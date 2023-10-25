#include <iostream>
#include <string>

using namespace std;

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
    cin << op << endl;
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

void searchClass() {
    string classCode;
    cout << "Write the code of the class: ";
    cin << classCode << endl;
    cout <<

}
void searchLesson() {

}
void searchStudent() {

}
void searchUC() {

}