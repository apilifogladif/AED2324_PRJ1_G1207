#include <iostream>
#include "CsvAndVectors.h"
#include "AuxiliarFunctions.h"

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
    for (const UC& uc: student->getUCs()) {
        if (uc.getUcCode() == UcCode) {
            func3.concludeRemoval(*student, uc);
            cout << "Removal request submitted." << endl;
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
    cout << "Insert your student code (eg.: 20xxxxxxx): ";
    cin >> studentCode;
    cout << endl;
    AuxiliarFunctions func;
    Student *student = func.retStudent(studentCode);
    while (student == nullptr) {
        cout << "Invalid student code" << endl;
        cout << "Insert your student code (eg.: 20xxxxxxx): ";
        cin >> studentCode;
        student = func.retStudent(studentCode);
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

int whichUc(int op1, const string& classCode) {
    int op2 = 0;
    cout << endl <<               "-----------------------------------------------------------" << endl;
    if (op1 == 0) cout << endl << "      Number of students of which UC from this class?      " << endl;
    else cout << endl <<          "       Print students from which Uc from this class?       " << endl;
    cout << endl << "-----------------------------------------------------------" << endl;

    CsvAndVectors CSVInfo = CsvAndVectors();
    vector<pair<string, set<string>>> ClassesPerUcVector = CSVInfo.getClassesPerUcVector();

    vector<string> UcOfClass;
    int op = 0;
    for(pair<string, set<string>> i : ClassesPerUcVector) {
        auto it = i.second.find(classCode);
        if (it != i.second.end()) {
            UcOfClass.push_back(i.first);
            cout << op << " - " << i.first << endl;
            op++;
        }
    }
    cout << "Write the number of the Uc: ";
    cin >> op2;
    cout << endl;
    while (cin.fail() || op2 < 1 || op2 > UcOfClass.size()) {
        cout << "Invalid number! Write the number of the Uc: " << endl;
        cin >> op2;
        cout << endl;
    }
    string ucCode = UcOfClass[op2 - 1];

    int count = 0;
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();
    for (auto &student: StudentsVector) {
        UC uc = student.findUc(ucCode);
        if (uc.getClassCode() == classCode) {
            if (op1 == 1) cout << student.getStudentCode() << "," << student.getStudentName() << endl;
            else count++;
        }
    }
    if (op == 0) cout << "Number of students:" << count << endl;
    cout << "1 - Choose other UC" << endl;
    cout << "2 - Return to Class Menu" << endl;
    cout << "3 - Return to Main Menu" << endl;
    cout << "4 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 4) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }

    switch (op) {
        case 1:
            whichUc(op1, classCode);
            break;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            system("exit");
    }
    return 2;
}

int listingMenu() {
    AuxiliarFunctions func = AuxiliarFunctions();
    int op = 0;
    cout << endl << "----------------------------------" << endl;
    cout << endl << "     Search for listings of...    " << endl;
    cout << endl << "----------------------------------" << endl;
    cout << "1 - Students of an Uc and a class." << endl;
    cout << "2 - Students of a year." << endl;
    cout << "3 - Students of a Uc." << endl;
    cout << "4 - Return to Main Menu." << endl;
    cout << "5 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 4) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    string UcCode;
    string sort_;
    string ClassCode;
    CsvAndVectors CSVInfo;
    int year = 0;
    switch (op) {
        case 1:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): " << endl;
            cin >> UcCode;
            cout << "Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
            cin >> ClassCode;
            cout << "How do you want the list to be sorted?" << endl;
            cout << "1 - A-Z order" << endl;
            cout << "2 - Z-A order" << endl;
            cout << "3 - numerical" << endl;
            cout << "4 - reverse numerical" << endl;
            cout << "Write the number of what you want to do: ";
            cin >> op;
            cout << endl;
            while (cin.fail() || op < 1 || op > 4) {
                cout << "Invalid number! Write the number of what you want to do: " << endl;
                cin >> op;
                cout << endl;
            }
            func.seeClassStudents(UC(UcCode, ClassCode), op);
            break;
        case 2:
            cout << "Write the year (1, 2 or 3): " << endl;
            cin >> year;
            cout << "How do you want the list to be sorted?" << endl;
            cout << "1 - A-Z order" << endl;
            cout << "2 - Z-A order" << endl;
            cout << "3 - numerical" << endl;
            cout << "4 - reverse numerical" << endl;
            cout << "Write the number of what you want to do: ";
            cin >> op;
            cout << endl;
            while (cin.fail() || op < 1 || op > 4) {
                cout << "Invalid number! Write the number of what you want to do: " << endl;
                cin >> op;
                cout << endl;
            }
            func.seeYearStudents(year, op);
            break;
        case 3:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): " << endl;
            cin >> UcCode;
            cout << "How do you want the list to be sorted?" << endl;
            cout << "1 - A-Z order" << endl;
            cout << "2 - Z-A order" << endl;
            cout << "3 - numerical" << endl;
            cout << "4 - reverse numerical" << endl;
            cout << "Write the number of what you want to do: ";
            cin >> op;
            cout << endl;
            while (cin.fail() || op < 1 || op > 4) {
                cout << "Invalid number! Write the number of what you want to do: " << endl;
                cin >> op;
                cout << endl;
            }
            func.seeUcStudents(UcCode, op);
            break;
        case 4:
            return 1;
        case 5:
            return 0;
    }

    cout << "1 - Return to Uc Menu" << endl;
    cout << "2 - Return to Main Menu" << endl;
    cout << "3 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    if (op == 3) system("exit");
    else if (op == 1) listingMenu();
    return 0;
}

int scheduleMenu() {
    AuxiliarFunctions func = AuxiliarFunctions();
    int op = 0;
    cout << endl << "-----------------------------------" << endl;
    cout << endl << "     Search for schedules of...    " << endl;
    cout << endl << "-----------------------------------" << endl;
    cout << "1 - an Uc." << endl;
    cout << "2 - a Class." << endl;
    cout << "3 - a Student." << endl;
    cout << "4 - Return to main menu." << endl;
    cout << "5 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    string UcCode;
    string ClassCode;
    string StudentCode;
    CsvAndVectors CSVInfo;
    CSVInfo.createClassesAndUcSet();
    set<string> ClassesSet;
    set<string> UcSet;
    set<string> StudentsSet;

    switch (op) {
        case 1:
            cout << "Write the code of the Uc (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            UcSet = CSVInfo.getUcSet();
            while (cin.fail() || UcSet.find(UcCode) == UcSet.end()) {
                cout << "Invalid number! Write the code of the Uc (L.EICxxx or UPxxx): " << endl;
                cin >> op;
                cout << endl;
            }
            func.seeUcSchedule(UcCode);
            break;
        case 2:
            cout << "Write the code of the Class (yLEICxx; y->year, xx->class): ";
            cin >> ClassCode;
            ClassesSet = CSVInfo.getClassesSet();
            while (cin.fail() || ClassesSet.find(ClassCode) == ClassesSet.end()) {
                cout << "Invalid number! Write the code of the Class (yLEICxx; y->year, xx->class): " << endl;
                cin >> op;
                cout << endl;
            }
            func.seeClassSchedule(ClassCode);
        case 3:
            cout << "Write the code of the Student (eg.: 20xxxxxxx): ";
            cin >> StudentCode;
            StudentsSet = CSVInfo.getStudentsSet();
            while (cin.fail() || StudentsSet.find(StudentCode) == StudentsSet.end()) {
                cout << "Invalid number! Write the code of the Student (eg.: 20xxxxxxx): " << endl;
                cin >> op;
                cout << endl;
            }
            func.seeStudentSchedule(StudentCode);
        case 4:
            return 1;
        case 5:
            return 0;
    }

    cout << "1 - Return to Lesson Menu" << endl;
    cout << "2 - Return to Main Menu" << endl;
    cout << "3 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }

    if (op == 3) system("exit");
    else if (op == 1) scheduleMenu();
    return 0;
}

// Menu for the user choose which type of request he wants (enroll in an UC, leave an UC, change an UC
int requestMenu() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Request Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Enroll in an UC." << endl;
    cout << "2 - Leave an UC." << endl;
    cout << "3 - Switch an UC." << endl;
    cout << "4 - Return to main menu." << endl;
    cout << "5 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    if (op == 4) return 1;
    if (op == 5) return 0;
    while (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
    }
    submitRequest(op);
}

//TODO
int pendingRequests() {}
int processedRequest() {}

int main() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Search for listings of..." << endl;
    cout << "2 - Search for schedules of..." << endl;
    cout << "3 - Submit a request for..." << endl;
    cout << "4 - See requests that are pending." << endl;
    cout << "5 - See requests that have already been processed." << endl;
    cout << "6 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 6) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    //clrscr();  ->  clear screen

    int aux = 0;

    switch (op) {
        case 1:
            aux = listingMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 2:
            aux = scheduleMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 3:
            aux = requestMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 4:
            aux = pendingRequests();
            if (aux == 1) main();
            else system("exit");
            break;

        case 5:
            aux = processedRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        case 6:
            system("exit");
    }
    return 0;
}

