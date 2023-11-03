#include "Request.h"
#include <iostream>
#include <utility>

// O(1)
Request::Request(Student student, UC uc, string type) {
    this->student = std::move(student);
    this->uc = std::move(uc);
    this->type = std::move(type);

}

// O(1)
Student Request::getStudent() {return this->student; }

// O(1)
UC Request::getUC(){return this->uc; }

// O(1)
string Request::getType() {return this->type; }

// O(1)
string Request::getStatus() {return this->status; }

// O(1)
string Request::getReason() {return this->reason; }

// O(1)
string Request::getDescription() {return this->description; }

// O(1)
void Request::setStatus(string status) {this->status = std::move(status); }

// O(1)
void Request::setReason(string reason) {this->reason = std::move(reason); }

// O(1)
void Request::setDescription(string description) {this->description = std::move(description); }

// O(1)
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