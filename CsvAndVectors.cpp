#include "CsvAndVectors.h"

using namespace std;

vector<Lesson> CsvAndVectors::LessonsVector;
vector<Student> CsvAndVectors::StudentsVector;
vector<pair<string, set<string>>> CsvAndVectors::ClassesPerUcVector;
set<string> CsvAndVectors::ClassesSet;
set<string> CsvAndVectors::UcSet;
set<string> CsvAndVectors::StudentsSet;

CsvAndVectors::CsvAndVectors() {}


void CsvAndVectors::createClassesAndUcSet() {
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
        ClassesSet.insert(ClassCode);
        UcSet.insert(UcCode);
    }
}

void CsvAndVectors::createStudentsSet() {
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
        StudentsSet.insert(StudentCode);
    }
}

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

vector<pair<string, set<string>>> CsvAndVectors::getClassesPerUcVector() {
    createClassesPerUcVector();
    return ClassesPerUcVector;
}

vector<Student> CsvAndVectors::getStudentsVector() {
    createStudentsVector();
    return StudentsVector;
}

void CsvAndVectors::setFromLessonsVector() {
    std::string fileName = "data/classes.csv";
    std::ofstream out(fileName);

    //clear content from csv file
    out.open("data/classes.csv", std::ofstream::out | std::ofstream::trunc);
    out.close();

    out << "ClassCode,UcCode,Weekday,StartHour,Duration,Type" << "\n";
    for (const auto & lesson : LessonsVector) {
        out << lesson.getUc().getClassCode() << "," << lesson.getUc().getUcCode() << "," <<
               lesson.getWeekday() << "," << lesson.getStartHour() << "," <<
               lesson.getDuration() << "," << lesson.getType() << "\n";
    }
}

void CsvAndVectors::setFromClassesPerUcVector() {
    std::string fileName = "data/classes_per_uc.csv";
    std::ofstream out(fileName);

    //clear content from csv file
    out.open("data/classes_per_uc.csv", std::ofstream::out | std::ofstream::trunc);
    out.close();

    out << "UcCode,ClassCode" << "\n";
    for (auto &Uc : ClassesPerUcVector) {
        for (string Class: Uc.second) {
            out << Uc.first << "," << Class << "\n";
        }
    }
}

void CsvAndVectors::setFromStudentsVector() {
    std::string fileName = "data/students_classes.csv";
    std::ofstream out(fileName);

    //clear content from csv file
    out.open("data/students_classes.csv", std::ofstream::out | std::ofstream::trunc);
    out.close();

    out << "StudentCode,StudentName,UcCode,ClassCode" << "\n";
    for (auto &student : StudentsVector) {
        for(auto &ucClass: student.getUCs()) {
            out << student.getStudentCode() << "," << student.getStudentName() << "," << ucClass.getUcCode() <<
                "," << ucClass.getClassCode() << "\n";
        }
    }
}