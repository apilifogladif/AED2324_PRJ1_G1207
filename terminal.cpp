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
void submitRequest(int op) {
    string studentCode;
    cout << "Insert your student code (eg.: up20xxxxxxx): ";
    cin >> studentCode;
    cout << endl;
    AuxiliarFunctions func;
    Student *student = func.retStudent(studentCode);
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

// Menu for the user choose which type of request he wants (enroll in an UC, leave an UC, change an UC
void RequestMenu() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Request Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Enroll in an UC." << endl;
    cout << "2 - Leave an UC." << endl;
    cout << "3 - Switch an UC." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    while (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
    }
    submitRequest(op);
}

