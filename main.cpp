#include <iostream>
#include "CsvAndVectors.h"
#include "AuxiliarFunctions.h"
#include <algorithm>

using namespace std;

// 0->quit; 1->main menu

bool verifyClass(string ClassCode) {
    CsvAndVectors CSVInfo;
    set<string> ClassesSet = CSVInfo.getClassesSet();
    if (ClassesSet.find(ClassCode) == ClassesSet.end()) return true;
    return false;
}

bool verifyUc(string UcCode) {
    CsvAndVectors CSVInfo;
    set<string> UcSet = CSVInfo.getUcSet();
    if (UcSet.find(UcCode) == UcSet.end()) return true;
    return false;
}

bool verifyStudent(string StudentCode) {
    CsvAndVectors CSVInfo;
    set<string> StudentsSet = CSVInfo.getStudentsSet();
    if (StudentsSet.find(StudentCode) == StudentsSet.end()) return true;
    return false;
}

int enrollRequest(Student student) {
    string UcCode;
    string classCode;
    cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
    cin >> UcCode;
    cout << endl;
    while (cin.fail() || verifyUc(UcCode)) {
        cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
        cin >> UcCode;
        cout << endl;
    }
    if (student.Enrolled(UcCode)) {
        cout << "The student is already enrolled in this UC." << endl;
    }
    cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
    cin >> classCode;
    cout << endl;
    while (cin.fail() || verifyClass(classCode)) {
        cout << "Invalid Class Code! Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
        cin >> classCode;
        cout << endl;
    }
    AuxiliarFunctions func2;
    func2.concludeEnrollment(student, UC(UcCode, classCode));
    cout << "Enrollment request submitted." << endl;

    int op = 0;
    cout << "1 - Return to Main Menu." << endl;
    cout << "2 - Quit" << endl;
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 2) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    if (op == 1) return 1;
    return 0;
}

int leaveRequest(Student student) {
    string UcCode;
    string classCode;
    cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
    cin >> UcCode;
    cout << endl;
    while (cin.fail() || verifyUc(UcCode)) {
        cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
        cin >> UcCode;
        cout << endl;
    }
    if (!(student.Enrolled(UcCode))) {
        cout << "The student is not enrolled in this UC." << endl;
    }
    AuxiliarFunctions func3;
    for (const UC& uc: student.getUCs()) {
        if (uc.getUcCode() == UcCode) {
            func3.concludeRemoval(student, uc);
            cout << "Removal request submitted." << endl;
        }
    }

    int op = 0;
    cout << "1 - Return to Main Menu." << endl;
    cout << "2 - Quit" << endl;
    cin >> op;
    while (cin.fail() || op < 1 || op > 2) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
    }
    if (op == 1) return 1;
    return 0;
}

int switchRequest(Student student) {
    string UcCode;
    string classCode;
    cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
    cin >> UcCode;
    cout << endl;
    while (cin.fail() || verifyUc(UcCode)) {
        cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
        cin >> UcCode;
        cout << endl;
    }
    if (!(student.Enrolled(UcCode))) {
        cout << "The student is not enrolled in this UC." << endl;
    }
    cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
    cin >> classCode;
    cout << endl;
    while (cin.fail() || verifyClass(classCode)) {
        cout << "Invalid Class Code! Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
        cin >> classCode;
        cout << endl;
    }
    AuxiliarFunctions func4;
    Schedule schedule = Schedule(UC(UcCode, classCode));
    func4.concludeSwitch(student, UC(UcCode, classCode));
    cout << "Switch request submitted." << endl;

    int op = 0;
    cout << "1 - Return to Main Menu." << endl;
    cout << "2 - Quit" << endl;
    cin >> op;
    while (cin.fail() || op < 1 || op > 2) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
    }
    if (op == 1) return 1;
    return 0;
}

int submitRequest(int op) {
    string studentCode;
    cout << "Write the Student Code (eg.: 20xxxxxxx): ";
    cin >> studentCode;
    cout << endl;
    while (cin.fail() || verifyStudent(studentCode)) {
        cout << "Invalid Student Code! Write the Student Code (eg.: 20xxxxxxx): " << endl;
        cin >> studentCode;
        cout << endl;
    }

    AuxiliarFunctions func;
    Student student = func.retStudent(studentCode);

    int aux = 0;
    switch(op) {
        case 1:
            aux = enrollRequest(student);
            if (aux == 1) return 1;
            return 0;
        case 2:
            aux = leaveRequest(student);
            if (aux == 1) return 1;
            return 0;
        case 3:
            aux = switchRequest(student);
            if (aux == 1) return 1;
            return 0;
    }
    return 0;
}

