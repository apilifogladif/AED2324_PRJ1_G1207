#include "CsvAndVectors.h"

using namespace std;

CsvAndVectors::CsvAndVectors() {}

// this function stores information of 'classes.csv' file in a vector of objects of the class 'Lesson'
void CsvAndVectors::createLessonsVector() {
    fstream file;
    file.open("data/classes.csv");
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
        getline(s, type, '\0');
    }
    LessonsVector.emplace_back(UcCode, classCode, weekDay, stod(startHour), stod(duration), type);
}

// this function stores information of 'classes_per_uc.csv' file in a vector of pairs that associates an uc to a set of the classes that have that uc
void CsvAndVectors::createClassesPerUcVector() {
    fstream file;
    set<string> classes;
    file.open("data/classes_per_uc.csv");
    string line;
    string lastUcCode;
    string UcCode;
    string ClassCode;
    getline(file, line);
    while(getline(file, line)) {
        stringstream s(line);
        getline(s, UcCode, ',');
        getline(s, ClassCode, '\0');
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
    file.open("data/students_classes.csv");
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
        getline(s, ClassCode, '\0');
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

vector<Lesson> CsvAndVectors::getLessonsVector() {
    createLessonsVector();
    return LessonsVector;
}
vector<pair<string, set<string>>> CsvAndVectors::getClassesPerUcVector() {
    createClassesPerUcVector();
    return ClassesPerUcVector;
}
vector<Student> CsvAndVectors::getStudentsVector() {
    createStudentsVector();
    return StudentsVector;
}

//TODO: eu trato disto hoje à noite (filipafidalgo - 30/10)
//void CsvAndVectors::setFromLessonsVector() {
//    std::string fileName = "classes.csv";
//
//
//}
//void CsvAndVectors::setFromClassesPerUcVector() {}
//void CsvAndVectors::setFromStudentsVector() {}