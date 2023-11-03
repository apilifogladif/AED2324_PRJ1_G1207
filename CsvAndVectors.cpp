#include "CsvAndVectors.h"

using namespace std;

CsvAndVectors::CsvAndVectors() = default;

vector<Lesson> CsvAndVectors::LessonsVector;
vector<pair<string, set<string>>> CsvAndVectors::ClassesPerUcVector;
vector<Student> CsvAndVectors::StudentsVector;
vector<Request> CsvAndVectors::RequestsVector;
set<string> CsvAndVectors::StudentsSet;
set<string> CsvAndVectors::ClassesSet;
set<string> CsvAndVectors::UcSet;



void CsvAndVectors::createClassesAndUcSet() {
    fstream file;
    set<string> classes;
    file.open("../data/classes_per_uc.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }
    string line;
    string lastUcCode;
    string UcCode;
    string ClassCode;
    getline(file, line);    // discard header line
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, UcCode, ',');
        getline(s, ClassCode);
        ClassesSet.insert(ClassCode);
        UcSet.insert(UcCode);
    }
    file.close();
}

void CsvAndVectors::createStudentsSet() {
    fstream file;
    set<string> classes;
    vector<UC> ucs;
    file.open("../data/students_classes.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }
    string line;
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
    string lastStudentName;
    string lastStudentCode;
    getline(file, line);
    while (getline(file, line)) {
        stringstream s(line);
        getline(s, StudentCode, ',');
        getline(s, StudentName, ',');
        getline(s, UcCode, ',');
        getline(s, ClassCode);
        StudentsSet.insert(StudentCode);
    }
}

// this function stores information of 'classes.csv' file in a vector of objects of the class 'Lesson'
void CsvAndVectors::createLessonsVector() {
    fstream file;
    file.open("../data/classes.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }
    string line;
    getline(file, line);
    string classCode;
    string UcCode;
    string weekDay;
    string startHour;
    string duration;
    string type;
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, classCode, ',');
        getline(s, UcCode, ',');
        getline(s, weekDay, ',');
        getline(s, startHour, ',');
        getline(s, duration, ',');
        getline(s, type);
        LessonsVector.emplace_back(UcCode, classCode, weekDay, stof(startHour), stof(duration), type);
    }
}

void CsvAndVectors::createRequestsVector() {
    fstream file;
    file.open("../data/requests.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }
    string line;
    getline(file, line);
    string studentCode;
    string studentName;
    string description;
    string type;
    string status;
    string reason;
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, studentCode, ',');
        getline(s, studentName, ',');
        getline(s, type, ',');
        getline(s, description, ',');
        getline(s, status, ',');
        getline(s, reason);
        Request request(Student(studentCode, studentName), UC(), type);
        request.setStatus(status);
        request.setReason(reason);
        request.setDescription(description);
        RequestsVector.push_back(request);
    }
}

// this function stores information of 'classes_per_uc.csv' file in a vector of pairs that associates an uc to a set of the classes that have that uc
void CsvAndVectors::createClassesPerUcVector() {
    fstream file;
    set<string> classes;
    file.open("../data/classes_per_uc.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }
    string line;
    string lastUcCode;
    string UcCode;
    string ClassCode;
    getline(file, line);
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, UcCode, ',');
        getline(s, ClassCode);
        if (UcCode == lastUcCode) {
            classes.insert(ClassCode);
        } else {
            ClassesPerUcVector.emplace_back(lastUcCode, classes);
            classes.clear();
            classes.insert(ClassCode);
        }
        lastUcCode = UcCode;
    }
}

// this function stores information of 'students_classes.csv' file in a vector of objects of the class 'Student'
void CsvAndVectors::createStudentsVector() {
    fstream file;
    set<string> classes;
    vector<UC> ucs;
    file.open("../data/students_classes.csv");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }
    string line;
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
    string lastStudentName;
    string lastStudentCode;
    getline(file, line);
    while (getline(file, line)) {
        stringstream s(line);
        getline(s, StudentCode, ',');
        getline(s, StudentName, ',');
        getline(s, UcCode, ',');
        getline(s, ClassCode);
        if (StudentCode == lastStudentCode) {
            ucs.emplace_back(UcCode, ClassCode);
        } else {
            StudentsVector.emplace_back(lastStudentCode, lastStudentName, ucs);
            ucs.clear();
            ucs.emplace_back(UcCode, ClassCode);
        }
        lastStudentCode = StudentCode;
        lastStudentName = StudentName;
    }
}

set<string> CsvAndVectors::getStudentsSet() {
    createStudentsSet();
    return StudentsSet;
}

set<string> CsvAndVectors::getClassesSet() {
    createClassesAndUcSet();
    return ClassesSet;
}

set<string> CsvAndVectors::getUcSet() {
    createClassesAndUcSet();
    return UcSet;
}

