#include "AuxiliarFunctions.h"
#include <algorithm>
#include <iostream>
#include "CsvAndVectors.h"

queue<Request> AuxiliarFunctions::enrollmentRequests;
queue<Request> AuxiliarFunctions::removalRequests;
queue<Request> AuxiliarFunctions::switchRequests;
vector<Request> AuxiliarFunctions::rejectedRequests;
vector<Request> AuxiliarFunctions::acceptedRequests;
vector<Request> AuxiliarFunctions::allRequests;

// O(1)
AuxiliarFunctions::AuxiliarFunctions() = default;

// O(n), where n is the number of students in the vector of students
Student AuxiliarFunctions::retStudent(const string &studentCode) {
    CsvAndVectors CSVInfo;
    vector<Student> students = CSVInfo.getStudentsVector();
    for (auto &student : students) {
        if (student.getStudentCode() == studentCode) {
            return student;
        }
    }
    return {};
}

// O(1)
void AuxiliarFunctions::concludeEnrollment(const Student& student, const UC& UcClass) {
    enrollmentRequests.emplace(student, UcClass, "Enrollment");
}

// O(1)
void AuxiliarFunctions::concludeRemoval(const Student& student, const UC& UcClass) {
    removalRequests.emplace(student, UcClass, "Removal");
}

// O(1)
void AuxiliarFunctions::concludeSwitch(const Student& student, const UC& UcClass) {
    switchRequests.emplace(student, UcClass, "Switch");
}

// O(log n) + O(mk) where n is the number of lines in classes_per_uc.csv, m is the number of lessons of the first class and k is the number of lessons of the second class
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

// O(1)
int AuxiliarFunctions::totalNumberOfRejectedRequests() {
    return rejectedRequests.size();
}

// O(1)
int AuxiliarFunctions::totalNumberOfAcceptedRequests() {
    return acceptedRequests.size();
}
// O(m), where m is the number of classes associated in
UC AuxiliarFunctions::getCurrentClass(Request &request) {
    return request.getStudent().findUc(request.getUC().getUcCode());
}

// O(log n), where n is the number of schedules / lines in 'classes_per_uc.csv'
bool AuxiliarFunctions::requestBalance(Request &request) {
    int currentClass = numberClassStudents(getCurrentClass(request));
    int newClass = numberClassStudents(request.getUC());
    if ((newClass - currentClass) <= 4) return true;
    return false;
}

// O(m log n + m*kl) : where m is the number of classes the student is in, n is the number of lines in classes_per_uc.csv, k is the number of lessons of the first class and l is the number of lessons of the second class
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

// O(n), where n is the number of schedules / lines in 'classes_per_uc.csv'
vector<Schedule> AuxiliarFunctions::UcClasses(const string &UcCode) {
    vector<Schedule> classes;
    for (Schedule &class_: schedules) {
        if (class_.getUcClass().getUcCode() == UcCode) {
            classes.push_back(class_);
        }
    }
    return classes;
}

// O(n log n), where n is the number of schedules / lines in 'classes_per_uc.csv'
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

// O(m log n + m*kl) + O(nlog n): where m is the number of classes the student is in, n is the number of schedules / lines in 'classes_per_uc,csv', k is the number of lessons of the first class and l is the number of lessons of the second class
void AuxiliarFunctions::verifySwapRequest(Request &request){
    if (!(requestBalance(request))) {
        request.setReason("The balance of class occupation is not maintained./n The difference between the number of students in the class can't be less than or equal to 4.");
        request.setStatus("rejected");
        rejectedRequests.push_back(request);
    } else if (requestConflict(request)) {
        request.setReason("There is conflict between the student’s schedule and the new class’s schedule.");
        request.setStatus("rejected");
        rejectedRequests.push_back(request);
    } else if (requestMax(request)) {
        request.setReason("The capacity of the class has been exceeded.");
        request.setStatus("rejected");
        rejectedRequests.push_back(request);
    } else {
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        UC uc_old = student.changeUC(uc);
        Schedule(request.getUC()).addStudent(student);
        Schedule(uc_old).removeStudent(student);
    }
    cout << endl;
}

// O(m log n + m*kl) + O(nlog n): where m is the number of classes the student is in, n is the number of schedules / lines in 'classes_per_uc,csv', k is the number of lessons of the first class and l is the number of lessons of the second class
void AuxiliarFunctions::verifyEnrollmentRequest(Request &request) {
    if (requestConflict(request)) {
        request.setReason("There is conflict between the student’s schedule and the new class’s schedule.");
        request.setStatus("rejected");
        rejectedRequests.push_back(request);
    } else if (requestMax(request)) {
        request.setReason("The capacity of the class has been exceeded.");
        request.setStatus("rejected");
        rejectedRequests.push_back(request);
    } else {
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        student.addUC(uc);
        Schedule(uc).addStudent(student);
    }
    cout << endl;
}

// O(m log n + m*kl) + O(nlog n): where m is the number of classes the student is in, n is the number of schedules / lines in 'classes_per_uc,csv', k is the number of lessons of the first class and l is the number of lessons of the second class
void AuxiliarFunctions::verifyRemovalRequest(Request &request) {
    if (!(requestBalance(request))) {
        request.setReason("The balance of class occupation is not maintained./n The difference between the number of students in the class can't be less than or equal to 4.");
        request.setStatus("rejected");
        rejectedRequests.push_back(request);
    } else {
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        student.removeUC(uc);
        Schedule(uc).removeStudent(student);
    }
}

