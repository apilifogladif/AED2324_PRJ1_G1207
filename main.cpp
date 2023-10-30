#include <iostream>

#include "terminal.cpp"
#include "CsvAndVectors.h"

using namespace std;

int main() {
    int op = 0;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1 - Search for a class." << endl;
    cout << "2 - Search for a lesson." << endl;
    cout << "3 - Search for a student." << endl;
    cout << "4 - Search for a UC." << endl;
    cout << "Write the number of what you want to do: ";
    cin >> op;
    cout << endl;
    while (cin.fail() || op < 1 || op > 4) {
        cout << "Invalid number! Write the number of what you want to do: " << endl;
        cin >> op;
        cout << endl;
    }
    //clrscr();  ->  clear screen
    string StudentCode;
    string classCode;
    string UcCode;

    vector<Lesson> LessonsVector = getLessonsVector();
    vector<pair<string, set<string>>> ClassesPerUcVector = getClassesPerUcVector();
    vector<Student> StudentsVector = getStudentsVector();
    switch (op) {
        case 1:
            cout << "Write the code of the class: ";
            cin >> classCode;
            cout << endl;
            op = 0;
            cout << endl << "----------------------------" << endl;
            cout << endl << "      Class Menu   " << endl;
            cout << endl << "----------------------------" << endl;
            cout << "1 - Show the schedule of this class." << endl;
            cout << "2 - Number os students in this class." << endl;
            cout << "3 - Show sorted students." << endl;
            cout << "4 - Return to Main Menu." << endl;
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
                    //draw schedule
                case 2:

                case 3:

                case 4:
                    main();
            }
            break;
        case 2:
            cout << "Write the code of the class: ";
            cin >> classCode;
            cout << endl;
            cout << "Write the code of the uc: ";
            cin >> UcCode;
            cout << endl;
            op = 0;
            cout << endl << "----------------------------" << endl;
            cout << endl << "      Lesson Menu   " << endl;
            cout << endl << "----------------------------" << endl;
            cout << "1 - Show the schedule of this lesson." << endl;
            cout << "2 - Number of students in this lesson." << endl;
            cout << "3 - Show sorted students." << endl;
            cout << "4 - Return to Main Menu." << endl;
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
                    //draw schedule
                case 2:

                case 3:

                case 4:
                    main();
            }
            break;
        case 3:
            cout << "Write the code of the student: ";
            cin >> StudentCode;
            cout << endl;
            op = 0;
            cout << endl << "----------------------------" << endl;
            cout << endl << "      Student Menu   " << endl;
            cout << endl << "----------------------------" << endl;
            cout << "1 - Show the schedule of this student." << endl;
            cout << "2 - Make a request." << endl;
            cout << "3 - Return to Main Menu." << endl;
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
                    //draw schedule
                case 2:
                    RequestMenu();
                case 3:
                    main();
            }
            break;
        case 4:
            cout << "Write the code of the uc: ";
            cin >> UcCode;
            cout << endl;
            op = 0;
            cout << endl << "----------------------------" << endl;
            cout << endl << "      Uc Menu   " << endl;
            cout << endl << "----------------------------" << endl;
            cout << "1 - Show the schedule of this uc." << endl;
            cout << "2 - Number of students in this uc." << endl;
            cout << "3 - Show sorted students." << endl;
            cout << "4 - Return to Main Menu." << endl;
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
                    //draw schedule
                case 2:

                case 3:

                case 4:
                    main();
            }
            break;
    }
    return 0;
}