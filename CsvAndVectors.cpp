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

void CsvAndVectors::createClassesAndUcSet() {
    ClassesSet.clear();
    UcSet.clear();
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
    StudentsSet.clear();
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
    LessonsVector.clear();
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
    RequestsVector.clear();
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
        getline(s, studentName, ':');
        getline(s, type, ',');
        getline(s, status, ',');
        getline(s, reason);
        Request request(Student(studentCode, studentName), UC(), type);
        request.setStatus(status);
        request.setReason(reason);
        RequestsVector.push_back(request);
    }
}

// this function stores information of 'classes_per_uc.csv' file in a vector of pairs that associates an uc to a set of the classes that have that uc
void CsvAndVectors::createClassesPerUcVector() {
    ClassesPerUcVector.clear();
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
    ClassesPerUcVector.emplace_back(lastUcCode, classes);
    classes.clear();
    classes.insert(ClassCode);
}

// this function stores information of 'students_classes.csv' file in a vector of objects of the class 'Student'
void CsvAndVectors::createStudentsVector() {
    StudentsVector.clear();
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
    getline(file, line);
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream s(line);
        getline(s, StudentCode, ',');
        getline(s, StudentName, ',');
        getline(s, UcCode, ',');
        getline(s, ClassCode);
        if (!StudentsVector.empty() && StudentCode == StudentsVector[StudentsVector.size() - 1].getStudentCode()) {
            StudentsVector[StudentsVector.size() - 1].addUC(UC(UcCode, ClassCode));
        }
        else {
            vector<UC> ucs;
            ucs.emplace_back(UcCode, ClassCode);
            StudentsVector.emplace_back(StudentCode, StudentName, ucs);
        }
    }
}

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

void CsvAndVectors::setFromRequestVector() {
    ofstream fileName;
    fileName.open("../data/requests.csv");
    fileName << "StudentCode, StudentName: RequestType -> Status, Reason (if rejected)" << endl;
    for (auto &request : RequestsVector) {
        fileName << request.getStudent().getStudentCode() << "," << request.getStudent().getStudentName() << ":" <<
            request.getType() << "," << request.getStatus();
        if (request.getStatus() == "Rejected") {
            fileName << "," << request.getReason();
        }
        fileName << endl;
    }
    fileName.close();
}