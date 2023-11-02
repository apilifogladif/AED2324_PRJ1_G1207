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
         */
        Student();

        /**
         * Class constructor
         *
         * Sets studentCode and studentName
         *
         * @param studentCode : private , Student code;
         * @param studentName : private , Student name;
         */
        Student(string studentCode, string studentName);

        /**
         * Class constructor
         *
         * Sets studentCode, studentName and ucs
         *
         * @param studentCode : private , Student code;
         * @param studentName : private , Student name;
         * @param ucs : vector of ucs;
         */
        Student(string studentCode, string studentName, vector<UC> ucs);

        /**
         * Returns the studentCode
         *
         * @return
         */
        string getStudentCode() const;

        /**
         * Returns the student name
         *
         * @return
         */
        string getStudentName() const;

        /**
         * Returns the UCs of the student lessons
         *
         * @return
         */
        vector<UC> getUCs() const;

        /**
         * Adds a UC to the student lessons
         *
         * @param uc : Uc
         */
        void addUC(const UC &uc);

        /**
         * Adds a UC to the student lessons
         *
         * @param uc : Uc
         */
        void removeUC(const UC &uc);

        /**
         * Binary search to search the position of a student in the StudentsVector from Csv file
         *
         * @param left : ??
         * @param right : ??
         * @return
         */
        int binarySearchCsvStudentVector(unsigned long left, unsigned long right);

        /**
         * Changes the UC of the student
         *
         * @param uc : Uc
         * @return
         */
        UC changeUC(const UC &uc);

        /**
         * Returns the Uc with the given Uc code
         *
         * @param UcCode : Uc code
         * @return
         */
        UC findUc(const string& UcCode) const;

        /**
         * Checks if a student is enrolled in a UC with UcCode
         *
         * @paramt UcCode : Uc code
         * @return
         */
        bool Enrolled(const string& UcCode);

        /**
         * Operator to compare two students
         *
         * @param s : Student
         * @return
         */
        bool operator<(const Student& s) const;

        /**
         * Operator to compare the similarity between two students
         *
         * @param s : Student
         * @return
         */
        bool operator==(const Student &s) const;

        /**
         * Prints the Uc code and the Uc class
         */
        void printUcAndClass() const;
};

#endif // AED2324_PRJ1_G1207_STUDENT_H