#include "Student.h"
#include <algorithm>
#include <iostream>
#include "CsvAndVectors.h"

// O(1)
Student::Student() {
    this->studentCode = "";
    this->studentName = "";
}

// O(1)
Student::Student(string studentCode, string studentName) {
    this->studentCode = std::move(studentCode);
    this->studentName = std::move(studentName);
}

// O(1)
Student::Student(string studentCode, string studentName, vector<UC> ucs) : ucs(std::move(ucs)) {
    this->studentCode = std::move(studentCode);
    this->studentName = std::move(studentName);
}

// O(1)
string Student::getStudentCode() const {
    return this->studentCode;
}

// O(1)
string Student::getStudentName() const {
    return this->studentName;
}

// O(1)
vector<UC> Student::getUCs() const {
    return this->ucs;
}

//  O(log n) + O(n) where n is the number of students int the CSVInfo.StudentsVector
void Student::addUC(const UC &uc) {
    this->ucs.push_back(uc);
    CsvAndVectors CSVInfo;
    CSVInfo.createStudentsVector();

    int idx = this->binarySearchCsvStudentVector(0, CSVInfo.StudentsVector.size());
    CSVInfo.StudentsVector[idx].getUCs().push_back(uc);
    CSVInfo.setFromStudentsVector();
}

//  O(log n) + O(n) where n is the number of students int the CSVInfo.StudentsVector
void Student::removeUC(const UC &uc) {
    CsvAndVectors CSVInfo;
    CSVInfo.createStudentsVector();

    auto it = find(this->ucs.begin(), this->ucs.end(), uc);
    this->ucs.erase(it);
    int idx = this->binarySearchCsvStudentVector(0, CSVInfo.StudentsVector.size());
    std::remove(CSVInfo.StudentsVector[idx].getUCs().begin(), CSVInfo.StudentsVector[idx].getUCs().end(), uc);
    CSVInfo.setFromStudentsVector();
}

// O(n log n) where n is the number of students in the CSVInfo.StudentsVector
int Student::binarySearchCsvStudentVector(unsigned long left, unsigned long right) {
    if (left > right) return -1; //not found

    CsvAndVectors CSVInfo;

    sort(CSVInfo.StudentsVector.begin(), CSVInfo.StudentsVector.end(), [](Student &A, Student &B) {
        return A.getStudentCode() < B.getStudentCode();
    });
    unsigned long mid = left + (right - left) / 2;
    if (CSVInfo.StudentsVector[mid].getStudentCode() == this->studentCode) {
        return mid; // Found the UC object at index mid
    }
    else if (CSVInfo.StudentsVector[mid].getStudentCode() > this->studentCode) {
        return binarySearchCsvStudentVector(left, mid - 1);
    }
    return binarySearchCsvStudentVector(mid + 1, right);
}

// TODO
// acho que falta completar com o CSVInfo e tal
// O(n) where n is the number of UC objects in the ucs vector
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

// O(n) where n is the number of UC objects in the ucs vector
UC Student::findUc(const string& UcCode) const{
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return uc;
        }
    }
    return UC();
}

// O(n) where n is the number of UC objects in the ucs vector
bool Student::Enrolled(const string& UcCode) {
    for (UC uc: this->ucs) {
        if (uc.getUcCode() == UcCode) {
            return true;
        }
    }
    return false;
}

// O(1)
bool Student::operator<(const Student &s) const {
    return this->studentName < s.getStudentName();
}

// O(1)
bool Student::operator==(const Student &s) const {
    return this->studentCode == s.getStudentCode();
}

// O(n) where n is the number of UC objects in the ucs vector
void Student::printUcAndClass() const {
    for (auto uc: ucs) {
        cout << uc.getUcCode() << " " << uc.getClassCode() << endl;
    }
}
