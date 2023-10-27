#include <iostream>
#include "Lesson.h"
#include <fstream>
#include <sstream>
#include "Student.h"
#include "UC.h"

using namespace std;

// this function stores information of 'classes.csv' file in a vector of objects of the class 'Lesson'
vector<Lesson> createLessonsVector() {
    fstream file;
    vector<Lesson> v;
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
    v.emplace_back(UcCode, classCode, weekDay, stod(startHour), stod(duration), type);
    return v;
}

// this function stores information of 'classes_per_uc.csv' file in a vector of pairs that associates an uc to a set of the classes that have that uc
vector<pair<string, set<string>>> createClassesPerUcVector() {
    fstream file;
    vector<pair<string, set<string>>> v;
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
            v.emplace_back(lastUcCode, classes);
            classes.clear();
            classes.insert(ClassCode);
        }
        lastUcCode = UcCode;
    }
    return v;
}

// this function stores information of 'students_classes.csv' file in a vector of objects of the class 'Student'
vector<Student> createStudentsVector() {
    fstream file;
    vector<Student> v;
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
            v.emplace_back(lastStudentCode, lastStudentName, ucs);
            ucs.clear();
            ucs.emplace_back(UcCode, ClassCode);
        }
        lastStudentCode = StudentCode;
        lastStudentName = StudentName;
    }
    return v;
}

//void submitLessonsVector(vector<Lesson> LessonsVector) {}
//void submitClassesPerUcVector(vector<pair<string, set<string>>> ClassesPerUcVector) {}
//void submitStudentsVector(vector<Student> StudentsVector) {}