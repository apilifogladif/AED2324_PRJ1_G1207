#include "AuxiliarFunctions.h"
#include <algorithm>
#include <map>
#include <iostream>
#include "CsvAndVectors.h"

// O(1)
AuxiliarFunctions::AuxiliarFunctions() = default;

// O(n)
Student AuxiliarFunctions::retStudent(const string &studentCode) {
    CsvAndVectors CSVInfo;
    vector<Student> students = CSVInfo.getStudentsVector();
    for (auto &student : students) {
        if (student.getStudentCode() == studentCode) {
            return student;
        }
    }
    return Student();
}

// O(1)
void AuxiliarFunctions::concludeEnrollment(Student student, UC UcClass) {
    enrollmentRequests.emplace(&student, &UcClass, "Enrollment");
}

// O(1)
void AuxiliarFunctions::concludeRemoval(Student student, UC UcClass) {
    removalRequests.emplace(&student, &UcClass, "Removal");
}

// O(1)
void AuxiliarFunctions::concludeSwitch(Student student, UC UcClass) {
    switchRequests.emplace(&student, &UcClass, "Switch");
}

// O(n)
bool AuxiliarFunctions::lessonOverlap(UC uc1, UC uc2){
    if (uc1.hasSameUcCode(uc2)) {
        return false;
    }
    Schedule class1 = Schedule(uc1);
    Schedule class2 = Schedule(uc2);
    for (Lesson l1 : class1.getLesson()) {
        for (const Lesson& l2 : class2.getLesson()) {
            if (l1.lessonOverlap(l2)) {
                return true;
            }
        }
    }
    return false;
}

// O(n)
vector<Student> AuxiliarFunctions::UcStudents(const string& UcCode) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    vector<Student> students;
    for (const Student& s : schedule.getStudents()) students.push_back(s);
    return students;
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

vector<Schedule> AuxiliarFunctions::UcClasses(const string& UcCode) {
    vector<Schedule> classes;
    for (Schedule class_: schedules) {
        if (class_.getUcClass().getUcCode() == UcCode) {
            classes.push_back(class_);
        }
    }
    return classes;
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
        rejectedRequests.emplace_back(request, "The balance of class occupation is not maintained./n The difference between the number of students in the class can't be less than or equal to 4.");
    } else if (requestConflict(request)) {
        rejectedRequests.emplace_back(request, "There is conflict between the student’s schedule and the new class’s schedule.");
    } else if (requestMax(request)) {
        rejectedRequests.emplace_back(request, "The capacity of the class has been exceeded.");
    } else {
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        UC uc_old = student.changeUC(uc);
        Schedule(request.getUC()).addStudent(student);
        Schedule(uc_old).removeStudent(student);
    }
    cout << endl;
}

void AuxiliarFunctions::verifyEnrollmentRequest(Request &request) {
    if (requestConflict(request)) {
        rejectedRequests.emplace_back(request, "There is conflict between the student’s schedule and the new class’s schedule.");
    } else if (requestMax(request)) {
        rejectedRequests.emplace_back(request, "The capacity of the class has been exceeded.");
    } else {
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        student.addUC(uc);
        Schedule(uc).addStudent(student);
    }
    cout << endl;
}

void AuxiliarFunctions::verifyRemovalRequest(Request &request) {
    Student student = retStudent(request.getStudent().getStudentCode());
    UC uc = Schedule(request.getUC()).getUcClass();
    student.removeUC(uc);
    Schedule(uc).removeStudent(student);
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
    Schedule schedule = Schedule(StudentCode);
    schedule.drawSchedule();
    cout << endl;
}

void AuxiliarFunctions::seeClassSchedule(const string& ClassCode) {
    Schedule schedule = Schedule(UC("", ClassCode));
    schedule.drawSchedule();
    cout << endl;
}

void AuxiliarFunctions::seeUcSchedule(const string& UcCode) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    schedule.drawSchedule();
    cout << endl;
}

void AuxiliarFunctions::seeClassStudents(const UC& UcClass, const int& sort_) {
    Schedule schedule = Schedule(UcClass);
    cout << "Students enrolled: \n";
    schedule.sortStudents(sort_);
    cout << endl;
}

void AuxiliarFunctions::seeUcStudents(const string& UcCode, const int& sort_) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    cout << "Students enrolled: \n";
    schedule.sortStudents(sort_);
    cout << endl;
}

void AuxiliarFunctions::seeYearStudents(int year, int sort_) {
    CsvAndVectors CSVInfo;
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();
    vector<Student> students;
    for (auto &student : StudentsVector) {
        int y = 0;
        for (auto &uc : student.getUCs()) {
            char firstChar = uc.getClassCode()[0];
            if (firstChar > y) y = static_cast<int>(firstChar) - 48;    //ASCII
        }
        if (y == year) students.push_back(student);
    }
    if (sort_ == 1) {
        sort(students.begin(), students.end(), [](Student &A, Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == 2) {
        sort(students.rbegin(), students.rend(), [](Student &A, Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == 3) {
        sort(students.begin(), students.end());
    } else if (sort_ == 4) {
        sort(students.rbegin(), students.rend());
    }
    for (const Student& student: students) {
        cout << student.getStudentCode() << " " << student.getStudentName() << endl;
    }
}

int AuxiliarFunctions::numberClassStudents(const UC &UcClass) {
    Schedule schedule = Schedule(UcClass);
    return schedule.getStudents().size();
}

int AuxiliarFunctions::numberUcStudents(const string &UcCode) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    return schedule.getStudents().size();
}

int AuxiliarFunctions::numberYearStudents(const int &Year) {
    CsvAndVectors CSVInfo;
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();
    vector<Student> students;
    for (auto &student : StudentsVector) {
        int y = 0;
        for (auto &uc : student.getUCs()) {
            char firstChar = uc.getClassCode()[0];
            if (firstChar > y) y = static_cast<int>(firstChar) - 48;    //ASCII
        }
        if (y == Year) students.push_back(student);
    }
    return students.size();
}



