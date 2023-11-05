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
    for (auto &student : CsvAndVectors::StudentsVector) {
        if (student.getStudentCode() == studentCode) {
            return student;
        }
    }
    return {};
}

void AuxiliarFunctions::concludeEnrollment(const Student &student, const UC &UcClass) {
    enrollmentRequests.emplace(student, UcClass, "Enrollment");
    allRequests.push_back(Request(student, UcClass, "Enrollment"));
}

void AuxiliarFunctions::concludeRemoval(const Student &student, const UC &UcClass) {
    removalRequests.emplace(student, UcClass, "Removal");
    allRequests.push_back(Request(student, UcClass, "Removal"));
}

void AuxiliarFunctions::concludeSwitch(const Student &student, const UC &oldUc, const UC &newUc) {
    Request request = Request(student, newUc, "Switch");
    request.setoldUC(oldUc);
    switchRequests.emplace(request);
    allRequests.push_back(request);
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

bool AuxiliarFunctions::requestBalance(Request &request) {
    AuxiliarFunctions func;
    string UcCode = request.getUC().getUcCode();
    int new_oc = func.numberClassStudents(request.getUC());
    int aux;

    for (pair<string, set<string>> p : CsvAndVectors::ClassesPerUcVector) {
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
        cout << request.getoldUC().getUcCode() << endl;
        if (!(uc_ == request.getoldUC()) && lessonOverlap(uc_, uc)) {
            cout << uc_.getUcCode() << " && " << uc.getUcCode() << endl;
            return true;
        }
    }
    return false;
}

bool AuxiliarFunctions::requestMax(Request &request) {
    int Cap = 25;
    Schedule schedule = Schedule(UC(request.getUC()));
    if (schedule.getStudents().size() > Cap) return true;
    return false;
}

void AuxiliarFunctions::changeAllRequests(bool status, Request request) {
    for (int i = 0; i < allRequests.size(); i++) {
        if (request.getStudent() == allRequests[i].getStudent() && request.getUC() == allRequests[i].getUC() && request.getType() == allRequests[i].getType() &&
                allRequests[i].getStatus() == "") {
            if (status) allRequests[i].setStatus("Accepted");
            else {
                allRequests[i].setStatus("Rejected");
                allRequests[i].setReason(request.getReason());
            }
            break;
        }
    }
}

void AuxiliarFunctions::verifySwapRequest(Request &request){
    Student student = retStudent(request.getStudent().getStudentCode());
    bool status = false;
    if (!(requestBalance(request))) {
        request.setReason("The balance of class occupation is not maintained. The difference between the number of students in the class can't be less than or equal to 4.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (requestConflict(request)) {
        request.setReason("There is conflict between the student’s schedule and the new class’s schedule.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (requestMax(request)) {
        request.setReason("The capacity of the class has been exceeded.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (student.findUc(request.getUC().getUcCode()).getUcCode() != "") {
        request.setReason("This student is already enrolled in this Uc.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (student.findUc(request.getoldUC().getUcCode()).getUcCode() == "") {
        request.setReason("This student is not enrolled in this Uc.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else {
        request.setStatus("Accepted");
        UC uc = request.getUC();
        UC uc_old = request.getoldUC();
        student.removeUC(uc_old);
        student.addUC(uc);
        acceptedRequests.push_back(request);
        status = true;
    }
    changeAllRequests(status, request);
}

void AuxiliarFunctions::verifyEnrollmentRequest(Request &request) {
    Student student = retStudent(request.getStudent().getStudentCode());

    bool status = false;
    if (!(requestBalance(request))) {
        request.setReason("The balance of class occupation is not maintained. The difference between the number of students in the class can't be less than or equal to 4.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (requestConflict(request)) {
        request.setReason("There is conflict between the student’s schedule and the new class’s schedule.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (requestMax(request)) {
        request.setReason("The capacity of the class has been exceeded.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else if (student.findUc(request.getUC().getUcCode()).getUcCode() != "") {
        request.setReason("This student is already enrolled in this Uc.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else {
        request.setStatus("Accepted");
        UC uc = Schedule(request.getUC()).getUcClass();
        student.addUC(uc);
        acceptedRequests.push_back(request);
        status = true;
    }
    changeAllRequests(status, request);
}

void AuxiliarFunctions::verifyRemovalRequest(Request &request) {
    Student student = retStudent(request.getStudent().getStudentCode());
    bool status = false;
    if (student.findUc(request.getUC().getUcCode()).getUcCode() == "") {
        request.setReason("This student is not enrolled in this Uc.");
        request.setStatus("Rejected");
        rejectedRequests.push_back(request);
    }
    else {
        request.setStatus("Accepted");
        UC uc = Schedule(request.getUC()).getUcClass();
        student.removeUC(uc);
        acceptedRequests.push_back(request);
        status = true;
    }
    changeAllRequests(status, request);
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

    for (auto request : allRequests) {
        CsvAndVectors::RequestsVector.push_back(request);
    }
    allRequests.clear();
}

void AuxiliarFunctions::seeRejectedRequests() {
    bool exists = false;
    for (auto i: CsvAndVectors::RequestsVector) {
        if (i.getStatus() == "Rejected") {
            i.printRequest();
            cout << " , reason:" << i.getReason() << endl;
            exists = true;
        }
    }
    if (!exists) cout << "There are no rejected requests." << endl;
}

void AuxiliarFunctions::seeAcceptedRequests() {
    bool exists = false;
    for (auto i: CsvAndVectors::RequestsVector) {
        if (i.getStatus() == "Accepted") {
            i.printRequest();
            exists = true;
        }
    }
    if (!exists) cout << "There are no accepted requests." << endl;
}

void AuxiliarFunctions::seeAllRequests() {
    if (CsvAndVectors::RequestsVector.empty()) cout << "There are no requests." << endl;
    for (auto i: CsvAndVectors::RequestsVector) {
        i.printRequest();
        cout << " - " << i.getStatus();
        if (i.getStatus() == "Rejected") cout << ", reason: " << i.getReason();
        cout << endl;
    }
}

void AuxiliarFunctions::seeStudentSchedule(const string& StudentCode) {
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
    set<Student> students;
    for (auto &student : CsvAndVectors::StudentsVector) {
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
    int count = 0;
    for (auto &student : CsvAndVectors::StudentsVector) {
        char y = 0;
        for (auto &uc : student.getUCs()) {
            char aux = uc.getClassCode()[0];
            if (aux > y) y = aux;
        }
        if (y == Year) count++;
    }
    return count;
}
