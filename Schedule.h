#ifndef AED2324_PRJ1_G1207_SCHEDULE_H
#define AED2324_PRJ1_G1207_SCHEDULE_H

#include "Lesson.h"
#include "UC.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <set>
#include "CsvAndVectors.h"

using namespace std;

// this class represents a schedule
class Schedule {
    private:
        set<Lesson> lessons;
        set<Student> students;
        UC UcClass;
        Student student;
    public:
        /**
         * Class constructor
         *
         * Sets lessons and students from a specific Class, Uc or Class and Uc
         *
         * @paramt ucCLass: Class and Uc of the schedule;
         */
        Schedule(UC ucClass);

        /**
         * Class constructor
         *
         * Sets lessons from a specific student
         *
         * @paramt StudentCode: Student Code;
         */
        Schedule(const string& StudentCode);

        /**
         * Adds a lesson to the schedule
         *
         * @paramt lesson : Lesson;
         */
        void addLesson(const Lesson& lesson);

        /**
         * Removes a lesson from the schedule
         *
         * @paramt lesson : Lesson;
         */
        void removeLesson(Lesson& lesson);

        /**
         * Returns a lesson from the schedule
         */
        set<Lesson> getLesson() const;

        /**
         * Prints the schedule
         */
        void drawSchedule() const;

        /**
         * Verifies if it has the same UcCode
         *
         * @paramt UcCode : Uc code;
         */
        bool hasSameUcCode(Schedule &UcCode);

        /**
         * Returns the Uc class
         */
        UC getUcClass();

        /**
         * Get students of a class
         */
        set<Student> getStudents();

        /**
         * Adds student to a class
         *
         * @paramt student : student;
         */
        void addStudent(const Student& student);

        /**
         * Removes student from a class
         *
         * @paramt student : student;
         */
        void removeStudent(const Student& student);

        /**
         * Operator to compare two schedules
         *
         * @paramt schedule : shedule;
         */
        bool operator<(Schedule schedule);

        /**
         * Prints UcCode and ClassCode
         */
        void printUcAndClass();

        /**
         * Sorts the students and prints them in the order that we asked for
         *
         * @paramt sort_ : Way to sort the students of the Uc;
         */
        void sortStudents(const string& sort_);
};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
