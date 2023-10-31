#include "AuxiliarFunctions.h"
#include <algorithm>
#include <map>
#include <utility>
#include <iostream>
#include "CsvAndVectors.h"

AuxiliarFunctions::AuxiliarFunctions() {}

Student* AuxiliarFunctions::retStudent(const string &studentCode) {
    CsvAndVectors CSVInfo;
    vector<Student> students = CSVInfo.getStudentsVector();
    for (auto &student : students) {
        if (student.getStudentCode() == studentCode) {
            return const_cast<Student*>(&student);
        }
    }
    return nullptr;
}

Schedule* AuxiliarFunctions::UCSchedule(const UC& UcClass) {
    unsigned long ucIdx = binarySearch(UcClass);
    if (ucIdx == -1) {
        return nullptr;
    }
    return &(schedules[ucIdx]);
    // const_cast<Schedule*>(&schedules[ucIdx]) se não der bem
}

unsigned long AuxiliarFunctions::binarySearch(const UC& UcClass) {
    return binarySearchAux(UcClass, 0, schedules.size());
}
unsigned long AuxiliarFunctions::binarySearchAux(const UC& UcClass, unsigned long left, unsigned long right) {
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
    enrollmentRequests.emplace(&student, &UcClass, "Enrollment");
}

void AuxiliarFunctions::concludeRemoval(Student student, UC UcClass) {
    removalRequests.emplace(&student, &UcClass, "Removal");
}

void AuxiliarFunctions::concludeSwitch(Student student, UC UcClass) {
    switchRequests.emplace(&student, &UcClass, "Switch");
}

vector<Schedule> AuxiliarFunctions::UcClasses(const string& UcCode) {
    vector<Schedule> classes;
    for (Schedule class_: schedules) {
        if (class_.getUcClass().getUcCode() == UcCode) {
            classes.push_back(class_);
        }
    }
    return classes;
}

bool AuxiliarFunctions::lessonOverlap(UC uc1, UC uc2){
    if (uc1.hasSameUcCode(uc2)) {
        return false;
    }
    Schedule* class1 = UCSchedule(uc1);
    Schedule* class2 = UCSchedule(uc2);
    for (Lesson l1 : class1->getLesson()) {
        for (const Lesson& l2 : class2->getLesson()) {
            if (l1.lessonOverlap(l2)) {
                return true;
            }
        }
    }
    return false;
}

vector<Student> AuxiliarFunctions::UcStudents(const string& UcCode) {
    vector<Student> UcStudents_;
    vector<Schedule> UcClasses_ = UcClasses(UcCode);
    for (Schedule schedule: UcClasses_) {
        for (const Student& student : schedule.getStudents()) {
            UcStudents_.push_back(student);
        }
    }
    return UcStudents_;
}

int AuxiliarFunctions::totalNumberOfPendingRequests() {
    return switchRequests.size() + enrollmentRequests.size() + removalRequests.size();
}


UC AuxiliarFunctions::getCurrentClass(Request &request) {
    return request.getStudent().findUc(request.getUC().getUcCode());
}
bool AuxiliarFunctions::requestBalance(Request &request) {
    int currentClass = numberClassStudents(getCurrentClass(request));
    int newClass = numberClassStudents(request.getUC());
    if ((newClass - currentClass) <= 4) return true;
    return false;
}

bool AuxiliarFunctions::requestConflict(Request &request) {
    UC uc = request.getUC();
    Student student = request.getStudent();
    vector<UC> studentUCs = student.getUCs();
    for (const UC& uc_ : studentUCs) {
        if (lessonOverlap(uc_, uc)) {
            return true;
        }
    }
    return false;
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
    if (max < numberClassStudents(request.getUC())) {
        return true;
    } else {
        return false;
    }
}

