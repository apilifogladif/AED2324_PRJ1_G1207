#include "Student.h"
#include <algorithm>
#include "CsvAndVectors.h"

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

void Student::setUCs(vector<UC> ucs_) {
    this->ucs = ucs_;
}

void Student::addUC(const UC &uc) {
    int idx = this->binarySearchCsvStudentVector(0, CsvAndVectors::StudentsVector.size());

    vector<UC> ucs_ = CsvAndVectors::StudentsVector[idx].getUCs();
    ucs_.push_back(uc);
    CsvAndVectors::StudentsVector[idx].setUCs(ucs_);
}

void Student::removeUC(const UC &uc) {
    int idx = this->binarySearchCsvStudentVector(0, CsvAndVectors::StudentsVector.size());

    vector<UC> ucs_ = CsvAndVectors::StudentsVector[idx].getUCs();
    int index;
    for (int i = 0; i < ucs_.size(); i++) {
        if (ucs_[i] == uc) {
            index = i;
            break;
        }
    }
    ucs_.erase(ucs_.begin() + index);
    CsvAndVectors::StudentsVector[idx].setUCs(ucs_);
}

int Student::binarySearchCsvStudentVector(unsigned long left, unsigned long right) {
    if (left > right) return -1; //not found


    sort(CsvAndVectors::StudentsVector.begin(), CsvAndVectors::StudentsVector.end(), [](Student &A, Student &B) {
        return A.getStudentCode() < B.getStudentCode();
    });
    unsigned long mid = left + (right - left) / 2;
    if (CsvAndVectors::StudentsVector[mid].getStudentCode() == this->studentCode) {
        return mid; // Found the UC object at index mid
    }
    else if (CsvAndVectors::StudentsVector[mid].getStudentCode() > this->studentCode) {
        return binarySearchCsvStudentVector(left, mid - 1);
    }
    return binarySearchCsvStudentVector(mid + 1, right);
}

UC Student::findUc(const string& UcCode) const{
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return uc;
        }
    }
    return UC();
}

bool Student::operator<(const Student &s) const {
    return this->studentName < s.getStudentName();
}

bool Student::operator==(const Student &s) const {
    return this->studentCode == s.getStudentCode();
}
