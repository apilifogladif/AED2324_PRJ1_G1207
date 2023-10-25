#ifndef AED2324_PRJ1_G1207_STUDENT_H
#define AED2324_PRJ1_G1207_STUDENT_H

#include <string>
#include <vector>
#include "UC.h"

namespace using std;

// this class represents a student
class Student {
    private:
        int studentCode;
        string studentName;
        vector<UC> ucs;
    public:
        Student(int studentCode, string studentName);
        int getStudentCode() const;
        string getStudentName() const;
        vector<UC> getUCs() const;
        void addUC(const UC &uc);
        void removeUC(const UC &uc);
        void changeUC(const UC &uc);

};

#endif // AED2324_PRJ1_G1207_STUDENT_H