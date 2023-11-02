#include "Request.h"
#include <iostream>
#include <utility>

Request::Request(Student student, UC uc, string type) {
    this->student = std::move(student);
    this->uc = std::move(uc);
    this->type = std::move(type);

}

Student Request::getStudent() {return this->student; }

UC Request::getUC(){return this->uc; }

string Request::getType() {return this->type; }

string Request::getStatus() {return this->status; }

string Request::getReason() {return this->reason; }

string Request::getDescription() {return this->description; }

void Request::setStatus(string status) {this->status = std::move(status); }

void Request::setReason(string reason) {this->reason = std::move(reason); }

void Request::setDescription(string description) {this->description = std::move(description); }

void Request::printRequest() {
    cout << student.getStudentCode() << " " << student.getStudentName();
    if (type == "Switch") {
        cout << "Switch to class " << uc.getUcCode() << " " << uc.getClassCode();
    } else if (type == "Enrollment") {
        cout << "Enroll in class " << uc.getUcCode() << " " << uc.getClassCode();
    } else if (type == "Removal") {
        cout << "Remove from UC " << uc.getUcCode();
    }
}


