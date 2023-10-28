#include "Student.h"
#include <algorithm>
#include <iostream>
#include <utility>

Student::Student(string studentCode, string studentName, vector<UC> ucs, UC ucClass) : UcClass(std::move(ucClass)) {
    this->studentCode = std::move(studentCode);
    this->studentName = std::move(studentName);
    this->ucs = std::move(ucs);
}

Student::Student(string studentCode, string studentName, UC ucClass) : UcClass(std::move(ucClass)) {
    this->studentCode = std::move(studentCode);
    this->studentName = std::move(studentName);
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
    for (auto & i : this->ucs) {
        if (uc.getUcCode() == i.getUcCode()) {
            i.setClassCode(uc.getClassCode());
        }
    }
}

UC Student::findUc(const string& UcCode) const{
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return uc;
        }
    }
}

bool Student::Enrolled(const string& UcCode) {
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

void Student::printUcAndClass() const {
    cout << UcClass.getUcCode() << " " << UcClass.getClassCode() << endl;
}
