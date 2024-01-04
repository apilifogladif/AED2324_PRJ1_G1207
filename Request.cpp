#include "Request.h"
#include <iostream>
#include <utility>

Request::Request(Student student, UC uc, string type) {
    this->student = std::move(student);
    this->uc = std::move(uc);
    this->type = std::move(type);

}

Student Request::getStudent() {return this->student; }

UC Request::getoldUC() {return this->oldUc; }

UC Request::getUC(){return this->uc; }

string Request::getType() {return this->type; }

string Request::getStatus() {return this->status; }

string Request::getReason() {return this->reason; }

void Request::setStatus(string status_) {this->status = std::move(status_); }

void Request::setReason(string reason_) {this->reason = std::move(reason_); }

void Request::setoldUC(UC oldUc_) {this->oldUc = std::move(oldUc_); }

void Request::printRequest() {
    cout << student.getStudentCode() << " " << student.getStudentName() << " ";
    if (type == "Switch") {
        cout << "Switch to class " << uc.getUcCode() << " " << uc.getClassCode();
    } else if (type == "Enrollment") {
        cout << "Enroll in class " << uc.getUcCode() << " " << uc.getClassCode();
    } else if (type == "Removal") {
        cout << "Remove from UC " << uc.getUcCode();
    }
}
