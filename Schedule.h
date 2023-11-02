#ifndef AED2324_PRJ1_G1207_SCHEDULE_H
#define AED2324_PRJ1_G1207_SCHEDULE_H

#include "Lesson.h"
#include "UC.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>
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
        Schedule();
        /**
         * Class constructor
         *
         * Sets ucClass
         *
         * @param ucCLass: Class and Uc of the schedule;
         */
        Schedule(UC ucClass);

        /**
         * Class constructor
         *
         * Sets StudentCode
         *
         * @param StudentCode: Student Code;
         */
        Schedule(const string& StudentCode);

        /**
         * Adds a lesson to the schedule
         *
         * @param lesson : Lesson;
         */
        void addLesson(const Lesson& lesson);

        /**
         * Removes a lesson from the schedule
         *
         * @param lesson : Lesson;
         */
        void removeLesson(Lesson& lesson);

        /**
         * Returns a lesson from the schedule
         *
         * @return
         */
        set<Lesson> getLesson() const;

        /**
         * Prints the schedule
         */
        void drawSchedule() const;

        /**
         * Verifies if it has the same UcCode
         *
         * @param UcCode : Uc code;
         * @return
         */
        bool hasSameUcCode(Schedule &UcCode);

        /**
         * Returns the Uc class
         *
         * @return
         */
        UC getUcClass();

        /**
         * Get students of a class
         *
         * @return
         */
        set<Student> getStudents();

        /**
         * Adds student to a class
         *
         * @param student : student;
         */
        void addStudent(const Student& student);

        /**
         * Removes student from a class
         *
         * @param student : student;
         */
        void removeStudent(const Student& student);

        /**
         * Operator to compare two schedules
         *
         * @param schedule : shedule;
         * @return
         */
        bool operator<(Schedule schedule);

        /**
         * Prints UcCode and ClassCode
         */
        void printUcAndClass();

        /**
         * Sorts the students and prints them in the order that we asked for
         *
         * @param sort_ : Way to sort the students of the Uc;
         */
        void sortStudents(const int &sort_);
};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
