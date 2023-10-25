#include "Schedule.h"

// constructor of the Schedule class
Schedule::Schedule(set<Lesson> lessons) {
    this->lessons = lessons;
}

// adds a lesson to the schedule
void Schedule::addLesson(const Lesson lesson) {
    this->lessons.insert(lesson);
}

// removes a lesson from the schedule
void Schedule::removeLesson(const Lesson lesson) {
    this->lessons.erase(lesson);
}

// returns a lesson from the schedule
set<Lesson> Schedule::getLesson() const {
    return this->lesson;
}

// prints the schedule
void Schedule::drawSchedule() const {
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (string dia : v) {
        cout << day << "\n";
        for (Lesson l: this->lessons) {
            if (lesson.getWeekday() == dia) {
                l.drawLesson();
            }
        }
    }
}