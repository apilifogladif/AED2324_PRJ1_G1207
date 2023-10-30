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
        /*
        * Class constructor
        *
        * Sets studentCode and studentName
        *
        * @paramt studentCode : private , Student code;
        * @paramt studentName : private , Student name;
        */
        Student();
        Student(string studentCode, string studentName);
        Student(string studentCode, string studentName, vector<UC> ucs);

        /*
         * Returns the studentCode
         */
        string getStudentCode() const;

        /*
         * Returns the student name
         */
        string getStudentName() const;

        /*
         * Returns the UCs of the student lessons
         */
        vector<UC> getUCs() const;

        /*
         * Adds a UC to the student lessons
         *
         * @paramt uc : Uc
         */
        void addUC(const UC &uc);

        /*
         * Adds a UC to the student lessons
         *
         * @paramt uc : Uc
         */
        void removeUC(const UC &uc);

        /*
         * Changes the UC of the student
         *
         * @paramt uc : Uc
         */
        UC changeUC(const UC &uc);

        /*
         * Returns the Uc with the given Uc code
         *
         * @paramt UcCode : Uc code
         */
        UC findUc(const string& UcCode) const;

        /*
         * Checks if a student is enrolled in a UC with UcCode
         *
         * @paramt UcCode : Uc code
         */
        bool Enrolled(const string& UcCode);

        /*
         * Operator to compare two students
         *
         * @paramt s : Student
         */
        bool operator<(const Student& s) const;

        /*
         * Operator to compare the similarity between two students
         *
         * @paramt s : Student
         */
        bool operator==(const Student &s) const;

        /*
         * Prints the Uc code and the Uc class
         */
        void printUcAndClass() const;
};

#endif // AED2324_PRJ1_G1207_STUDENT_H