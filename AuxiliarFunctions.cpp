#include "AuxiliarFunctions.h"

Student* AuxiliarFunctions::retStudent(string studentCode) {
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

int AuxiliarFunctions::totalNumberOfStudentsUcClass(UC UcClass) {
    int numberStudents = UCSchedule(UcClass)->getStudents().size();
    return numberStudents;
}
UC AuxiliarFunctions::getCurrentClass(Request request) {
    UC currentClass = request.getStudent().findUc(request.getUC().getUcCode());
    return currentClass;
}
bool AuxiliarFunctions::requestBalance(Request request) {
    int currentClass = totalNumberOfStudentsUcClass(getCurrentClass(request));
    int newClass = totalNumberOfStudentsUcClass(request.getUC());
    if ((newClass - currentClass) <= 4) {
        return true;
    } else {
        return false;
    }
}

bool AuxiliarFunctions::requestConflict(Request request) {
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

bool AuxiliarFunctions::requestMax(Request request) {
    vector<Schedule> totalUcsClasses = totalUcsClasses(request.getUC().getUcCode());
    sort(totalUcsClasses.begin(), totalUcsClasses.end(), [](const Schedule &class1, const Schedule &class2) {
        if (class1.getStudents().size() >= class2.getStudents().size()) {
            return false;
        } else {
            return true;
        }
    });
    int max = totalUcsClasses.back().getStudents().size();
    if (totalUcsClasses[0].getStudents().size() == max) {
       max++;
    }
    if (max < totalNumberOfStudentsUcClass(request.getUC())) {
        return true;
    } else {
        return false;
    }
}

// completar descrições
void AuxiliarFunctions::verifySwapRequest(Request request){
    if (!(requestBalance(request))) {
        rejectRequests.push_back(request, "Unbalaced");
    } else if (requestConflict(request)) {
        rejectRequests.push_back(request, "Conflict");
    } else if (requestMax(request)) {
        rejectRequests.push_back(request, "Max");
    } else {
        Student* student = retStudent(request.getStudent().getStudentCode());
        UC uc = UCSchedule(request.getUC())->getUcClass();
        UC uc_old = student->changeUC(UcClass);
        UCSchedule(request.getUC())->addStudent(*student);
        UCSchedule(uc_old)->removeStudent(*student);
    }
    cout << endl;
}