// completar descrições
void AuxiliarFunctions::verifySwapRequest(Request &request){
    if (!(requestBalance(request))) {
        rejectedRequests.emplace_back(request, "Unbalanced");
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

void AuxiliarFunctions::RequestsManager() {

    while (!(removalRequests.empty())) { // it has to be first
        Request request = removalRequests.front();
        removalRequests.pop();
        verifyRemovalRequest(request);
    }

    while (!(enrollmentRequests.empty())) {
        Request request = enrollmentRequests.front();
        enrollmentRequests.pop();
        verifyEnrollmentRequest(request);
    }

    while (!(switchRequests.empty())) {
        Request request = switchRequests.front();
        switchRequests.pop();
        verifySwapRequest(request);
    }

}

void AuxiliarFunctions::seePendingRequests() {
    while (!(removalRequests.empty())) {
        removalRequests.front().printRequest();
        removalRequests.pop();
    }
    while (!(switchRequests.empty())) {
        switchRequests.front().printRequest();
        switchRequests.pop();
    }
    while (!(enrollmentRequests.empty())) {
        enrollmentRequests.front().printRequest();
        enrollmentRequests.pop();
    }
}

void AuxiliarFunctions::seeRejectedRequests() {
    for (auto i: rejectedRequests) {
        i.request.printRequest();
        cout << " , reason:" << i.reason;
    }
}

void AuxiliarFunctions::seeStudentSchedule(const string& StudentCode) const {
    Student* student = retStudent(StudentCode);
    vector<UC> studentsClasses = student->getUCs();
    for (UC uc: studentsClasses) {
        Schedule sched = Schedule(uc);
        CsvAndVectors getInfo;
        for (Lesson lesson: getInfo.LessonsVector) {
            if (lesson.getUc() == uc) {
                sched.addLesson(lesson);
            }
        }
        sched.drawSchedule();
    }
}

// TODO
void AuxiliarFunctions::seeClassSchedule(const string& ClassCode) {

}

// TODO
void AuxiliarFunctions::seeUcSchedule(const string& UcCode) {

}

// TODO
void AuxiliarFunctions::seeLessonSchedule(UC uc) {

}

void AuxiliarFunctions::seeClassStudents(const UC& UcClass, const string& order_) {
    Schedule* schedule = UCSchedule(UcClass);
    cout << "Class " << UcClass.getClassCode() << ", UC " << UcClass.getUcCode() << endl;
    cout << "Students enrolled: \n";

    CsvAndVectors CSVInfo = CsvAndVectors();
    for (auto student: CSVInfo.getStudentsVector()) {
        for (UC uc: student.getUCs()) {
            if (uc == UcClass) {
                schedule->addStudent(student);
                break;
            }
        }
    }

    schedule->sortStudents(order_);
}

void AuxiliarFunctions::seeUcStudents(const string& UcCode, const string& sort_) {
    vector<Student> sorted = UcStudents(UcCode);
    if (sort_ == "A-Z order") {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == "Z-A order") {
        sort(sorted.rbegin(), sorted.rend(), [](Student &A, Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == "numerical") {
        sort(sorted.begin(), sorted.end());
    } else if (sort_ == "reverse numerical") {
        sort(sorted.rbegin(), sorted.rend());
    }
    for (const Student& student: sorted) {
        student.printUcAndClass();
    }
}

int AuxiliarFunctions::numberClassStudents(const UC &UcClass) {
    CsvAndVectors CSVInfo = CsvAndVectors();
    int count = 0;
    for (auto &student: CSVInfo.getStudentsVector()) {
        for (UC uc: student.getUCs()) {
            if (uc == UcClass) {
                count++;
            }
        }
    }
    return count;
}

int AuxiliarFunctions::numberUcStudents(const string &UcCode) {
    CsvAndVectors CSVInfo = CsvAndVectors();
    int count = 0;
    for (auto &student: CSVInfo.getStudentsVector()) {
        for (UC uc: student.getUCs()) {
            if (uc.getUcCode() == UcCode) {
                count++;
            }
        }
    }
    return count;
}

