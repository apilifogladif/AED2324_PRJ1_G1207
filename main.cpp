#include <iostream>
#include "CsvAndVectors.h"
#include "AuxiliarFunctions.h"
#include <algorithm>


using namespace std;

// 0->quit; 1->main menu

void occupationSortMenu_case1(string UcCode, vector<pair<string, int>> auxVector) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - Numerical order" << endl;
    cout << "2 - Reverse numerical" << endl;
    cout << "3 - From the one with more students to the less students." << endl;
    cout << "4 - From the one with less students to the more students." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 4) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 4." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
}

void occupationSortMenu_case2(string classCode, vector<pair<string, int>> auxVector) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - Numerical order" << endl;
    cout << "2 - Reverse numerical" << endl;
    cout << "3 - From the one with more students to the less students." << endl;
    cout << "4 - From the one with less students to the more students." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 4) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 4." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
}

void occupationSortMenu_case3(int year, vector<pair<UC, int>> ClassesPerUcVectorOfYear) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - Numerical order os UCs" << endl;
    cout << "2 - Reverse numerical of UCs" << endl;
    cout << "3 - Numerical order of Classes" << endl;
    cout << "4 - Reverse numerical of Classes" << endl;
    cout << "5 - From the one with more students to the less students." << endl;
    cout << "6 - From the one with less students to the more students." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 6) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 6." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
}

int sortMenu(const string& UcCode, const string& classCode, int year) {
    AuxiliarFunctions func;
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - A-Z order" << endl;
    cout << "2 - Z-A order" << endl;
    cout << "3 - numerical" << endl;
    cout << "4 - reverse numerical" << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 4) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 4." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (year == 0 && UcCode != "" && classCode != "")
        func.seeClassStudents(UC(UcCode, classCode), op);

    else if (year != 0 && UcCode == "" && classCode == "")
        func.seeYearStudents(year, op);

    else if (year == 0 && UcCode != "" && classCode == "")
        func.seeUcStudents(UcCode, op);

    cout << "1 - Return to last Menu" << endl;
    cout << "2 - Return to Main Menu" << endl;
    cout << "3 - Quit." << endl;
    cout << "Write the number of what you want to do: ";
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 3) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    return op;
}

bool verifyClass(const string& ClassCode) {
    CsvAndVectors CSVInfo;
    set<string> ClassesSet = CSVInfo.getClassesSet();
    if (ClassesSet.find(ClassCode) == ClassesSet.end()) return false;
    return true;
}

bool verifyUc(const string& UcCode) {
    CsvAndVectors CSVInfo;
    set<string> UcSet = CSVInfo.getUcSet();
    if (UcSet.find(UcCode) == UcSet.end()) return false;
    return true;
}

bool verifyStudent(const string& StudentCode) {
    CsvAndVectors CSVInfo;
    set<string> StudentsSet = CSVInfo.getStudentsSet();
    if (StudentsSet.find(StudentCode) == StudentsSet.end()) return false;
    return true;
}

