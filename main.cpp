#include <iostream>
#include "CsvAndVectors.h"
#include "AuxiliarFunctions.h"
#include <algorithm>
#include <climits>


using namespace std;

/**
 * @file main.cpp
 *
 * @mainpage AED project main.cpp
 * @section intro_sec Introduction
 * This project has the intention of creating a functional schedules manager for a university.
 * This project was made by: Ana Filipa Geraldes, Filipa Fidalgo and Leonor Couto.
 */


// 0->quit; 1->main menu
/**
 * occupationSortMenu_case1 ????????????????????????????????????????????
 *
 * O(n log n) where n is the number of elements in auxVector (number of pairs in auxVector)
 *
 * @param UcCode
 * @param auxVector
 */
int occupationSortMenu_case1(string UcCode, vector<pair<string, int>> auxVector) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - Ascending order" << endl;
    cout << "2 - Descending order" << endl;
    cout << "3 - From the one with less students to the more students." << endl;
    cout << "4 - From the one with more students to the less students." << endl;
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
    cout << endl;
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
    if (op == 1) occupationSortMenu_case1(UcCode, auxVector);
    if (op == 3) return 0;
    return 1;
}

/**
 * occupationSortMenu_case2 ???????????????????
 *
 * O(n log n) where n is the number of elements in auxVector (number of pairs in auxVector)
 *
 * @param classCode
 * @param auxVector
 */
int occupationSortMenu_case2(string classCode, vector<pair<string, int>> auxVector) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - Ascending order" << endl;
    cout << "2 - Descending order" << endl;
    cout << "3 - From the one with less students to the more students." << endl;
    cout << "4 - From the one with more students to the less students." << endl;
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
    cout << endl;
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
    if (op == 1) occupationSortMenu_case2(classCode, auxVector);
    if (op == 3) return 0;
    return 1;
}

/**
 * occupationSortMenu_case3 ?????????????????????????????????????
 *
 * O(n log n) where n is the number of elements in ClassesPerVectorOfYear vector
 *
 * @param year
 * @param ClassesPerUcVectorOfYear
 */
int occupationSortMenu_case3(int year, vector<pair<UC, int>> ClassesPerUcVectorOfYear) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - Ascending order of UCs" << endl;
    cout << "2 - Descending order of UCs" << endl;
    cout << "3 - Ascending order of Classes" << endl;
    cout << "4 - Descending order of Classes" << endl;
    cout << "5 - From the one with less students to the one with more students." << endl;
    cout << "6 - From the one with more students to the one with less students." << endl;
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
    cout << endl;
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
    if (op == 1) occupationSortMenu_case3(year, ClassesPerUcVectorOfYear);
    if (op == 3) return 0;
    return 1;
}

/**
 * sortMenu ???????????????????????????????????
 *
 * O(n log n) where n is the number of elements to be sorted
 *
 * @param UcCode
 * @param classCode
 * @param year
 * @return
 */
int sortMenu(const string& UcCode, const string& classCode, int year) {
    int op = 0;
    cout << "How do you want the list to be sorted?" << endl;
    cout << "1 - A-Z order" << endl;
    cout << "2 - Z-A order" << endl;
    cout << "3 - Descending order" << endl;
    cout << "4 - Ascending order" << endl;
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
    if (year == '0' && !UcCode.empty() && !classCode.empty())
        AuxiliarFunctions::seeClassStudents(UC(UcCode, classCode), op);

    else if (year != '0' && UcCode.empty() && classCode.empty())
        AuxiliarFunctions::seeYearStudents(year, op);

    else if (year == '0' && !UcCode.empty() && classCode.empty())
        AuxiliarFunctions::seeUcStudents(UcCode, op);

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
    cout << endl;
    return op;
}

/**
 * verifyClass ?????????????????????????????
 *
 * O(1)
 *
 * @param ClassCode
 * @return
 */
bool verifyClass(const string& ClassCode) {
    if (CsvAndVectors::ClassesSet.find(ClassCode) == CsvAndVectors::ClassesSet.end()) return false;
    return true;
}

