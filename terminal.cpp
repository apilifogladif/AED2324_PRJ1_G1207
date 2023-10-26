#include <iostream>
#include "Lesson.h"
#include "Student.h"
#include "Request.h"
#include "UC.h"
#include "Schedule.h"
#include "AuxiliarFunctions.h"
#include <fstream>
#include <sstream>

using namespace std;

void searchClass() {
    string classCode;
    cout << "Write the code of the class: ";
    cin >> classCode;
    cout << endl;
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      ClassMenu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show schedule of this class." << endl;
    cout << "2 - Number os students in this class." << endl;
    cout << "3 - Return to MainMenu." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    if (cin.fail() || op < 1 || op > 2) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
}
void searchLesson() {
    string classCode;
    string UcCode;
    cout << "Write the code of the class: ";
    cin >> classCode;
    cout << endl;
    cout << "Write the code of the uc: ";
    cin >> UcCode;
    cout << endl;
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      LessonMenu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show schedule of this lesson." << endl;
    cout << "2 - Number os students in this lesson." << endl;
    cout << "3 - Return to MainMenu." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    if (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
}
void searchStudent() {
    string StudentCode;
    cout << "Write the code of the student: ";
    cin >> StudentCode;
    cout << endl;
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      StudentMenu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show schedule of this student." << endl;
    cout << "2 - Change a class in an uc." << endl;
    cout << "3 - Return to MainMenu." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    if (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
}
void searchUC() {
    string UcCode;
    cout << "Write the code of the uc: ";
    cin >> UcCode;
    cout << endl;
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      UcMenu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show schedule of this uc." << endl;
    cout << "2 - Number of students in this uc." << endl;
    cout << "3 - Return to MainMenu." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    if (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
}

int main() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      MainMenu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Search for a class." << endl;
    cout << "2 - Search for a lesson." << endl;
    cout << "3 - Search for a student." << endl;
    cout << "4 - Search for a UC." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    if (cin.fail() || op < 1 || op > 4) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    switch (op) {
        case 1:
            searchClass();
            break;
        case 2:
            searchLesson();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            searchUC();
            break;
    }
    return 0;
}

// this function stores information of 'classes.csv' file in a vector of objects of the class 'Lesson'
vector<Lesson> createLessonsVector() {
    fstream file;
    vector<Lesson> v;
    file.open("data/classes.csv");
    string line;
    int i = 0;
    getline(file, line);
    string classCode;
    int UcCode;
    string weekDay;
    double startHour;
    double duration;
    string type;
    while(getline(file, line)) {
        stringstream s(line);
        s >> classCode;
        s >> UcCode;
        s >> weekDay;
        s >> startHour;
        s >> duration;
        s >> type;
    }
    v.push_back(Lesson(classCode, UcCode, weekDay, startHour, duration, type));
    }
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
        s >> UcCode;
        s >> ClassCode;
        if (UcCode == lastUcCode) {
            classes.insert(ClassCode);
        }
        else {
            v.push_back(pair(lastUcCode, classes));
            classes.clear();
            classes.
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
    int StudentCode;
    int lastStudentCode;
    string StudentName;
    string lastStudentName;
    string UcCode;
    string ClassCode;
    getline(file, line);
    while (getline(file, line)) {
        stringstream s(line);
        s >> StudentCode;
        s >> StudentName;
        s >> UcCode;
        s >> ClassCode;
        if (StudentCode = lastStudentCode) {
            ucs.push_back(UC(UcCode, ClassCode));
        } else {
            v.push_back(Student(lastStudentCode, lastStudentName, ucs));
            ucs.clear();
            ucs.push_back(UC(UcCode, ClassCode));
        }
        lastStudentCode = StudentCode;
        lastStudentName = StudentName;
    }
    return v;
}

// Menu for the user choose which type of request he wants (enroll in an UC, leave an UC, change an U
int RequestMenu() {
    int op = 0;
    cout << endl << "There are three types of request" << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Enroll in an UC." << endl;
    cout << "2 - Leave an UC." << endl;
    cout << "3 - Switch an UC." << endl:
    cout << "Write the number of what you want to do: ";
    cin >> op;
    if (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
    }
    cout << endl;
    return op;
}

int submitRequest(int op) {
    string studentCode;
    cout << "Insert your student code (eg.: up20xxxxxxx): ";
    cin >> studentCode;
    cout << endl;
    AuxiliarFunctions func;
    Student *student = func.findStudent(studentCode);
    if (student == nullptr) {
        cout << "Invalid student code" << endl;
        cout << "Insert your student code (eg.: up20xxxxxxx): ";
        cin >> studentCode;
    }
    switch(op) {
        case 1:
            enrollRequest(student);
            break;
        case 2:
            leaveRequest(student);
            break;
        case 3:
            switchRequest(student);
            break;
    }
}

void enrollRequest(Student *student) {
    string UcCode;
    string classCode;
    cout << "Insert UC code: ";
    cin >> UcCode;
    cout << endl;
    if (student->Enrolled(UcCode)) {
        cout << "The student is already enrolled in this UC." << endl;
    }
    cout << "Insert class code: ";
    cin >> classCode;
    cout << endl;
    AuxiliarFunctions func2;
    Schedule *schedule = func2.UCSchedule(UC(UcCode, classCode));
    if (schedule == nullptr) {
        cout << "Class not found." << endl;
    }
    func2.concludeEnrollment(*student, UC(UcCode, classCode));
    cout << "Enrollment request submitted." << endl;
}

void leaveRequest(Student *student) {
    string UcCode;
    string classCode;
    cout << "Insert UC code: ";
    cin >> UcCode;
    cout << endl;
    if (!(student->Enrolled(UcCode))) {
        cout << "The student is not enrolled in this UC." << endl;
    }
    AuxiliarFunctions func3;
    for (UC uc: student->getUCs()) {
        if (uc.getUcCode() == UcCode) {
            func3.concludeRemoval(*student, uc);
            cout << "Enrollment request submitted." << endl;
        }
    }
}

void switchRequest(Student *student) {
    string UcCode;
    string classCode;
    cout << "Insert UC code: ";
    cin >> UcCode;
    cout << endl;
    if (!(student->Enrolled(UcCode))) {
        cout << "The student is not enrolled in this UC." << endl;
    }
    cout << "Insert class code: ";
    cin >> classCode;
    cout << endl;
    AuxiliarFunctions func4;
    Schedule *schedule = func4.UCSchedule(UC(UcCode, classCode));
    if (schedule == nullptr) {
        cout << "Class not found." << endl;
    }
    func4.concludeSwitch(*student, UC(UcCode, classCode));
    cout << "Switch request submitted." << endl;
}