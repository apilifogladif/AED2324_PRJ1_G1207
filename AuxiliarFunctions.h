//
// Created by Filipa on 10/26/2023.
//

#ifndef AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
#define AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H

#include "Student.h"
#include <string>
#include <set>

using namespace std;

class AuxiliarFunctions {
    private:
        string studentCode;
        set<Student> students;
    public:
    // returns the student with the studentCode passed
    Student* findStudent(string studentCode);

};
#endif //AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
