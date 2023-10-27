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
        Student(string studentCode, string studentName, vector<UC> ucs);
        Student(string studentCode, string studentName);

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
         */
        void addUC(const UC &uc);

        /*
         * Adds an UC to the student lessons
         */
        void removeUC(const UC &uc);

        /*
         * Changes the UC of the student
         */
        UC changeUC(const UC &uc);

        /*
         *
         */
        UC findUc(string UcCode) const;

        /*
         * Checks if a student is enrolled in a UC with UcCode
         */
        bool Enrolled(string UcCode);

        /*
         * Operator to compare two students
         */
        bool operator<(const Student& s) const;

        /*
         * Operator to compare the similarity between two students
         */
        bool operator==(const Student &s) const;
};

#endif // AED2324_PRJ1_G1207_STUDENT_H