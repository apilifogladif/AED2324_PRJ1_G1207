#ifndef AED2324_PRJ1_G1207_STUDENT_H
#define AED2324_PRJ1_G1207_STUDENT_H

#include <string>
#include <vector>
#include <set>
#include "UC.h"

using namespace std;

// this class represents a student
class Student {
    private:
        string studentCode;
        string studentName;
        vector<UC> ucs;
    public:

        /**
         * Class constructor
         * O(1)
         */
        Student();

        /**
         * Class constructor
         * O(1)
         *
         * Sets studentCode and studentName
         *
         * @param studentCode : private , Student code;
         * @param studentName : private , Student name;
         */
        Student(string studentCode, string studentName);

        /**
         * Class constructor
         * O(1)
         *
         * Sets studentCode, studentName and ucs
         *
         * @param studentCode : private , Student code;
         * @param studentName : private , Student name;
         * @param ucs : vector of ucs;
         */
        Student(string studentCode, string studentName, vector<UC> ucs);

        /**
         * Returns the student code
         * O(1)
         *
         * @return studentCode
         */
        string getStudentCode() const;

        /**
         * Returns the student name
         * O(1)
         *
         * @return studentName
         */
        string getStudentName() const;

        /**
         * Returns the UCs of the student lessons
         *
         * @return ucs
         */
        vector<UC> getUCs() const;

        /**
         * Adds a UC to the student lessons
         * O(1)
         *
         * @param uc : Uc
         */
        void addUC(const UC &uc);

        /**
         * Adds a UC to the student lessons
         * O(log n) + O(n) where n is the number of students int the CSVInfo.StudentsVector
         *
         * @param uc : Uc
         */
        void removeUC(const UC &uc);

        /**
         * Binary search to search the position of a student in the StudentsVector from Csv file
         * O(n log n) where n is the number of students in the CSVInfo.StudentsVector
         *
         * @param left : ??????????????????????????
         * @param right : ?????????????????????????
         * @return
         */
        int binarySearchCsvStudentVector(unsigned long left, unsigned long right);

        /**
         * Changes the UC of the student
         * O(1)
         *
         * @param uc : Uc
         * @return UC
         */
        UC changeUC(const UC &uc);

        /**
         * Returns the Uc with the given Uc code
         * O(n) where n is the number of UC objects in the ucs vector
         *
         * @param UcCode : Uc code
         * @return UC
         */
        UC findUc(const string& UcCode) const;

        /**
         * Checks if a student is enrolled in a UC with UcCode
         * O(n) where n is the number of UC objects in the ucs vector
         *
         * @paramt UcCode : Uc code
         * @return bool : true or false
         */
        bool Enrolled(const string& UcCode);

        /**
         * Operator to compare two students
         * O(1)
         *
         * @param s : Student
         * @return bool : true or false
         */
        bool operator<(const Student& s) const;

        /**
         * Operator to compare the similarity between two students
         * O(1)
         *
         * @param s : Student
         * @return bool : true or false
         */
        bool operator==(const Student &s) const;

        /**
         * Prints the Uc code and the Uc class
         * O(n) where n is the number of UC objects in the ucs vector
         */
        void printUcAndClass() const;
};

#endif // AED2324_PRJ1_G1207_STUDENT_H