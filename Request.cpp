#include "Request.h"
#include <iostream>
#include <utility>

Request::Request(Student* student, UC* uc, string type) {
    this->student = student;
    this->uc = uc;
    this->type = std::move(type);

}

Student Request::getStudent() {
    return *this->student;
}

UC Request::getUC(){
    return *this->uc;
}

string Request::getType() {
    return this->type;
}

void Request::printRequest() {
    cout << student->getStudentCode() << " " << student->getStudentName();
    if (type == "Switch") {
        cout << "Switch to class " << uc->getUcCode() << " " << uc->getClassCode();
    } else if (type == "Enrollment") {
        cout << "Enroll in class " << uc->getUcCode() << " " << uc->getClassCode();
    } else if (type == "Removal") {
        cout << "Remove from UC " << uc->getUcCode();
    }
}