int listingMenu() {
    AuxiliarFunctions func;
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
    while (cin.fail() || op < 1 || op > 5) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    string UcCode;
    string sort_;
    string classCode;
    CsvAndVectors CSVInfo;
    int year = 0;
    switch (op) {
        case 1:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            cout << endl;
            while (cin.fail() || verifyUc(UcCode)) {
                cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
                cin >> UcCode;
                cout << endl;
            }

            cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
            cin >> classCode;
            cout << endl;
            while (cin.fail() || verifyClass(classCode)) {
                cout << "Invalid Class Code! Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
                cin >> classCode;
                cout << endl;
            }

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
            func.seeClassStudents(UC(UcCode, classCode), op);
            break;
        case 2:
            cout << "Write the year (1, 2 or 3): " << endl;
            cin >> year;
            while (cin.fail() || year < 1 || year > 3) {
                cout << "Invalid year! Write the year (1, 2, 3): " << endl;
                cin >> year;
                cout << endl;
            }
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
            cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            cout << endl;
            while (cin.fail() || verifyUc(UcCode)) {
                cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
                cin >> UcCode;
                cout << endl;
            }
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

    cout << "1 - Return to last Menu" << endl;
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
    if (op == 3) return 0;
    else if (op == 1) listingMenu();
    return 1;
}

int numbersMenu() {
    AuxiliarFunctions func;
    CsvAndVectors CSVInfo;
    int op = 0;
    cout << endl << "------------------------------------------------" << endl;
    cout << endl << "     Search for the number of students... " << endl;
    cout << endl << "------------------------------------------------" << endl;
    cout << "1 - within an Uc." << endl;
    cout << "2 - within an Uc and a Class." << endl;
    cout << "3 - within a Year." << endl;
    cout << "4 - enrolled in a certain number of Ucs." << endl;
    cout << "5 - Return to Main Menu." << endl;
    cout << "6 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 5) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }

    string UcCode;
    string classCode;
    int year;
    int count = 0;
    int num;
    vector<Student> StudentsVector;
    switch(op) {
        case 1:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            cout << endl;
            while (cin.fail() || verifyUc(UcCode)) {
                cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
                cin >> UcCode;
                cout << endl;
            }
            cout << func.numberUcStudents(UcCode) << " students." << endl;
            break;

        case 2:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            cout << endl;
            while (cin.fail() || verifyUc(UcCode)) {
                cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
                cin >> UcCode;
                cout << endl;
            }

            cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
            cin >> classCode;
            cout << endl;
            while (cin.fail() || verifyClass(classCode)) {
                cout << "Invalid Class Code! Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
                cin >> classCode;
                cout << endl;
            }

            cout << func.numberClassStudents(UC(UcCode, classCode)) << " students." << endl;
            break;

        case 3:
            cout << "Write the year (1, 2 or 3): " << endl;
            cin >> year;
            while (cin.fail() || year < 1 || year > 3) {
                cout << "Invalid year! Write the year (1, 2, 3): " << endl;
                cin >> year;
                cout << endl;
            }
            cout << func.numberYearStudents(year) << " students." << endl;
            break;

        case 4:
            StudentsVector = CSVInfo.getStudentsVector();
            cout << "How many Ucs? ";
            cin >> num;
            for (const Student& student : StudentsVector) {
                if (student.getUCs().size() == num) count++;
            }
            cout << count << " students." << endl;
            break;

        case 5:
            return 1;

        case 6:
            return 0;
    }
    cout << "1 - Return to last Menu" << endl;
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
    if (op == 3) return 0;
    else if (op == 1) numbersMenu();
    return 1;
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
    string classCode;
    string studentCode;
    CsvAndVectors CSVInfo;

    switch (op) {
        case 1:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            cout << endl;
            while (cin.fail() || verifyUc(UcCode)) {
                cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
                cin >> UcCode;
                cout << endl;
            }
            func.seeUcSchedule(UcCode);
            break;

        case 2:
            cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
            cin >> classCode;
            cout << endl;
            while (cin.fail() || verifyClass(classCode)) {
                cout << "Invalid Class Code! Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
                cin >> classCode;
                cout << endl;
            }
            func.seeClassSchedule(classCode);
            break;

        case 3:
            cout << "Write the Student Code (eg.: 20xxxxxxx): ";
            cin >> studentCode;
            cout << endl;
            while (cin.fail() || verifyStudent(studentCode)) {
                cout << "Invalid Student Code! Write the Student Code (eg.: 20xxxxxxx): " << endl;
                cin >> studentCode;
                cout << endl;
            }
            func.seeStudentSchedule(studentCode);
            break;

        case 4:
            return 1;
        case 5:
            return 0;
    }

    cout << "1 - Return to last Menu" << endl;
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

    if (op == 3) return 0;
    else if (op == 1) scheduleMenu();
    return 1;
}

int occupationMenu() {
    AuxiliarFunctions func;
    CsvAndVectors CSVInfo;
    int op = 0;
    cout << endl << "------------------------------------------------" << endl;
    cout << endl << "     Search for the occupation of...  " << endl;
    cout << endl << "------------------------------------------------" << endl;
    cout << "1 - an Uc." << endl;
    cout << "2 - a Class." << endl;
    cout << "3 - a Year." << endl;
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

    string UcCode;
    string classCode;
    vector<pair<UC, int>> ClassesPerUcVectorOfYear;
    vector<pair<string, set<string>>> ClassesPerUcVector;
    vector<pair<string, int>> auxVector;
    pair<string, int> auxPair;
    pair<UC, int> auxPair2;
    int year;
    switch(op) {
        case 1:
            cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
            cin >> UcCode;
            cout << endl;
            while (cin.fail() || verifyUc(UcCode)) {
                cout << "Invalid Uc Code! Write the Uc Code (L.EICxxx or UPxxx): " << endl;
                cin >> UcCode;
                cout << endl;
            }
            ClassesPerUcVector = CSVInfo.getClassesPerUcVector();

            for (pair<string, set<string>> p : ClassesPerUcVector) {
                if (p.first == UcCode) {
                    for (string Class : p.second) {
                        auxPair.first = Class;
                        auxPair.second = func.numberClassStudents(UC(UcCode, Class));
                        auxVector.push_back(auxPair);
                    }
                }
            }
            cout << "How do you want the list to be sorted?" << endl;
            cout << "1 - A-Z order" << endl;
            cout << "2 - Z-A order" << endl;
            cout << "3 - From the one with more students to the less students." << endl;
            cout << "4 - From the one with less students to the more students." << endl;
            cout << "Write the number of what you want to do: ";
            cin >> op;
            cout << endl;
            while (cin.fail() || op < 1 || op > 4) {
                cout << "Invalid number! Write the number of what you want to do: " << endl;
                cin >> op;
                cout << endl;
            }
            if (op == 1) {
                sort(auxVector.begin(), auxVector.end(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.first < B.first;
                });
            }
            else if (op == 2) {
                sort(auxVector.rbegin(), auxVector.rend(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.first < B.first;
                });
            }
            else if (op == 3) {
                sort(auxVector.begin(), auxVector.end(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.second < B.second;
                });
            }
            else if (op == 4) {
                sort(auxVector.begin(), auxVector.end(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.second > B.second;
                });
            }
            cout << "ClassCode: Number of students" << endl;
            for (pair<string, int> &aux: auxVector) {
                cout << aux.first << ": " << aux.second << endl;
            }
            break;

        case 2:
            cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
            cin >> classCode;
            cout << endl;
            while (cin.fail() || verifyClass(classCode)) {
                cout << "Invalid Class Code! Write the Class Code (yLEICxx; y->year, xx->class): " << endl;
                cin >> classCode;
                cout << endl;
            }
            ClassesPerUcVector = CSVInfo.getClassesPerUcVector();

            for (pair<string, set<string>> p : ClassesPerUcVector) {
                if (p.second.find(classCode) != p.second.end()) {
                    auxPair.first = p.first;
                    auxPair.second = func.numberClassStudents(UC(UcCode, classCode));
                    auxVector.push_back(auxPair);
                }
            }

            cout << "How do you want the list to be sorted?" << endl;
            cout << "1 - A-Z order" << endl;
            cout << "2 - Z-A order" << endl;
            cout << "3 - From the one with more students to the less students." << endl;
            cout << "4 - From the one with less students to the more students." << endl;
            cout << "Write the number of what you want to do: ";
            cin >> op;
            cout << endl;
            while (cin.fail() || op < 1 || op > 4) {
                cout << "Invalid number! Write the number of what you want to do: " << endl;
                cin >> op;
                cout << endl;
            }
            if (op == 1) {
                sort(auxVector.begin(), auxVector.end(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.first < B.first;
                });
            }
            else if (op == 2) {
                sort(auxVector.rbegin(), auxVector.rend(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.first < B.first;
                });
            }
            else if (op == 3) {
                sort(auxVector.begin(), auxVector.end(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.second < B.second;
                });
            }
            else if (op == 4) {
                sort(auxVector.begin(), auxVector.end(), [](pair<string, int> &A, pair<string, int> &B) {
                    return A.second > B.second;
                });
            }
            cout << "UcCode: Number of students" << endl;
            for (pair<string, int> &aux: auxVector) {
                cout << aux.first << ": " << aux.second << endl;
            }
            break;

        case 3:
            cout << "Write the year (1, 2 or 3): " << endl;
            cin >> year;
            while (cin.fail() || year < 1 || year > 3) {
                cout << "Invalid year! Write the year (1, 2, 3): " << endl;
                cin >> year;
                cout << endl;
            }
            ClassesPerUcVector = CSVInfo.getClassesPerUcVector();
            for (pair<string, set<string>> &p : ClassesPerUcVector) {
                for (auto Class : p.second) {
                    if(static_cast<int>(Class[0]) - 48 == year) {
                        auxPair2.first = UC(p.first, Class);
                        auxPair2.second = func.numberClassStudents(auxPair2.first);
                        ClassesPerUcVectorOfYear.push_back(auxPair2);
                    }
                }
            }

            cout << "How do you want the list to be sorted?" << endl;
            cout << "1 - A-Z order of Ucs" << endl;
            cout << "2 - Z-A order of Ucs" << endl;
            cout << "3 - A-Z order of Classes" << endl;
            cout << "4 - Z-A order of Classes" << endl;
            cout << "5 - From the one with more students to the less students." << endl;
            cout << "6 - From the one with less students to the more students." << endl;
            cout << "Write the number of what you want to do: ";
            cin >> op;
            cout << endl;
            while (cin.fail() || op < 1 || op > 4) {
                cout << "Invalid number! Write the number of what you want to do: " << endl;
                cin >> op;
                cout << endl;
            }
            if (op == 1) {
                sort(ClassesPerUcVectorOfYear.begin(), ClassesPerUcVectorOfYear.end(), [](pair<UC, int> &A, pair<UC, int> &B) {
                    return A.first.getUcCode() < B.first.getUcCode();
                });
            }
            else if (op == 2) {
                sort(ClassesPerUcVectorOfYear.rbegin(), ClassesPerUcVectorOfYear.rend(), [](pair<UC, int> &A, pair<UC, int> &B) {
                    return A.first.getUcCode() < B.first.getUcCode();
                });
            }
            else if (op == 3) {
                sort(ClassesPerUcVectorOfYear.begin(), ClassesPerUcVectorOfYear.end(), [](pair<UC, int> &A, pair<UC, int> &B) {
                    return A.first.getClassCode() < B.first.getClassCode();
                });
            }
            else if (op == 3) {
                sort(ClassesPerUcVectorOfYear.rbegin(), ClassesPerUcVectorOfYear.rend(), [](pair<UC, int> &A, pair<UC, int> &B) {
                    return A.first.getClassCode() < B.first.getClassCode();
                });
            }
            else if (op == 5) {
                sort(ClassesPerUcVectorOfYear.begin(), ClassesPerUcVectorOfYear.end(), [](pair<UC, int> &A, pair<UC, int> &B) {
                    return A.second < B.second;
                });
            }
            else if (op == 6) {
                sort(ClassesPerUcVectorOfYear.begin(), ClassesPerUcVectorOfYear.end(), [](pair<UC, int> &A, pair<UC, int> &B) {
                    return A.second > B.second;
                });
            }
            if (op == 3 || op == 4) cout << "ClassCode; UcCode: Number of students" << endl;
            else cout << "UcCode; ClassCode: Number of students" << endl;
            for (pair<UC, int> &aux: ClassesPerUcVectorOfYear) {
                if (op == 3 || op == 4) cout << aux.first.getClassCode() << "; " << aux.first.getUcCode() << ": " << aux.second << endl;
                else cout << aux.first.getUcCode() << "; " << aux.first.getClassCode() << ": " << aux.second << endl;
            }
            break;

        case 4:
            return 1;

        case 5:
            return 0;
    }
    cout << "1 - Return to last Menu" << endl;
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
    if (op == 3) return 0;
    else if (op == 1) occupationMenu();
    return 1;
}

int greatestMenu() {
    AuxiliarFunctions func;
    CsvAndVectors CSVInfo;
    int op = 0;
    cout << endl << "------------------------------------------------" << endl;
    cout << endl << "     ...with the greatest number of students.   " << endl;
    cout << endl << "------------------------------------------------" << endl;
    cout << "1 - The Ucs..." << endl;
    cout << "2 - The Classes..." << endl;
    cout << "3 - The years..." << endl;
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

    set<string> UcSet;
    vector<pair<string, set<string>>> ClassesPerUcVector;
    int num = 0;
    vector<string> MAX;
    vector<int> max;
    vector<UC> MAXUC;
    vector<int> MAXYEARS;
    switch(op) {
        case 1:
            UcSet = CSVInfo.getUcSet();
            for (const string& UcCode : UcSet) {
                num = func.numberUcStudents(UcCode);
                if (num > max[0]) {
                    max.clear();
                    max.push_back(num);
                    MAX.clear();
                    MAX.push_back(UcCode);
                }
                else if (num == max[0]) {
                    max.push_back(num);
                    MAX.push_back(UcCode);
                }
            }
            cout << "The Ucs with the greatest number of students: " << endl;
            for (int i = 0; i < max.size(); i++) {
                cout << MAX[i] << " (" << max[i] << " students)" << endl;
            }
            break;

        case 2:
            ClassesPerUcVector = CSVInfo.getClassesPerUcVector();
            for (pair<string, set<string>> p : ClassesPerUcVector) {
                for (string ClassCode : p.second) {
                    UC uc = UC(p.first, ClassCode);
                    num = func.numberClassStudents(uc);
                    if (num > max[0]) {
                        max.clear();
                        max.push_back(num);
                        MAXUC.clear();
                        MAXUC.push_back(uc);
                    }
                    else if (num == max[0]) {
                        max.push_back(num);
                        MAXUC.push_back(uc);
                    }
                }
            }
            cout << "The Classes with the greatest number of students: " << endl;
            for (int i = 0; i < max.size(); i++) {
                cout << "UcCode: " << MAXUC[i].getClassCode() << "; ClassCode: " << MAXUC[i].getUcCode() <<
                     " (" << max[i] << " students)" << endl;
            }
            break;

        case 3:
            for (int year = 1; year < 4; year++) {
                num = func.numberYearStudents(year);
                if (num > max[0]) {
                    max.clear();
                    max.push_back(num);
                    MAXYEARS.clear();
                    MAXYEARS.push_back(year);
                }
                else if (num == max[0]) {
                    max.push_back(num);
                    MAXYEARS.push_back(year);
                }
            }
            cout << "The Years with the greatest number of students: " << endl;
            for (int i = 0; i < max.size(); i++) {
                cout << MAX[i] << " (" << max[i] << " students)" << endl;
            }
            break;

        case 4:
            return 1;

        case 5:
            return 0;
    }
    cout << "1 - Return to last Menu" << endl;
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
    if (op == 3) return 0;
    else if (op == 1) greatestMenu();
    return 1;
}

// Menu for the user choose which type of request he wants (enroll in an UC, leave an UC, change an UC
int requestMenu() {
    int op = 0;
    cout << endl << "--------------------------------" << endl;
    cout << endl << "     Submit a request for...    " << endl;
    cout << endl << "--------------------------------" << endl;
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
    int aux = submitRequest(op);
    if (aux == 0) return 0;
    return 1;
}

//TODO
int pendingRequests() {}
int processedRequest() {}

// Main Menu
int main() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Search for listings of..." << endl;
    cout << "2 - Search for the number of students..." << endl;
    cout << "3 - Search for schedules of..." << endl;
    cout << "4 - Search for occupation of..." << endl;
    cout << "5 - Search for the Ucs/Classes/Years with the greatest number of students." << endl;
    cout << "6 - Submit a request for..." << endl;
    cout << "7 - See requests that are pending." << endl;
    cout << "8 - See requests that have already been processed." << endl;
    cout << "9 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 9) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }

    int aux = 0;

    switch (op) {
        case 1:
            aux = listingMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 2:
            aux = numbersMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 3:
            aux = scheduleMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 4:
            aux = occupationMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 5:
            aux = greatestMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 6:
            aux = requestMenu();
            if (aux == 1) main();
            else system("exit");
            break;

        case 7:
            aux = pendingRequests();
            if (aux == 1) main();
            else system("exit");
            break;

        case 8:
            aux = processedRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        case 9:
            system("exit");
    }
    return 0;
}

