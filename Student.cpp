#include "Student.h"
#include <algorithm>

Student::Student(string studentCode, string studentName, vector<UC> ucs) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->ucs = ucs;
}

Student::Student(string studentCode, string studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->ucs = vector<UC>();
}

string Student::getStudentCode() const {
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
    auto it = find(this->ucs.begin(),this->ucs.end(),uc);
    this->ucs.erase(it);
}

UC Student::changeUC(const UC &uc) {
    for (int i = 0; i < this->ucs.size(); i++) {
        if (uc.getUcCode() == this->ucs[i].getUcCode()) {
            this->ucs[i].setClassCode(uc.getClassCode());
        }
    }
}

UC Student::findUc(string UcCode) const{
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return uc;
        }
    }
}

bool Student::Enrolled(string UcCode) {
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return true;
        }
    }
    return false;
}


bool Student::operator<(const Student &s) const {
    return this->studentName < s.getStudentName();
}

bool Student::operator==(const Student &s) const {
    return this->studentCode == s.getStudentCode();
}