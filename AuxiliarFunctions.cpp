#include "AuxiliarFunctions.h"
#include <algorithm>
#include <map>

// erro por resolver
Student* AuxiliarFunctions::retStudent(const string &studentCode) const{
    auto student = students.find(Student(studentCode, ""));
    if (student != students.end()) {
        return const_cast<Student*>(&(*student));
    } else {
        return nullptr;
    }
}

Schedule* AuxiliarFunctions::UCSchedule(UC UcClass) {
    unsigned long ucIdx = binarySearch(UcClass);
    if (ucIdx == -1) {
        return nullptr;
    }
    return &(schedules[ucIdx]);
    // const_cast<Schedule*>(&schedules[ucIdx]) se não der bem
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
    enrollmentRequests.push(Request(&student, &UcClass, "Enrollment"));
}

void AuxiliarFunctions::concludeRemoval(Student student, UC UcClass) {
    removalRequests.push(Request(&student, &UcClass, "Removal"));
}

void AuxiliarFunctions::concludeSwitch(Student student, UC UcClass) {
    switchRequests.push(Request(&student, &UcClass, "Switch"));
}

vector<Schedule> AuxiliarFunctions::UcClasses(string UcCode) {
    vector<Schedule> classes;
    for (Schedule class_ : schedules) {
        if (class_.getUcClass().getUcCode() == UcCode) {
            classes.push_back(class_);
        }
    }
}

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

int AuxiliarFunctions::totalNumberOfStudentsUcClass(UC UcClass) {
    int numberStudents = UCSchedule(UcClass)->getStudents().size();
    return numberStudents;
}

UC AuxiliarFunctions::getCurrentClass(Request &request) {
    return request.getStudent().findUc(request.getUC().getUcCode());
}
bool AuxiliarFunctions::requestBalance(Request &request) {
    int currentClass = totalNumberOfStudentsUcClass(getCurrentClass(request));
    int newClass = totalNumberOfStudentsUcClass(request.getUC());
    if ((newClass - currentClass) <= 4) {
        return true;
    } else {
        return false;
    }
}

bool AuxiliarFunctions::requestConflict(Request &request) {
    UC uc = request.getUC();
    Student student = request.getStudent();
    vector<UC> studentUCs = student.getUCs();
    for (UC uc_ : studentUCs) {
        if (lessonOverlap(uc_, uc)) {
            return true;
        } else {
            return false;
        }
    }
}

bool AuxiliarFunctions::requestMax(Request &request) {
    vector<Schedule> UcClasses_ = UcClasses(request.getUC().getUcCode());
    sort(UcClasses_.begin(), UcClasses_.end(), [](Schedule &class1, Schedule &class2) {
        return class1.getStudents().size() < class2.getStudents().size();
    });
    int max = UcClasses_.back().getStudents().size();
    if (UcClasses_[0].getStudents().size() == max) {
       max++;
    }
    if (max < totalNumberOfStudentsUcClass(request.getUC())) {
        return true;
    } else {
        return false;
    }
}

// completar descrições
void AuxiliarFunctions::verifySwapRequest(Request &request){
    if (!(requestBalance(request))) {
        rejectedRequests.emplace_back(request, "Unbalaced");
    } else if (requestConflict(request)) {
        rejectedRequests.emplace_back(request, "Conflict");
    } else if (requestMax(request)) {
        rejectedRequests.emplace_back(request, "Max");
    } else {
        Student* student = retStudent(request.getStudent().getStudentCode());
        UC uc = UCSchedule(request.getUC())->getUcClass();
        UC uc_old = student->changeUC(uc);
        UCSchedule(request.getUC())->addStudent(*student);
        UCSchedule(uc_old)->removeStudent(*student);
    }
    cout << endl;
}

void AuxiliarFunctions::verifyEnrollmentRequest(Request &request) {
    if (requestConflict(request)) {
        rejectedRequests.emplace_back(request, "Conflict");
    } else if (requestMax(request)) {
        rejectedRequests.emplace_back(request, "Max");
    } else {
        Student* student = retStudent(request.getStudent().getStudentCode());
        UC uc = UCSchedule(request.getUC())->getUcClass();
        student->addUC(uc);
        UCSchedule(uc)->addStudent(*student);
    }
    cout << endl;
}

void AuxiliarFunctions::verifyRemovalRequest(Request &request) {
    Student* student = retStudent(request.getStudent().getStudentCode());
    UC uc = UCSchedule(request.getUC())->getUcClass();
    student->removeUC(uc);
    UCSchedule(uc)->removeStudent(*student);
}
