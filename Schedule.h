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

        /**
         * Class constructor
         * O(1)
         */
        Schedule();
        /**
         * Class constructor
         * O(m) + O(n) + O(k) where m is the number of lessons and students in the vectors (LessonsVector and StudentVector),
         * n is the number of lessons in the LessonsVector and k is the number of students in the StudentsVector
         *
         * Sets ucClass
         *
         * @param ucCLass: Class and Uc of the schedule;
         */
        Schedule(UC ucClass);

        /**
         * Class constructor
         * O(n) + O(m) + O(k) + O(k*l) where n is the number of students in StudentsVector, m is the number of lessons in the LessonsVector,
         * k is the number of UCs and l is the lessons in the LessonsVector associated with the students

         *
         * Sets StudentCode
         *
         * @param StudentCode: Student Code;
         */
        Schedule(const string& StudentCode);

        /**
         * Adds a lesson to the schedule
         * O(log n) + O(m) where n is the number of lessons in the lessons set and m is the number of lessons in LessonsVector
         *
         * @param lesson : Lesson;
         */
        void addLesson(const Lesson& lesson);

        /**
         * Removes a lesson from the schedule
         * O(log n) + O(m) where n is the number of lessons in the lessons set and m is the number of lessons in LessonsVector
         *
         * @param lesson : Lesson;
         */
        void removeLesson(Lesson& lesson);

        /**
         * Returns a lesson from the schedule
         * O(1)
         *
         * @return
         */
        set<Lesson> getLesson() const;

        /**
         * Prints the schedule
         * O(n) where n is the number of lessons in the lessons set
         */
        void drawSchedule() const;

        /**
         * Verifies if it has the same UcCode
         * O(1)
         *
         * @param UcCode : Uc code;
         * @return bool : true or false
         */
        bool hasSameUcCode(Schedule &UcCode);

        /**
         * Returns the Uc class
         * O(1)
         *
         * @return UcClass
         */
        UC getUcClass();

        /**
         * Get students of a class
         * O(n)
         *
         * @return students
         */
        set<Student> getStudents();

        /**
         * Adds student to a class
         * O(log n) where n is the number of students already in the set
         *
         * @param student : student;
         */
        void addStudent(const Student& student);

        /**
         * Removes student from a class
         * O(log n) where n is the number of students already in the set
         *
         * @param student : student;
         */
        void removeStudent(const Student& student);

        /**
         * Operator to compare two schedules
         * O(1)
         *
         * @param schedule : schedule;
         * @return bool : true or false
         */
        bool operator<(Schedule schedule);

        /**
         * Prints UcCode and ClassCode
         * O(1)
         */
        void printUcAndClass();

        /**
         * Sorts the students and prints them in the order that we asked for
         * O(n log n) where n is the number of students in the vector
         *
         * @param sort_ : Way to sort the students of the Uc;
         */
        void sortStudents(const int &sort_);
};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
