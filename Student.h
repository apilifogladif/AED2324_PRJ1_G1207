#ifndef AED2324_PRJ1_G1207_STUDENT_H
#define AED2324_PRJ1_G1207_STUDENT_H

#include <string>
#include <vector>
#include "UC.h"

using namespace std;

// this class represents a student
class Student {
    private:
        int studentCode;
        string studentName;
        vector<UC> ucs;
    public:
    // constructor for the Student class
        Student(int studentCode, string studentName, vector<UC> ucs);

    // returns the studentCode
        int getStudentCode() const;

    // return the studentName
        string getStudentName() const;

    // return the UCs of the student lessons
        vector<UC> getUCs() const;

    // adds an UC to the student lessons
        void addUC(const UC &uc);

    // adds an UC to the student lessons
        void removeUC(const UC &uc);

    // changes the UC of the student
        void changeUC(const UC &uc);


        bool findUc(const string UcCode);
        // checks if student is enrolled in a UC with UcCode
        bool Enrolled(string UcCode);

};

#endif // AED2324_PRJ1_G1207_STUDENT_H