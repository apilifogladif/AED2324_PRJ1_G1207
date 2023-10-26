#include "AuxiliarFunctions.h"

Student* AuxiliarFunctions::findStudent(string studentCode){
    auto student = students.find(Student(studentCode, ""));
    if (student != student.end()) {
        return &(*student);
    } else {
        return nullptr;
    }
}