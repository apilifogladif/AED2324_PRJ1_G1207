#include "Schedule.h"

Schedule::Schedule(set<Lesson> lessons) {
    this->lessons = lessons;
}

void Schedule::addLesson(const Lesson lesson) {
    this->lessons.insert(lesson);
}

void Schedule::removeLesson(const Lesson lesson) {
    this->lessons.erase(lesson);
}

set<Lesson> Schedule::getLesson() const {
    return this->lessons;
}

void Schedule::drawSchedule() const {
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (string day : v) {
        cout << day << "\n";
        for (Lesson l: this->lessons) {
            if (l.getWeekday() == day) {
                l.drawLesson();
            }
        }
    }
}

bool Schedule::hasSameUcCode(Schedule UcCode) {
    if (UcClass.hasSameUcCode(UcCode.getUcClass())) {
        return true;
    } else {
        return false;
    }
}

UC Schedule::getUcClass() {
    return this->UcClass;
}

set<Student> Schedule::getStudents() {
    return this->students;
}

void Schedule::addStudent(Student student) {
    students.insert(student);
}
void Schedule::removeStudent(Student student) {
    students.erase(student);
}
