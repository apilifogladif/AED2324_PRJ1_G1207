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

int studentMenu(const string& StudentCode) {
    AuxiliarFunctions func = AuxiliarFunctions();
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Student Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show the schedule of this student." << endl;
    cout << "2 - Make a request." << endl;
    cout << "3 - Return to Main Menu." << endl;
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
            func.seeStudentSchedule(StudentCode);
            break;
        case 2:
            RequestMenu();
            break;
        case 3:
            return 0;
        case 4:
            system("exit");
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
    else if (op == 1) studentMenu(StudentCode);
    return 0;
}

int lessonMenu(const string& classCode, const string& UcCode) {
    AuxiliarFunctions func = AuxiliarFunctions();
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Lesson Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show the schedule of this lesson." << endl;
    cout << "2 - Return to Main Menu." << endl;
    cout << "3 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 3) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    switch (op) {
        case 1:
            func.seeLessonSchedule(UC(UcCode, classCode));
            break;
        case 2:
            return 0;
        case 3:
            system("exit");
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
    else if (op == 1) lessonMenu(classCode, UcCode);
    return 0;
}

int ucMenu(const string& UcCode) {
    AuxiliarFunctions func = AuxiliarFunctions();
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Uc Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show the schedule of this uc." << endl;
    cout << "2 - Number of students in this uc." << endl;
    cout << "3 - Show sorted students." << endl;
    cout << "4 - Return to Main Menu." << endl;
    cout << "5 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 5) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }

    CsvAndVectors CSVInfo;
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();
    int count = 0;

    switch (op) {
        case 1:
            func.seeUcSchedule(UcCode);
            break;

        case 2:
            for (auto &student : StudentsVector) {
                if (student.findUc(UcCode).getClassCode() != "") {
                    count++;
                }
            }
            cout << "Number of students: " << count << endl;

        case 3:
            for (auto &student : StudentsVector) {
                if (student.findUc(UcCode).getClassCode() != "") {
                    cout << student.getStudentCode() << "," << student.getStudentName() << endl;
                }
            }

        case 4:
            return 0;
        case 5:
            system("exit");
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
    else if (op == 1) ucMenu(UcCode);
    return 0;
}

int classMenu(const string& classCode) {
    AuxiliarFunctions func = AuxiliarFunctions();
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Class Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Show the schedule of this class." << endl;
    cout << "2 - Number os students in this class." << endl;
    cout << "3 - Show sorted students." << endl;
    cout << "4 - Return to Main Menu." << endl;
    cout << "5 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 5) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    switch (op) {
        case 1:
            func.seeClassSchedule(classCode);
            cout << "1 - Return to Class Menu" << endl;
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
            else if (op == 1) classMenu(classCode);
            break;
        case 2:
        case 3:
            op = whichUc(op - 2, classCode);
            if (op == 1) classMenu(classCode);
            break;
        case 4:
            return 0;
        case 5:
            system("exit");
    }
    return 0;
}

int main() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Search for a class." << endl;
    cout << "2 - Search for a lesson." << endl;
    cout << "3 - Search for a student." << endl;
    cout << "4 - Search for a UC." << endl;
    cout << "5 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 5) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    //clrscr();  ->  clear screen
    string StudentCode;
    string classCode;
    string UcCode;

    switch (op) {
        case 1:
            cout << "Write the code of the class: ";
            cin >> classCode;
            cout << endl;
            classMenu(classCode);
            main();

        case 2:
            cout << "Write the code of the class: ";
            cin >> classCode;
            cout << endl;
            cout << "Write the code of the uc: ";
            cin >> UcCode;
            cout << endl;
            lessonMenu(classCode, UcCode);
            main();

        case 3:
            cout << "Write the code of the student: ";
            cin >> StudentCode;
            cout << endl;
            studentMenu(StudentCode);
            main();

        case 4:
            cout << "Write the code of the uc: ";
            cin >> UcCode;
            cout << endl;
            ucMenu(UcCode);
            main();

        case 5:
            system("exit");
    }
    return 0;
}

