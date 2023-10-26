#include "Request.h"

Request::Request(Student &student, UC &uc, string type) {
    this->student = student;
    this->uc = uc;
    this->type = type;
}

Student Request::getStudent() {
    return this->student;
}

UC Request::getUC(){
    return this->uc;
}

string Request::getType() {
    return this->type;
}