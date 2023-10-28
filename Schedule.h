#ifndef AED2324_PRJ1_G1207_SCHEDULE_H
#define AED2324_PRJ1_G1207_SCHEDULE_H

#include "Lesson.h"
#include "UC.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// this class represents a schedule
class Schedule {
    private:
        set<Lesson> lessons;
        set<Student> students;
        UC UcClass;
    public:
        /*
         * Class constructor
         *
         * Sets lessons
         *
         * @paramt lessons : private , Lessons to allocate to the students;
         */
        Schedule(set<Lesson> lessons, UC ucClass);

        /*
         * Adds a lesson to the schedule
         */
        void addLesson(const Lesson& lesson);

        /*
         * Removes a lesson from the schedule
         */
        void removeLesson(const Lesson& lesson);

        /*
         * Returns a lesson from the schedule
         */
        set<Lesson> getLesson() const;

        /*
         * Prints the schedule
         */
        void drawSchedule() const;

        /*
         * Verifies if it has the same UcCode
         */
        bool hasSameUcCode(Schedule &UcCode);

        /*
         * Returns the Uc class
         */
        UC getUcClass();

        /*
         * Get students of a class
         */
        set<Student> getStudents();

        /*
         * Adds student to a class
         */
        void addStudent(const Student& student);

        /*
         * Removes student from a class
         */
        void removeStudent(const Student& student);

        /*
         * Operator to compare two schedules
         */
        bool operator<(Schedule schedule);
        // prints UcCode and ClassCode
        void printUcAndClass();
        // sorts students and prints them in the order that we asked for
        void sortStudents(const string& sort_);
};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
