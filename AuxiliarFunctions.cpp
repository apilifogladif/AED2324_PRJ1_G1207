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


AuxiliarFunctions::AuxiliarFunctions() = default;

Student AuxiliarFunctions::retStudent(const string &studentCode) {
    CsvAndVectors CSVInfo;
    vector<Student> students = CSVInfo.StudentsVector;
    for (auto &student : students) {
        if (student.getStudentCode() == studentCode) {
            return student;
        }
    }
    return {};
}

void AuxiliarFunctions::concludeEnrollment(const Student& student, const UC& UcClass) {
    enrollmentRequests.emplace(student, UcClass, "Enrollment");
}

void AuxiliarFunctions::concludeRemoval(const Student& student, const UC& UcClass) {
    removalRequests.emplace(student, UcClass, "Removal");
}

void AuxiliarFunctions::concludeSwitch(const Student& student, const UC& oldUc, const UC& newUc) {
    Request request = Request(student, newUc, "Switch");
    request.setoldUC(oldUc);
    switchRequests.emplace(request);
}

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

int AuxiliarFunctions::totalNumberOfRejectedRequests() {
    return rejectedRequests.size();
}

int AuxiliarFunctions::totalNumberOfAcceptedRequests() {
    return acceptedRequests.size();
}

UC AuxiliarFunctions::getCurrentClass(Request &request) {
    return request.getStudent().findUc(request.getUC().getUcCode());
}

bool AuxiliarFunctions::requestBalance(Request &request) {
    CsvAndVectors CSVInfo;
    AuxiliarFunctions func;
    vector<pair<string, set<string>>> ClassesPerUcVector = CSVInfo.ClassesPerUcVector;
    string UcCode = request.getUC().getUcCode();
    int new_oc = func.numberClassStudents(request.getUC());
    int aux;

    for (pair<string, set<string>> p : ClassesPerUcVector) {
        if (p.first == UcCode) {
            for (string Class : p.second) {
                aux = func.numberClassStudents(UC(UcCode, Class));
                if (new_oc - aux > 4) return false;
            }
        }
    }
    return true;
}

bool AuxiliarFunctions::requestConflict(Request &request) {
    UC uc = request.getUC();
    Student student = request.getStudent();
    vector<UC> studentUCs = student.getUCs();
    for (UC& uc_ : studentUCs) {
        if (!(uc_ == request.getoldUC()) && lessonOverlap(uc_, uc)) {
            return true;
        }
    }
    return false;
}

vector<Schedule> AuxiliarFunctions::UcClasses(const string &UcCode) {
    vector<Schedule> classes;
    for (Schedule &class_: schedules) {
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

void AuxiliarFunctions::verifySwapRequest(Request &request){
    if (!(requestBalance(request))) {
        request.setReason("The balance of class occupation is not maintained./n The difference between the number of students in the class can't be less than or equal to 4.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    } else if (requestConflict(request)) {
        request.setReason("There is conflict between the student’s schedule and the new class’s schedule.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    } else if (requestMax(request)) {
        request.setReason("The capacity of the class has been exceeded.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else {
        request.setStatus("Accepted");
        Student student = request.getStudent();
        UC uc = request.getUC();
        UC uc_old = request.getoldUC();
        student.removeUC(uc_old);
        student.addUC(uc);
        acceptedRequests.push_back(request);
    }
    allRequests.push_back(request);
}

void AuxiliarFunctions::verifyEnrollmentRequest(Request &request) {
    if (requestConflict(request)) {
        request.setReason("There is conflict between the student’s schedule and the new class’s schedule.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (requestMax(request)) {
        request.setReason("The capacity of the class has been exceeded.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else {
        request.setStatus("Accepted");
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        student.addUC(uc);
        Schedule(uc).addStudent(student);
        acceptedRequests.push_back(request);
    }
    allRequests.push_back(request);
}

void AuxiliarFunctions::verifyRemovalRequest(Request &request) {
    if (!(requestBalance(request))) {
        request.setReason("The balance of class occupation is not maintained./n The difference between the number of students in the class can't be less than or equal to 4.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    } else {
        request.setStatus("Accepted");
        Student student = retStudent(request.getStudent().getStudentCode());
        UC uc = Schedule(request.getUC()).getUcClass();
        student.removeUC(uc);
        Schedule(uc).removeStudent(student);
        acceptedRequests.push_back(request);
    }
    allRequests.push_back(request);
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

    CsvAndVectors CSVInfo;
    CSVInfo.setFromRequestVector();
}

void AuxiliarFunctions::seeRejectedRequests() {
    if (rejectedRequests.size() == 0) cout << "There are no rejected requests." << endl;
    for (auto i: rejectedRequests) {
        i.printRequest();
        cout << " , reason:" << i.getReason() << endl;
    }
}

void AuxiliarFunctions::seeAcceptedRequests() {
    if (acceptedRequests.size() == 0) cout << "There are no accepted requests." << endl;
    for (auto i: acceptedRequests) {
        i.printRequest();
        cout << endl;
    }

}

void AuxiliarFunctions::seeAllRequests() {
    if (allRequests.size() == 0) cout << "There are no requests." << endl;
    for (auto i: allRequests) {
        i.printRequest();
        cout << " - " << i.getStatus();
        if (i.getStatus() == "Rejected") cout << ", reason: " << i.getReason();
        cout << endl;
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
    vector<Student> StudentsVector = CSVInfo.StudentsVector;
    set<Student> students;
    for (auto &student : StudentsVector) {
        char y = '0';
        char aux;
        for (auto &uc : student.getUCs()) {
            aux = uc.getClassCode()[0];
            if (aux > y) y = aux;
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

int AuxiliarFunctions::numberClassStudents(const UC &UcClass) {
    Schedule schedule = Schedule(UcClass);
    return schedule.getStudents().size();
}

int AuxiliarFunctions::numberUcStudents(const string &UcCode) {
    Schedule schedule = Schedule(UC(UcCode, ""));
    return schedule.getStudents().size();
}

int AuxiliarFunctions::numberYearStudents(char &Year) {
    CsvAndVectors CSVInfo;
    vector<Student> StudentsVector = CSVInfo.StudentsVector;
    int count = 0;
    for (auto &student : StudentsVector) {
        char y = 0;
        for (auto &uc : student.getUCs()) {
            char aux = uc.getClassCode()[0];
            if (aux > y) y = aux;
        }
        if (y == Year) count++;
    }
    return count;
}

void AuxiliarFunctions::getRequests() {
    CsvAndVectors CSVInfo;
    allRequests = CSVInfo.RequestsVector;
    for (Request r : allRequests) {
        if (r.getStatus() == "Accepted") acceptedRequests.push_back(r);
        else rejectedRequests.push_back(r);
    }
}
