#include "CsvAndVectors.h"
using namespace std;

// O(1)
CsvAndVectors::CsvAndVectors() = default;

vector<Lesson> CsvAndVectors::LessonsVector;
vector<pair<string, set<string>>> CsvAndVectors::ClassesPerUcVector;
vector<Student> CsvAndVectors::StudentsVector;
vector<Request> CsvAndVectors::RequestsVector;
set<string> CsvAndVectors::StudentsSet;
set<string> CsvAndVectors::ClassesSet;
set<string> CsvAndVectors::UcSet;

// O(n) where n is the number of lines in the 'classes_per_uc.csv'
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

// O(n) where n is the number of lines in the 'students_classes.csv'
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

// O(n) where n is the number of lines in the 'classes.csv'
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

// O(n) where n is the number of lines in the 'requests.csv'
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

// O(n) where n is the number of lines in the 'classes_per_uc.csv'
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

// O(n) where n is the number of lines in the 'students_classes.csv'
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

// O(n) where n is the number of lines in the 'students_classes.csv'
set<string> CsvAndVectors::getStudentsSet() {
    createStudentsSet();
    return StudentsSet;
}

// O(n) where n is the number of lines in the 'classes_per_uc.csv'
set<string> CsvAndVectors::getClassesSet() {
    createClassesAndUcSet();
    return ClassesSet;
}

// O(n) where n is the number of lines in the 'classes_per_uc.csv'
set<string> CsvAndVectors::getUcSet() {
    createClassesAndUcSet();
    return UcSet;
}

// O(n) where n is the number of lines in the 'classes.csv'
vector<Lesson> CsvAndVectors::getLessonsVector() {
    createLessonsVector();
    return LessonsVector;
}

// O(n) where n is the number of lines in the 'requests.csv'
vector<Request> CsvAndVectors::getRequestVector() {
    createRequestsVector();
    return RequestsVector;
}

// O(n) where n is the number of lines in the 'classes_per_uc.csv'
vector<pair<string, set<string>>> CsvAndVectors::getClassesPerUcVector() {
    createClassesPerUcVector();
    return ClassesPerUcVector;
}

// O(n) where n is the number of lines in the 'students_classes.csv'
vector<Student> CsvAndVectors::getStudentsVector() {
    createStudentsVector();
    return StudentsVector;
}

// O(n) where n is the number of lessons in the 'LessonsVector'
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

// O(m*k) where m is the number of unique UcCode entries and k is the average number of ClassCode entries for each UcCode
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

// O(n*k) where n is the number of Student objects in StudentsVector and k is the average number of UC objects associated with each Student
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

// O(n) where n is the number of Request objects in RequestVectors
void CsvAndVectors::setFromRequestVector() {
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