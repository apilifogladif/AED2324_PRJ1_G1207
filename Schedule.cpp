#include "Schedule.h"
#include <algorithm>
#include <utility>

Schedule::Schedule(set<Lesson> lessons, UC ucClass) : UcClass(std::move(ucClass)) {
    this->lessons = std::move(lessons);
}

void Schedule::addLesson(const Lesson& lesson) {
    this->lessons.insert(lesson);
}

void Schedule::removeLesson(const Lesson& lesson) {
    this->lessons.erase(lesson);
}

set<Lesson> Schedule::getLesson() const {
    return this->lessons;
}

void Schedule::drawSchedule() const {
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (const string& day : v) {
        cout << day << "\n";
        for (const Lesson& l: this->lessons) {
            if (l.getWeekday() == day) {
                l.drawLesson();
            }
        }
    }
}

bool Schedule::hasSameUcCode(Schedule &UcCode) {
   return UcClass.getUcCode() == UcCode.getUcClass().getUcCode();
}

UC Schedule::getUcClass() {
    return this->UcClass;
}

set<Student> Schedule::getStudents() {
    return this->students;
}

void Schedule::addStudent(const Student& student) {
    students.insert(student);
}
void Schedule::removeStudent(const Student& student) {
    students.erase(student);
}

bool Schedule::operator<(Schedule schedule) {
    return this->UcClass < schedule.getUcClass();
}

void Schedule::printUcAndClass() {
    cout << UcClass.getUcCode() << " " << UcClass.getClassCode() << endl;
}

void Schedule::sortStudents(const string& sort_) {
    vector<Student> sorted = vector<Student>(students.begin(), students.end());
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