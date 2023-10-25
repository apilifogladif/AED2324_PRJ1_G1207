#ifndef AED2324_PRJ1_G1207_STUDENT_H
#define AED2324_PRJ1_G1207_STUDENT_H

#include <string>
#include "UC.h"

namespace using std;

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
        void addUC(const UC &ucs);
        void removeUC(const UC &ucs);
        void changeUC(const US &ucs);

};

#endif // AED2324_PRJ1_G1207_STUDENT_H