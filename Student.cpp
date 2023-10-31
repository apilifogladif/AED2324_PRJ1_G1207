#include "Student.h"
#include "CsvAndVectors.h"
#include <algorithm>
#include <iostream>

Student::Student() {
    this->studentCode = "";
    this->studentName = "";
}

Student::Student(string studentCode, string studentName) {
    this->studentCode = std::move(studentCode);
    this->studentName = std::move(studentName);
}

Student::Student(string studentCode, string studentName, vector<UC> ucs) : ucs(std::move(ucs)) {
    this->studentCode = std::move(studentCode);
    this->studentName = std::move(studentName);
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
            UC old_uc = i;
            i.setClassCode(uc.getClassCode());
            return old_uc;
        }
    }
    return UC();
}

UC Student::findUc(const string& UcCode) const{
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return uc;
        }
    }
    return UC();
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
    for (auto uc: ucs) {
        cout << uc.getUcCode() << " " << uc.getClassCode() << endl;
    }
}
