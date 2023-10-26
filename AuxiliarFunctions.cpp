#include "AuxiliarFunctions.h"

Student* AuxiliarFunctions::findStudent(string studentCode) {
    auto student = students.find(Student(studentCode, ""));
    if (student != student.end()) {
        return &(*student);
    } else {
        return nullptr;
    }
}

Schedule* AuxiliarFunctions::UCSchedule(UC UcClass) {
    unsigned long ucIdx = binarySearch(UcClass);
    if (ucIdx == -1) {
        return nullptr;
    } else {
        return &(*schedules[ucIdx]);
    }
}

unsigned long AuxiliarFunctions::binarySearch(UC UcClass) {
    return binarySearchAux(UcClass, 0, schedules.size());
}
unsigned long AuxiliarFunctions::binarySearchAux(UC UcClass, unsigned long left, unsigned long right) {
    if (left > right) {
        return -1; // not found
    }
    unsigned long middle = left + right / 2;
    if (schedules[middle].getUcClass() == UcClass) {
        return middle;
    } else if (schedules[middle].getUcClass() < UcClass) { // upper half
        return binarySearchAux(UcClass, middle + 1, right);
    } else {
        return binarySearchAux(UcClass, left, middle - 1); // lower half
    }
}

void AuxiliarFunctions::concludeEnrollment(Student student, UC UcClass) {
    enrollmentRequests.push(Request(student, UcClass, "Enrollment"));
}

void AuxiliarFunctions::concludeRemoval(Student student, UC UcClass) {
    removalRequests.push(Request(student, UcClass, "Removal"));
}

void AuxiliarFunctions::concludeSwitch(Student student, UC UcClass) {
    switchRequests.push(Request(student, UcClass, "Switch"));
}

bool AuxiliarFunctions::requestMax(Request request);

bool AuxiliarFunctions::requestConflict(Request request);

bool AuxiliarFunctions::requestBalance(Request request);

bool AuxiliarFunctions::lessonOverlap(UC uc1, UC uc2){
    if (uc1.hasSameUcCode(uc2)) {
        return false;
    }
    Schedule* class1 = UCSchedule(uc1);
    Schedule* class2 = UCSchedule(uc2);
    for (Lesson l1 : class1->getLesson()) {
        for (Lesson l2 : class2->getLesson()) {
            if (l1.lessonOverlap(l2)) {
                return true;
            }
        }
    }
}