/**
 * verifyUc ?????????????????????????
 *
 * O(1)
 *
 * @param UcCode
 * @return
 */
bool verifyUc(const string& UcCode) {
    if (CsvAndVectors::UcSet.find(UcCode) == CsvAndVectors::UcSet.end()) return false;
    return true;
}

/**
 * verifyStudent?????????????????????????
 *
 * O(1)
 *
 * @param StudentCode
 * @return
 */
bool verifyStudent(const string& StudentCode) {
    if (CsvAndVectors::StudentsSet.find(StudentCode) == CsvAndVectors::StudentsSet.end()) return false;
    return true;
}

/**
 * enrollRequest??????????????????????????
 *
 * O(log n) where n is the size of the set
 *
 * @param student
 * @return
 */
int enrollRequest(Student student) {
    string UcCode;
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

    UC uc;
    uc = student.findUc(UcCode);
    if (uc.getUcCode() != "") {
        cout << "The student is already enrolled in this UC.";
        return 1;  //Main Menu
    }

    string classCode;
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

    AuxiliarFunctions::concludeEnrollment(student, UC(UcCode, classCode));
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
    if (op == 1) {
        AuxiliarFunctions::RequestsManager();
        return 1;
    }
    if (op == 2) {
        cout << endl;
        cout << "NOTE: if you quit now the requests you have made will be canceled. You must" << endl;
        cout << "You must return to the main menu so that the requests can have effect." << endl;
        cout << "If you want to see which requests were accepted and which were rejected, you must" << endl;
        cout << "consult that in the designated options in the main menu." << endl;
        cout << endl;
        string option;
        while (true) {
            cout << "Are you sure you want to quit? Y/N  ";
            if (cin >> option) {
                if (option == "Y") return 0;
                else if (option == "N") {
                    AuxiliarFunctions::RequestsManager();
                    return 1;
                }
                else {
                    cout << "Invalid answer! The answer should be Y (for Yes) or N (for No)." << endl;
                }
            } else {
                cout << "Invalid input! Please enter a valid answer." << endl;
                cin.clear();          // Clear the error state
                cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
            }
        }
    }
    return 0;
}

/**
 * leaveRequest ?????????????????????????????????
 *
 * O(log n) where n is the size of the set
 *
 * @param student
 * @return
 */
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

    UC uc;
    uc = student.findUc(UcCode);
    if (uc.getUcCode() == "") {
        cout << "This student is not enrolled in this Uc.";
        return 1;  //Main Menu
    }

    AuxiliarFunctions::concludeRemoval(student, uc);
    cout << "Removal request submitted." << endl;

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
    if (op == 1) {
        AuxiliarFunctions::RequestsManager();
        return 1;
    }
    if (op == 2) {
        cout << endl;
        cout << "NOTE: if you quit now the requests you have made will be canceled." << endl;
        cout << "You must return to the main menu so that the requests can have effect." << endl;
        cout << "If you want to see which requests were accepted and which were rejected, you must" << endl;
        cout << "consult that in the designated options in the main menu." << endl;
        cout << endl;
        string option;
        while (true) {
            cout << "Are you sure you want to quit? Y/N  ";
            if (cin >> option) {
                if (option == "Y") return 0;
                else if (option == "N") {
                    AuxiliarFunctions::RequestsManager();
                    return 1;
                }
                else {
                    cout << "Invalid answer! The answer should be Y (for Yes) or N (for No)." << endl;
                }
            } else {
                cout << "Invalid input! Please enter a valid answer." << endl;
                cin.clear();          // Clear the error state
                cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
            }
        }
    }
    return 0;
}

/**
 * switchRequest ???????????????????????
 *
 * O(log n) where n is the size of the set
 *
 * @param student
 * @return
 */