// O(m) + O(log n * log n) + O(log k) + O(t log n + t*pl) + O(nlog n) where m is the number of classes of the student who is submitting the request,
// n is the number of schedules / lines in 'classes_per_uc.csv',
// k is the number of lines in 'students.csv'
// t is the number of classes the student is in
// p is the number of lessons of the first class and l is the number of lessons in the second class
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

    if (!rejectedRequests.empty()) {
        seeRejectedRequests();
    } else {
        cout << endl;
        cout << "All pending requests were accepted." << endl;
    }

}

// O(m), where m is the number of rejected requests
void AuxiliarFunctions::seeRejectedRequests() {
    for (auto i: rejectedRequests) {
        i.printRequest();
        cout << " , reason:" << i.getReason();
    }
}

// O(m), where m is the number of accepted requests
void AuxiliarFunctions::seeAcceptedRequests() {
    for (auto i: acceptedRequests) i.printRequest();
}

// O(m), where m is the number of all requests done
void AuxiliarFunctions::seeAllRequests() {
    for (auto i: allRequests) {
        i.printRequest();
        cout << i.getStatus();
        if (i.getStatus() == "Rejected") cout << " - " << i.getReason();
    }
}

// O(n) + O(lk), where n is the total number of students and lessons, l is the lesson in the student's schedule and k is the days of the week
void AuxiliarFunctions::seeStudentSchedule(const string& StudentCode) const {
    Schedule schedule = Schedule(StudentCode);
    schedule.drawSchedule();
    cout << endl;
}

// O(n) + O(lk), where n is the total number of students and lessons, l is the lesson in the student's schedule and k is the days of the week
void AuxiliarFunctions::seeClassSchedule(const string& ClassCode) {
    Schedule schedule = Schedule(UC("", ClassCode));
    schedule.drawSchedule();
    cout << endl;
}

// O(n) + O(lk), where n is the total number of students and lessons, l is the lesson in the student's schedule and k is the days of the week
void AuxiliarFunctions::seeUcSchedule(const string& UcCode) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    schedule.drawSchedule();
    cout << endl;
}

// O(n) + O(q log q) where n is the number of lessons and students associated with that Class of that UC, q is the number of students in that Class of that UC
void AuxiliarFunctions::seeClassStudents(const UC& UcClass, const int& sort_) {
    Schedule schedule = Schedule(UcClass);
    cout << "Students enrolled: \n";
    schedule.sortStudents(sort_);
    cout << endl;
}

// O(n) + O(q log q) where n is the number of lessons and students associated with that UC code, q is the number of students in that UC
void AuxiliarFunctions::seeUcStudents(const string& UcCode, const int& sort_) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    cout << "Students enrolled: \n";
    schedule.sortStudents(sort_);
    cout << endl;
}

// O(n) + O(mk) + O(m) + O(m log m) where n is the number of students in students_classes.csv, m is the students and k is the UCs of each student
void AuxiliarFunctions::seeYearStudents(int year, int sort_) {
    CsvAndVectors CSVInfo;
    vector<Student> StudentsVector = CSVInfo.getStudentsVector();
    set<Student> students;
    for (auto &student : StudentsVector) {
        int y = 0;
        for (auto &uc : student.getUCs()) {
            char firstChar = uc.getClassCode()[0];
            if (firstChar > y) y = static_cast<int>(firstChar) - 48;    //ASCII
        }
        if (y == year) students.insert(student);
    }
    std::vector<Student> tempVector(students.begin(), students.end());

    if (sort_ == 1) {
        std::sort(tempVector.begin(), tempVector.end(), [](const Student &A, const Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == 2) {
        sort(tempVector.begin(), tempVector.end(), [](Student &A, Student &B) {
            return A.getStudentName() > B.getStudentName();
        });
    } else if (sort_ == 3) {
        sort(tempVector.begin(), tempVector.end(), [](Student &A, Student &B) {
            return A.getStudentCode() > B.getStudentCode();
        });
    } else if (sort_ == 4) {
        sort(tempVector.begin(), tempVector.end(), [](Student &A, Student &B) {
            return A.getStudentCode() < B.getStudentCode();
        });
    }
    for (const Student& student: tempVector) {
        cout << student.getStudentCode() << " " << student.getStudentName() << endl;
    }
}

// O(m + l) + O(1) where m is the number of lessons and l is the number of student in a Class of an UC
int AuxiliarFunctions::numberClassStudents(const UC &UcClass) {
    Schedule schedule = Schedule(UcClass);
    return schedule.getStudents().size();
}

// O(m + l) where m is the number of lessons and l is the number of student in an UC
int AuxiliarFunctions::numberUcStudents(const string &UcCode) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    return schedule.getStudents().size();
}

// O(n) where n is the total number of students
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

// O(n) is the number of requests
void AuxiliarFunctions::getRequests() {
    CsvAndVectors CSVInfo;
    allRequests = CSVInfo.getRequestVector();
    for (Request r : allRequests) {
        if (r.getStatus() == "Accepted") acceptedRequests.push_back(r);
        else rejectedRequests.push_back(r);
    }
}
