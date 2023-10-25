#include "Request.h"

// constructor of the Request class
Request::Request(Student &student, UC &uc, string type) {
    this->student = student;
    this->uc = uc;
    this->type = type;
}

// returns the student that made the request
Student Request::getStudent() {
    return this->student;
}

// return the UC class that the student wants to be in
UC Request::getUC(){
    return this->uc;
}

// return the type of the request
string Request::getType() {
    return this->type;
}

// allocate to each type which function it must use (Enrollment - add method, Removal - remove method, Swap - swap method)
void Request::typeAllocation(string type_) {
    if (this->type == "Enrollment") {
        this->add(type_);
    } else if (this->type == "Removal") {
        this->remove(type_);
    } else if (this->type == "Swap") {
        this->swap(type_);
    }
    // else { invalid }
}

uc* Request::getUCi() {
    return this->UCi_ptr;
}

// adds a student to a lesson
// a student cannot be registered in more than 7 UCs at any given time -> doubt : what is the maximum number of students in a class
// there must be at least one class with a vacancy in the new UC
bool Request::add(string type_) {
    // The resulting schedule will not conflict with the student’s original schedule.

    if (this->student.getUCs().size() > 7) {
        cout << this->student->getStudentName() << "is already enrolled in 6 classes.";
        this->type_;
        return false;
    }
}
void remove(string type_);
void swap(string type_);