#include "Student.h"

// constructor for the Student class
Student::Student(int studentCode, string studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;

}

// returns the studentCode
int Student::getStudentCode() const {
    return this->studentCode;
}

// return the studentName
string Student::getStudentName() const {
    return this->studentName;
}

// return the UCs of the student lessons
vector<UC> Student::getUCs() const {
    return this->ucs;
}

// adds an UC to the student lessons
void Student::addUC(const UC &uc) {
    this->ucs.push_back(uc);
}

// adds an UC to the student lessons
void Student::removeUC(const UC &uc) {
    remove(this->ucs.begin(),this->ucs.end(),uc);
}

// changes the UC of the student
void Student::changeUC(const UC &uc) {
    for (int i = 0; i < this->ucs.size(); i++) {
        if (uc.getUcCode() == this->ucs[i].getUcCode()) {
            this->ucs[i].setClassCode(uc.getClassCode());
        }
    }
}
