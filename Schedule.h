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
/**
 * @file Schedule.h
 * @brief Class that represents a schedule
 */
class Schedule {
    private:
        set<Lesson> lessons;
        set<Student> students;  // when the schedule is the schedule of an UcClass, Uc or Class
        UC UcClass;
        Student student;        // when the schedule is the schedule of a student
    public:

        /**
         * @brief Schedule::Schedule
         * Class constructor
         *
         * Complexity: O(1)
         */
        Schedule();
        /**
         * @brief Schedule::Schedule
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param ucCLass: Class and Uc of the schedule.
         */
        Schedule(UC ucClass);

        /**
         * @brief Schedule::Schedule
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param StudentCode: The student code.
         */
        Schedule(const string& StudentCode);

        /**
         * @brief Schedule::loadLessonsUcClass
         * Set the private set lessons to the lessons of the UcClass, Uc or Class
         *
         * Complexity: O(n)  where n is the number of lessons in LessonsVector
         */
        void loadLessonsUcClass();

        /**
         * @brief Schedule::loadLessonsStudent
         * Set the private set lessons to the lessons of the Student
         *
         * Complexity: O(n*m)  where n is the number of Ucs of the Student and m is the number of lessons in LessonsVector
         */
        void loadLessonsStudent();

        /**
         * @brief Schedule::loadStudents
         * Set the private set students to the students of the UcClass, Uc or Class
         *
         * Complexity: O(n*m)  where n is the number of students in StudentsVector and m is the number of Ucs of each student
         */
        void loadStudents();

        /**
         * @brief Schedule::getLesson
         * Returns a lesson from the schedule
         *
         * Complexity: O(1)
         *
         * @return The lesson from the schedule.
         */
        set<Lesson> getLesson() const;

        /**
         * @brief Schedule::drawSchedule
         * Prints the schedule
         *
         * Complexity: O(n) where n is the number of lessons in the lessons set
         */
        void drawSchedule() const;

        /**
         * @brief Schedule::getUcClass
         * Returns the Uc class
         *
         * Complexity: O(1)
         *
         * @return The uc class.
         */
        UC getUcClass();

        /**
         * @brief Schedule::getStudents
         * Get students of a class
         *
         * Complexity: O(n)
         *
         * @return The students.
         */
        set<Student> getStudents();

        /**
         * @brief Schedule::operator<
         * Operator to compare two schedules
         *
         * Complexity: O(1)
         *
         * @param schedule : The schedule to compare to;
         * @return true or false.
         */
        bool operator<(Schedule schedule);

        /**
         * @brief Schedule::sortStudents
         * Sorts the students and prints them in the order that we asked for
         *
         * Complexity: O(n log n) where n is the number of students in the vector
         *
         * @param sort_ : Way to sort the students of the Uc.
         */
        void sortStudents(const int &sort_);
};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