int enrollRequest(Student student) {
    string UcCode;
    string classCode;
    while (true) {
        cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
        if (cin >> UcCode) {
            if (verifyUc(UcCode)) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid Uc Code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Uc Code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (student.Enrolled(UcCode)) {
        cout << "The student is already enrolled in this UC." << endl;
    }
    while (true) {
        cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
        if (cin >> classCode) {
            if (verifyClass(classCode)) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid Class Code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Class Code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    AuxiliarFunctions func2;
    func2.concludeEnrollment(student, UC(UcCode, classCode));
    cout << "Enrollment request submitted." << endl;

    int op = 0;
    cout << "1 - Return to Main Menu." << endl;
    cout << "2 - Quit" << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be 1 or 2." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) return 1;
    return 0;
}

int leaveRequest(Student student) {
    string UcCode;
    string classCode;
    while (true) {
        cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
        if (cin >> UcCode) {
            if (verifyUc(UcCode)) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid Uc Code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Uc Code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be 1 or 2." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) return 1;
    return 0;
}

int switchRequest(Student student) {
    string UcCode;
    string classCode;
    while (true) {
        cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
        if (cin >> UcCode) {
            if (verifyUc(UcCode)) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid Uc Code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Uc Code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (!(student.Enrolled(UcCode))) {
        cout << "The student is not enrolled in this UC." << endl;
    }
    while (true) {
        cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
        if (cin >> classCode) {
            if (verifyClass(classCode)) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid Class Code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Class Code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    AuxiliarFunctions func4;
    Schedule schedule = Schedule(UC(UcCode, classCode));
    func4.concludeSwitch(student, UC(UcCode, classCode));
    cout << "Switch request submitted." << endl;

    int op = 0;
    cout << "1 - Return to Main Menu." << endl;
    cout << "2 - Quit" << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            } else {
                cout << "Invalid number! The number should be between 1 and 2." << endl;
            }
        } else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) return 1;
    return 0;
}

int submitRequest(int op) {
    string studentCode;
    while (true) {
        cout << "Write the Student Code (eg.: 20xxxxxxx): ";
        if (cin >> studentCode) {
            if (verifyStudent(studentCode)) {
                break;  // Input is valid, exit the loop
            }
            else if (studentCode == "q") return 1;
            else {
                cout << "Invalid Student Code!" << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid Student Code." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
        cout << "Invalid number! Write the number of what you want to do: ";
        cin >> op;
        cout << endl;
    }
    string UcCode;
    string sort_;
    string  classCode;
    CsvAndVectors CSVInfo;
    char year = '0';
    cout << endl;
    switch (op) {
        case 1:
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (UcCode == "q") return 1;
                    else {
                        cout << "Invalid Uc Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Uc Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }

            while (true) {
                cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
                if (cin >> classCode) {
                    if (verifyClass(classCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (classCode == "q") return 1;
                    else {
                        cout << "Invalid Class Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Class Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }

            op = sortMenu(UcCode, classCode, year);
            break;

        case 2:
            while (true) {
                cout << "Write the year (1, 2 or 3): ";
                if (cin >> year) {
                    if (year >= 0 && year <= 3) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (year == 'q') return 1;
                    else {
                        cout << "Invalid year!" << endl;
                    }
                } else {
                    cout << "Invalid input! Please enter a valid year." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            op = sortMenu(UcCode, classCode, year);
            break;

        case 3:
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (UcCode == "q") return 1;
                    else {
                        cout << "Invalid Uc Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Uc Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            op = sortMenu(UcCode, classCode, year);
            break;
        case 4:
            return 1;
        case 5:
            return 0;
    }

    while (op == 1) op = sortMenu(UcCode, classCode, year);
    if (op == 3) return 0;
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 6) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 6." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }

    string UcCode;
    string classCode;
    char year = '0';
    int count = 0;
    int num;
    vector<Student> StudentsVector;
    switch(op) {
        case 1:
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (UcCode == "q") return 1;
                    else {
                        cout << "Invalid Uc Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Uc Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            cout << func.numberUcStudents(UcCode) << " students." << endl;
            break;

        case 2:
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (UcCode == "q") return 1;
                    else {
                        cout << "Invalid Uc Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Uc Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }

            while (true) {
                cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
                if (cin >> classCode) {
                    if (verifyClass(classCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (classCode == "q") return 1;
                    else {
                        cout << "Invalid Class Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Class Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }

            cout << func.numberClassStudents(UC(UcCode, classCode)) << " students." << endl;
            break;

        case 3:
            while (true) {
                cout << "Write the year (1, 2 or 3): ";
                if (cin >> year) {
                    if (year >= 0 && year <= 3) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (year == 'q') return 1;
                    else {
                        cout << "Invalid year!" << endl;
                    }
                } else {
                    cout << "Invalid input! Please enter a valid year." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            cout << func.numberYearStudents(year) << " students." << endl;
            break;

        case 4:
            StudentsVector = CSVInfo.getStudentsVector();
            while (true) {
                cout << "How many Ucs? (Write a number between 1 and 7) ";
                if (cin >> op) {
                    if (op >= 1 && op <= 7) {
                        break;  // Input is valid, exit the loop
                    }
                    else {
                        cout << "Invalid number!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid number." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 3) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 5) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 5." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    string UcCode;
    string classCode;
    string studentCode;
    CsvAndVectors CSVInfo;
    cout << endl;

    switch (op) {
        case 1:
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (UcCode == "q") return 1;
                    else {
                        cout << "Invalid Uc Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Uc Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            cout << endl;
            func.seeUcSchedule(UcCode);
            break;

        case 2:
            while (true) {
                cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
                if (cin >> classCode) {
                    if (verifyClass(classCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (classCode == "q") return 1;
                    else {
                        cout << "Invalid Class Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Class Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            cout << endl;
            func.seeClassSchedule(classCode);
            break;

        case 3:
            while (true) {
                cout << "Write the Student Code (eg.: 20xxxxxxx): ";
                if (cin >> studentCode) {
                    if (verifyStudent(studentCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (studentCode == "q") return 1;
                    else {
                        cout << "Invalid Student Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Student Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            cout << endl;
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 3) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 5) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 5." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (UcCode == "q") return 1;
                    else {
                        cout << "Invalid Uc Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Uc Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
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
            occupationSortMenu_case1(UcCode, auxVector);
            break;

        case 2:
            while (true) {
                cout << "Write the Class Code (yLEICxx; y->year, xx->class): ";
                if (cin >> classCode) {
                    if (verifyClass(classCode)) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (classCode == "q") return 1;
                    else {
                        cout << "Invalid Class Code!" << endl;
                    }
                }
                else {
                    cout << "Invalid input! Please enter a valid Class Code." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
            }
            ClassesPerUcVector = CSVInfo.getClassesPerUcVector();

            for (pair<string, set<string>> p : ClassesPerUcVector) {
                if (p.second.find(classCode) != p.second.end()) {
                    auxPair.first = p.first;
                    auxPair.second = func.numberClassStudents(UC(UcCode, classCode));
                    auxVector.push_back(auxPair);
                }
            }
            occupationSortMenu_case2(classCode, auxVector);
            break;

        case 3:
            while (true) {
                cout << "Write the year (1, 2 or 3): ";
                if (cin >> year) {
                    if (year >= 0 && year <= 3) {
                        break;  // Input is valid, exit the loop
                    }
                    else if (year == 'q') return 1;
                    else {
                        cout << "Invalid year!" << endl;
                    }
                } else {
                    cout << "Invalid input! Please enter a valid year." << endl;
                    cin.clear();          // Clear the error state
                    cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
                }
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
            occupationSortMenu_case3(year, ClassesPerUcVectorOfYear);
            break;

        case 4:
            return 1;

        case 5:
            return 0;
    }
    int op2 = 0;
    cout << "1 - Return to last Menu" << endl;
    cout << "2 - Return to Main Menu" << endl;
    cout << "3 - Quit." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op2) {
            if (op2 >= 1 && op2 <= 3) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    while (op2 == 1 && op == 1) occupationSortMenu_case1(UcCode, auxVector);
    while (op2 == 1 && op == 2) occupationSortMenu_case2(classCode, auxVector);
    while (op2 == 1 && op == 3) occupationSortMenu_case3(year, ClassesPerUcVectorOfYear);
    if (op2 == 3) return 0;
    return 1;
}
/*
 * 
 */
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 3) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 3) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 3." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 3) return 0;
    else if (op == 1) greatestMenu();
    return 1;
}
/**
 * Menu for the user choose which type of request he wants
 *
 * Options : enroll in an UC, leave an UC or change an UC;
 */
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
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 5) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be between 1 and 5." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    int aux = submitRequest(op);
    if (aux == 0) return 0;
    return 1;
}

/**
 * Prints the pending requests
 */
int pendingRequests() {
    int op;
    AuxiliarFunctions func = AuxiliarFunctions();
    if (func.totalNumberOfPendingRequests() == 0) {
        cout << "There are no pending requests." << endl;
    }
    func.seePendingRequests();
    cout << "1 - Return to Main Menu" << endl;
    cout << "2 - Quit." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be 1 or 2." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) return 1;
    return 0;
}

/**
 * Prints the processed requests
 */
int processRequest() {
    int op;
    AuxiliarFunctions func = AuxiliarFunctions();
    if (func.totalNumberOfPendingRequests() == 0) {
        cout << "There are no processed requests." << endl;
        cout << endl;
        cout << "1 - Return to Main Menu" << endl;
        cout << "2 - Quit." << endl;
        while (true) {
            cout << "Write the number of what you want to do: ";
            if (cin >> op) {
                if (op >= 1 && op <= 2) {
                    break;  // Input is valid, exit the loop
                }
                else {
                    cout << "Invalid number! The number should be 1 or 2." << endl;
                }
            }
            else {
                cout << "Invalid input! Please enter a valid number." << endl;
                cin.clear();          // Clear the error state
                cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
            }
        }
        if (op == 1) return 1;
        return 0;
    }
    func.RequestsManager();
    cout << endl;
    cout << "1 - Return to Main Menu" << endl;
    cout << "2 - Quit." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be 1 or 2." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) return 1;
    return 0;
}

/**
 * Prints the rejected requests
 */
int rejectedRequest() {
    int op;
    AuxiliarFunctions func = AuxiliarFunctions();
    if (func.totalNumberOfRejectedRequests() == 0) {
        cout << "There are no rejected requests." << endl;
    }
    func.seeRejectedRequests();
    cout << "1 - Return to Main Menu" << endl;
    cout << "2 - Quit." << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            }
            else {
                cout << "Invalid number! The number should be 1 or 2." << endl;
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) return 1;
    return 0;
}

/**
 * Main menu
 */
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
    cout << "8 - Process requests that are pending." << endl;
    cout << "9 - See requests that have already been processed." << endl;
    cout << "10 - Quit." << endl;
    cout << endl;
    cout << "Note: If you enter a 'q' when asked for a classCode, UcCode studentCode" << endl;
    cout << "or year, you will return to the main menu." << endl;
    cout << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 10) {
                break;  // Input is valid, exit the loop
            } else {
                cout << "Invalid number! The number should be between 1 and 10." << endl;
            }
        } else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
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
            aux = processRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        case 9:
            aux = rejectedRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        case 10:
            system("exit");
    }
    return 0;
}