vector<Lesson> CsvAndVectors::getLessonsVector() {
    createLessonsVector();
    return LessonsVector;
}

vector<Request> CsvAndVectors::getRequestVector() {
    createRequestsVector();
    return RequestsVector;
}

vector<pair<string, set<string>>> CsvAndVectors::getClassesPerUcVector() {
    createClassesPerUcVector();
    return ClassesPerUcVector;
}

vector<Student> CsvAndVectors::getStudentsVector() {
    createStudentsVector();
    return StudentsVector;
}


void CsvAndVectors::setFromLessonsVector() {
    ofstream fileName;
    fileName.open("../data/classes.csv");
    fileName << "ClassCode,UcCode,Weekday,StartHour,Duration,Type" << endl;
    for (const auto & lesson : LessonsVector) {
        fileName << lesson.getUc().getClassCode() << "," << lesson.getUc().getUcCode() << "," <<
               lesson.getWeekday() << "," << lesson.getStartHour() << "," <<
               lesson.getDuration() << "," << lesson.getType() << "\n";
    }
    fileName.close();
}
//    std::string fileName = "../data/classes.csv";
//    std::ofstream out(fileName);

    //clear content from csv file
//    out.open("../data/classes.csv", std::ofstream::out | std::ofstream::trunc);
//    out.close();

//    out << "ClassCode,UcCode,Weekday,StartHour,Duration,Type" << "\n";
//    for (const auto & lesson : LessonsVector) {
//        out << lesson.getUc().getClassCode() << "," << lesson.getUc().getUcCode() << "," <<
//               lesson.getWeekday() << "," << lesson.getStartHour() << "," <<
//               lesson.getDuration() << "," << lesson.getType() << "\n";
//    }
//}

void CsvAndVectors::setFromClassesPerUcVector() {
    ofstream fileName;
    fileName.open("../data/classes_per_uc.csv");
    fileName << "UcCode,ClassCode" << endl;
    for (auto &Uc : ClassesPerUcVector) {
        for (const string& Class: Uc.second) {
            fileName << Uc.first << "," << Class << "\n";
        }
    }
    fileName.close();
}
//    std::string fileName = "../data/classes_per_uc.csv";
//    std::ofstream out(fileName);

    //clear content from csv file
//    out.open("../data/classes_per_uc.csv", std::ofstream::out | std::ofstream::trunc);
//    out.close();

//    out << "UcCode,ClassCode" << "\n";
//    for (auto &Uc : ClassesPerUcVector) {
//        for (const string& Class: Uc.second) {
//            out << Uc.first << "," << Class << "\n";
//        }
//    }
//}

void CsvAndVectors::setFromStudentsVector() {
    ofstream fileName;
    fileName.open("../data/students_classes.csv");
    fileName << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    for (const Student &s: StudentsVector) {
        for (const UC &c: s.getUCs()) {
            fileName << s.getStudentCode() << "," << s.getStudentName() << "," << c.getUcCode() << "," << c.getClassCode() << endl;
        }
    }
    fileName.close();
}
//    std::string fileName = "../data/students_classes.csv";
//    std::ofstream out(fileName);

    //clear content from csv file
//    out.open("../data/students_classes.csv", std::ofstream::out | std::ofstream::trunc);
//    out.close();

//    out << "StudentCode,StudentName,UcCode,ClassCode" << "\n";
//    for (auto &student : StudentsVector) {
//        for(auto &ucClass: student.getUCs()) {
//            out << student.getStudentCode() << "," << student.getStudentName() << "," << ucClass.getUcCode() <<
//                "," << ucClass.getClassCode() << "\n";
//        }
//    }
//}

void CsvAndVectors::setRequestVector() {
    ofstream fileName;
    fileName.open("../data/requests.csv");
    fileName << "StudentCode, StudentName, Type, Description -> Status, Reason (if rejected)" << endl;
    for (auto &request : RequestsVector) {
        fileName << request.getStudent().getStudentCode() << ", " << request.getStudent().getStudentName() << ", " <<
            request.getType() << ", " << request.getDescription() << " -> " << request.getStatus();
        if (request.getStatus() == "Rejected") {
            fileName << ", " << request.getReason();
        }
        fileName << endl;
    }
    fileName.close();
}
//    std::string fileName = "../data/requests.csv";
//    std::ofstream out(fileName);

    //clear content from csv file
//    out.open("../data/requests.csv", std::ofstream::out | std::ofstream::trunc);
//    out.close();

//    out << "StudentCode, StudentName, Type, Description -> Status, Reason (if rejected)" << "\n";
//    for (auto &request : RequestsVector) {
//        out << request.getStudent().getStudentCode() << ", " << request.getStudent().getStudentName() << ", " <<
//            request.getType() << ", " << request.getDescription() << " -> " << request.getStatus();
//        if (request.getStatus() == "Rejected") {
//            out << ", " << request.getReason();
//        }
//        out << endl;
//    }
//}

