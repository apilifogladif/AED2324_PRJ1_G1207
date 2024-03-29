#include "Schedule.h"
#include "Student.h"
#include "AuxiliarFunctions.h"
#include "CsvAndVectors.h"
#include <algorithm>
#include <utility>

Schedule::Schedule() = default;

Schedule::Schedule(UC ucClass) {
    this->UcClass = std::move(ucClass);
    this->loadLessonsUcClass();
    this->loadStudents();
}

Schedule::Schedule(const string& StudentCode) {
    this->student = AuxiliarFunctions::retStudent(StudentCode);
    this->loadLessonsStudent();
}

void Schedule::loadLessonsUcClass() {

    // get lessons from this ucClass(UcCode, ClassCode)
    for (auto &lesson: CsvAndVectors::LessonsVector) {
        if (lesson.getUc() == this->UcClass) {
            this->lessons.insert(lesson);
        }
            // if the user wants the schedule of an uc
        else if (lesson.getUc().getUcCode() == this->UcClass.getUcCode() && this->UcClass.getClassCode().empty()) {
            this->lessons.insert(lesson);
        }
            // if the user wants the schedule of a class
        else if (lesson.getUc().getClassCode() == this->UcClass.getClassCode() && this->UcClass.getUcCode().empty()) {
            this->lessons.insert(lesson);
        }
    }
}

void Schedule::loadLessonsStudent() {

    for (auto &uc: this->student.getUCs()) {
        for (auto &lesson : CsvAndVectors::LessonsVector) {
            if (uc == lesson.getUc()) {
                this->lessons.insert(lesson);
            }
        }
    }
}

void Schedule::loadStudents() {

    // get students from this ucClass(UcCode, ClassCode)
    for (auto &student_: CsvAndVectors::StudentsVector) {
        for (auto &uc : student_.getUCs()) {
            if (uc == this->UcClass) {
                this->students.insert(student_);
            }
                // if the user wants the schedule of an uc
            else if (uc.getUcCode() == this->UcClass.getUcCode() && this->UcClass.getClassCode().empty()) {
                this->students.insert(student_);
            }
                // if the user wants the schedule of a class
            else if (uc.getClassCode() == this->UcClass.getClassCode() && this->UcClass.getUcCode().empty()) {
                this->students.insert(student_);
            }
        }
    }
}

set<Lesson> Schedule::getLesson() const {
    return this->lessons;
}

void Schedule::drawSchedule() const {
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    bool exists = false;
    for (const string& day : v) {
        exists = false;
        cout << day << "\n";
        for (const Lesson& l: this->lessons) {
            if (l.getWeekday() == day) {
                l.drawLesson();
                exists = true;
            }
        }
        if (!exists) cout << ">> There is no lessons in this day." << endl;
        cout << endl;
    }
}

UC Schedule::getUcClass() {
    return this->UcClass;
}

set<Student> Schedule::getStudents() {
    return this->students;
}

bool Schedule::operator<(Schedule schedule) {
    return this->UcClass < schedule.getUcClass();
}

void Schedule::sortStudents(const int &sort_) {
    vector<Student> sorted = vector<Student>(students.begin(), students.end());
    if (sort_ == 1) {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentName() < B.getStudentName();
        });
    } else if (sort_ == 2) {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentName() > B.getStudentName();
        });
    } else if (sort_ == 3) {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentCode() > B.getStudentCode();
        });
    } else if (sort_ == 4) {
        sort(sorted.begin(), sorted.end(), [](Student &A, Student &B) {
            return A.getStudentCode() < B.getStudentCode();
        });
    }

    for (const Student& student: sorted) {
        cout << student.getStudentCode() << "; " << student.getStudentName() << endl;
    }
}
