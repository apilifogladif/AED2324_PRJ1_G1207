#include "Student.h"

Student::Student(int studentCode, string studentName, vector<UC> ucs) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->ucs = ucs;

}

int Student::getStudentCode() const {
    return this->studentCode;
}

string Student::getStudentName() const {
    return this->studentName;
}

vector<UC> Student::getUCs() const {
    return this->ucs;
}

void Student::addUC(const UC &uc) {
    this->ucs.push_back(uc);
}

void Student::removeUC(const UC &uc) {
    remove(this->ucs.begin(),this->ucs.end(),uc);
}

void Student::changeUC(const UC &uc) {
    for (int i = 0; i < this->ucs.size(); i++) {
        if (uc.getUcCode() == this->ucs[i].getUcCode()) {
            this->ucs[i].setClassCode(uc.getClassCode());
        }
    }
}

bool Student::findUc(const string UcCode) {
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return true;
        }
    }
    return false;
}

bool Student::Enrolled(string UcCode) {
    for (UC uc: ucs) {
        if (uc.getUcCode() == UcCode) {
            return true;
        }
    }
    return false;
}
