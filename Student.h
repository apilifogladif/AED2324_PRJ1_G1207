#ifndef AED2324_PRJ1_G1207_STUDENT_H
#define AED2324_PRJ1_G1207_STUDENT_H

#include <string>
#include <vector>
#include <set>
#include "UC.h"

using namespace std;

// this class represents a student
/**
 * @file Student.h
 * @brief Class that represents a student
 */
class Student {
    private:
        string studentCode;
        string studentName;
        vector<UC> ucs;
    public:

        /**
         * @brief Student::Student
         * Class constructor
         *
         * Complexity: O(1)
         */
        Student();

        /**
         * @brief Student::Student
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param studentCode : The student code;
         * @param studentName : The student name.
         */
        Student(string studentCode, string studentName);

        /**
         * @brief Student::Student
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param studentCode : The student code;
         * @param studentName : The student name;
         * @param ucs : Vector of ucs;
         */
        Student(string studentCode, string studentName, vector<UC> ucs);

        /**
         * @brief Student::getStudentCode
         * Gets the student code
         *
         * Complexity: O(1)
         *
         * @return The student code.
         */
        string getStudentCode() const;

        /**
         * @brief Student::getStudentName
         * Gets the student name
         *
         * Complexity: O(1)
         *
         * @return The student name.
         */
        string getStudentName() const;

        /**
         * @brief Student::getUCs
         * Gets the uc's
         *
         * Complexity: O(1)
         *
         * @return The uc's.
         */
        vector<UC> getUCs() const;

        /**
         * @brief Student::setUCs
         * Sets a value for ucs
         *
         * @param ucs_ : The value to set to ucs.
         */
        void setUCs(vector<UC> ucs_);

        /**
         * @brief Student::addUC
         * Adds a uc to the student lessons
         *
         * Complexity: O(log n) + O(n) where n is the number of students int the CsvAndVectors::StudentsVector
         *
         * @param uc : The uc.
         */
        void addUC(const UC &uc);

        /**
         * @brief Student::removeUC
         * Adds a uc to the student lessons
         *
         * Complexity: O(log n) + O(n) where n is the number of students int the CSVInfo.StudentsVector
         *
         * @param uc : The uc.
         */
        void removeUC(const UC &uc);

        /**
         * @brief Student::binarySearchCsvStudentVector
         * Binary search to search the position of a student in the StudentsVector from Csv file
         *
         * Complexity: O(n log n) where n is the number of students in the CSVInfo.StudentsVector
         *
         * @param left : Inicial index of the analyzed vector;
         * @param right : Final index of the analyzed vector;
         * @return Index of the the student we are searching for.
         */
        int binarySearchCsvStudentVector(unsigned long left, unsigned long right);

        /**
         * @brief Student::changeUC
         * Changes the uc of the student
         *
         * Complexity: O(1)
         *
         * @param uc : The uc;
         * @return New uc.
         */
        UC changeUC(const UC &uc);

        /**
         * @brief Student::findUc
         * Returns the uc with the given uc code
         *
         * Complexity: O(n) where n is the number of UC objects in the ucs vector
         *
         * @param UcCode : The uc code;
         * @return The uc.
         */
        UC findUc(const string& UcCode) const;

        /**
         * @brief Student::Enrolled
         * Checks if a student is enrolled in a uc with UcCode
         *
         * Complexity: O(n) where n is the number of UC objects in the ucs vector
         *
         * @paramt UcCode : The uc code;
         * @return true or false.
         */
        bool Enrolled(const string& UcCode);

        /**
         * @brief Student::operator<
         * Operator to compare two students
         *
         * Complexity: O(1)
         *
         * @param s : The student;
         * @return true or false.
         */
        bool operator<(const Student& s) const;

        /**
         * @brief Student::operator==
         * Operator to compare the similarity between two students
         *
         * Complexity: O(1)
         *
         * @param s : The student;
         * @return true or false.
         */
        bool operator==(const Student &s) const;

        /**
         * @brief Student::printUcAndClass
         * Prints the uc code and the uc class
         *
         * Complexity: O(n) where n is the number of UC objects in the ucs vector
         */
        void printUcAndClass() const;
};

#endif // AED2324_PRJ1_G1207_STUDENT_H