int switchRequest(Student student) {
    string UcCode;
    string newUcCode;
    string classCode;
    int op = 0;

    cout << "-----------------------------" << endl;
    cout << "         Switch Menu         " << endl;
    cout << "-----------------------------" << endl;
    cout << "1 - Switch an Uc." << endl;
    cout << "2 - Switch a class from a Uc." << endl;
    cout << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            } else {
                cout << "Invalid number! The number should be between 1 or 2." << endl;
            }
        } else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }

    vector<pair<string, int>> auxVector;
    pair<string, int> auxPair;
    string newClass;
    int occup = 0;
    int newClass_occup = INT_MAX;
    UC newuc;
    UC uc;

    switch(op) {
        case 1:
            while (true) {
               cout << "Write the Uc Code of the Uc you want to remove (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        uc = student.findUc(UcCode);
                        if (uc.getUcCode() == "") {
                            cout << "This student is not enrolled in this Uc.";
                            return 1;  //Main Menu
                        }
                        break;
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



            while (true) {
                cout << "Write the Uc Code you want to add(L.EICxxx or UPxxx): ";
                if (cin >> newUcCode) {
                    if (verifyUc(newUcCode)) {
                        uc = student.findUc(newUcCode);
                        if (uc.getUcCode() != "") {
                            cout << "This student is already enrolled in this Uc.";
                            return 1;  //Main Menu
                        }
                        break;
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

            while (true) {
                cout << "Write the Class Code you want to go to(yLEICxx; y->year, xx->class): ";
                if (cin >> newClass) {
                    if (verifyClass(newClass)) {
                        break;
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
            newuc = UC(newUcCode, newClass);

            student.removeUC(uc);
            student.addUC(newuc);

        case 2:
            while (true) {
                cout << "Write the Uc Code (L.EICxxx or UPxxx): ";
                if (cin >> UcCode) {
                    if (verifyUc(UcCode)) {
                        uc = student.findUc(UcCode);
                        if (uc.getUcCode() == "") {
                            cout << "This student is not enrolled in this Uc.";
                            return 1;  //Main Menu
                        }
                        break;
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

            while (true) {
                cout << "Write the Class Code you want to switch to(yLEICxx; y->year, xx->class): ";
                if (cin >> newClass) {
                    if (verifyClass(newClass)) {
                        if (uc.getClassCode() == newClass) {
                            cout << "This is already the class of this student in that Uc.";
                            return 1;  //Main Menu
                        }
                        break;
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

            newuc = UC(UcCode, newClass);
            student.removeUC(uc);
            student.addUC(newuc);
    }
    AuxiliarFunctions::concludeSwitch(student, uc, newuc);
    cout << "Switch request submitted." << endl;

    op = 0;
    cout << "1 - Return to Main Menu." << endl;
    cout << "2 - Quit" << endl;
    while (true) {
        cout << "Write the number of what you want to do: ";
        if (cin >> op) {
            if (op >= 1 && op <= 2) {
                break;  // Input is valid, exit the loop
            } else {
                cout << "Invalid number! The number should be 1 or 2." << endl;
            }
        } else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();          // Clear the error state
            cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
        }
    }
    if (op == 1) {
        AuxiliarFunctions::RequestsManager();
        return 1;
    }
    if (op == 2) {
        cout << endl;
        cout << "NOTE: if you quit now the requests you have made will be canceled. You must" << endl;
        cout << "You must return to the main menu so that the requests can have effect." << endl;
        cout << "If you want to see which requests were accepted and which were rejected, you must" << endl;
        cout << "consult that in the designated options in the main menu." << endl;
        cout << endl;
        string option;
        while (true) {
            cout << "Are you sure you want to quit? Y/N  ";
            if (cin >> option) {
                if (option == "Y") return 0;
                else if (option == "N") {
                    AuxiliarFunctions::RequestsManager();
                    return 1;
                }
                else {
                    cout << "Invalid answer! The answer should be Y (for Yes) or N (for No)." << endl;
                }
            } else {
                cout << "Invalid input! Please enter a valid answer." << endl;
                cin.clear();          // Clear the error state
                cin.ignore(INT_MAX , '\n'); // Ignore the invalid input
            }
        }
    }
    return 0;
}

/**
 * submitRequest ?????????????????????????
 *
 * O(log n) where n is the size of the set
 *
 * @param op : option chosen by the user
 * @return
 */
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

    Student student = AuxiliarFunctions::retStudent(studentCode);

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

/**
 * listingMenu ??????????
 *
 * O(log n) where n is the size of the set
 *
 * @return
 */
int listingMenu() {
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
                    if (year == '0' || year == '2' || year == '3') {
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

/**
 * numbersMenu ????????????????????????????????
 *
 * O(n) where n is the number of students
 *
 * @return
 */
int numbersMenu() {
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
    int num = 0;
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
            cout << AuxiliarFunctions::numberUcStudents(UcCode) << " students." << endl;
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

            cout << AuxiliarFunctions::numberClassStudents(UC(UcCode, classCode)) << " students." << endl;
            break;

        case 3:
            while (true) {
                cout << "Write the year (1, 2 or 3): ";
                if (cin >> year) {
                    if (year == '0' || year == '1' || year == '2') {
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
            cout << AuxiliarFunctions::numberYearStudents(year) << " students." << endl;
            break;

        case 4:
            while (true) {
                cout << "How many Ucs? (Write a number between 1 and 7) ";
                if (cin >> num) {
                    if (num >= 1 && num <= 7) {
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
            for (const Student& student : CsvAndVectors::StudentsVector) {
                if (student.getUCs().size() == num) count++;
            }
            cout << count << " students." << endl;
            break;

        case 5:
            return 1;

        default:
            return 0;
    }
    cout << endl;
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

 /**
  * scheduleMenu ???????????????????????????????????????
  *
  * O(1)
  *
  * @return
  */
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
            AuxiliarFunctions::seeUcSchedule(UcCode);
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
            AuxiliarFunctions::seeClassSchedule(classCode);
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
            AuxiliarFunctions::seeStudentSchedule(studentCode);
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

/**
 * occupationMenu ?????????????????????????
 *
 * O(n log n) where n is the number of elements to be sorted
 *
 * @return
 */
int occupationMenu() {
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
    vector<pair<string, int>> auxVector;
    pair<string, int> auxPair;
    pair<UC, int> auxPair2;
    int year;
    int aux = 0;
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

            for (pair<string, set<string>> p : CsvAndVectors::ClassesPerUcVector) {
                if (p.first == UcCode) {
                    for (string Class : p.second) {
                        auxPair.first = Class;
                        auxPair.second = AuxiliarFunctions::numberClassStudents(UC(UcCode, Class));
                        auxVector.push_back(auxPair);
                    }
                }
            }
            aux = occupationSortMenu_case1(UcCode, auxVector);
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

            for (pair<string, set<string>> p : CsvAndVectors::ClassesPerUcVector) {
                if (p.second.find(classCode) != p.second.end()) {
                    auxPair.first = p.first;
                    auxPair.second = AuxiliarFunctions::numberClassStudents(UC(UcCode, classCode));
                    auxVector.push_back(auxPair);
                }
            }
            aux = occupationSortMenu_case2(classCode, auxVector);
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
            for (pair<string, set<string>> &p : CsvAndVectors::ClassesPerUcVector) {
                for (auto Class : p.second) {
                    if(static_cast<int>(Class[0]) - 48 == year) {
                        auxPair2.first = UC(p.first, Class);
                        auxPair2.second = AuxiliarFunctions::numberClassStudents(auxPair2.first);
                        ClassesPerUcVectorOfYear.push_back(auxPair2);
                    }
                }
            }
            aux = occupationSortMenu_case3(year, ClassesPerUcVectorOfYear);
            break;

        case 4:
            return 1;

        case 5:
            return 0;
    }
    if (aux == 0) return 0;
    return 1;
}

 /**
  * greatestMenu ????????????????????
  *
  * O(m) + O(n log n) where m is the total number of UCs or Classes and n is the number of elements to be sorted
  *
  * @return
  */
int greatestMenu() {
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
    cout << endl;

    set<string> UcSet;
    int num = 0;
    vector<string> MAX;
    vector<int> max;
    vector<UC> MAXUC;
    vector<char> MAXYEARS;
    max.push_back(0);
    switch(op) {
        case 1:
            UcSet = CsvAndVectors::UcSet;
            for (const string& UcCode : UcSet) {
                num = AuxiliarFunctions::numberUcStudents(UcCode);
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
            for (pair<string, set<string>> p : CsvAndVectors::ClassesPerUcVector) {
                for (string ClassCode : p.second) {
                    UC uc = UC(p.first, ClassCode);
                    num = AuxiliarFunctions::numberClassStudents(uc);
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
            cout << "UcCode; ClassCode";
            for (int i = 0; i < max.size(); i++) {
                cout << MAXUC[i].getClassCode() << "; " << MAXUC[i].getUcCode() <<
                     " (" << max[i] << " students)" << endl;
            }
            break;

        case 3:
            for (char year = '1'; year < '4'; year++) {
                num = AuxiliarFunctions::numberYearStudents(year);
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
                cout << MAXYEARS[i] << " (" << max[i] << " students)" << endl;
            }
            break;

        case 4:
            return 1;

        case 5:
            return 0;
    }
    cout << endl;
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
  * O(1)
  *
  * Options : enroll in an UC, leave an UC or change an UC;
  *
  * @return
  */
int requestMenu() {
    AuxiliarFunctions::getRequests();
    int op = 0;
    cout << endl << "--------------------------------" << endl;
    cout << endl << "     Submit a request for...    " << endl;
    cout << endl << "--------------------------------" << endl;
    cout << "1 - Enroll in an UC." << endl;
    cout << "2 - Leave an UC." << endl;
    cout << "3 - Switch an UC." << endl;
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
    if (op == 4) return 1;
    if (op == 5) return 0;
    int aux = submitRequest(op);
    if (aux == 0) return 0;
    return 1;
}

/**
 * Prints the pending requests
 *
 * O(n) where n is the number of accepted requests
 *
 * @return
 */
int acceptedRequest() {
    int op;
    AuxiliarFunctions func = AuxiliarFunctions();
    AuxiliarFunctions::seeAcceptedRequests();
    cout << endl;
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
 *
 * O(n) where n is the number of rejected requests
 *
 * @return
 */
int rejectedRequest() {
    int op;
    AuxiliarFunctions func = AuxiliarFunctions();
    AuxiliarFunctions::seeRejectedRequests();
    cout << endl;
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
 * Prints all requests
 *
 * O(n) where n is the number of all requests made
 *
 * @return
 */
int allRequest() {
    int op;
    AuxiliarFunctions func = AuxiliarFunctions();
    AuxiliarFunctions::seeAllRequests();
    cout << endl;
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
 * Main
 *
 * O(1)
 *
 * @return
 */
int main() {
    cout << "IM ALMOST HERE" << endl;
    if (CsvAndVectors::StudentsVector.size() != 0) {
        cout << "IM HERE" << endl;
        CsvAndVectors::setFromRequestVector();
        CsvAndVectors::setFromStudentsVector();
    }

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
    cout << "7 - See rejected requests." << endl;
    cout << "8 - See accepted requests." << endl;
    cout << "9 - See all requests made." << endl;
    cout << "10 - Quit." << endl;
    cout << endl;
    cout << "Note: If you enter a 'q' when asked for a classCode, UcCode studentCode" << endl;
    cout << "or year, you will return to the main menu." << endl;
    cout << endl;

    CsvAndVectors::createStudentsVector();
    CsvAndVectors::createRequestsVector();
    CsvAndVectors::createClassesPerUcVector();
    CsvAndVectors::createLessonsVector();
    CsvAndVectors::createStudentsSet();
    CsvAndVectors::createClassesAndUcSet();

    cout << CsvAndVectors::StudentsVector.size() << endl;
    for (auto student : CsvAndVectors::StudentsVector) {
        for (auto uc: student.getUCs()) {
            cout << student.getStudentCode() << " " << uc.getUcCode() << " " << uc.getClassCode()
                 << endl;
        }
    }

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
            aux = rejectedRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        case 8:
            aux = acceptedRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        case 9:
            aux = allRequest();
            if (aux == 1) main();
            else system("exit");
            break;

        default:
            system("exit");
    }
    return 0;
}