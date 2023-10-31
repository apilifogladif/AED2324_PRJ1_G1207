#ifndef AED2324_PRJ1_G1207_CSVANDVECTORS_H
#define AED2324_PRJ1_G1207_CSVANDVECTORS_H

#include "Lesson.h"
#include <fstream>
#include <sstream>
#include "Student.h"
#include "UC.h"
#include <vector>
#include <set>
#include <string>


using namespace std;

class CsvAndVectors {
    private:

    public:
        CsvAndVectors();
        static vector<Lesson> LessonsVector;
        static vector<pair<string, set<string>>> ClassesPerUcVector;
        static vector<Student> StudentsVector;
        void createLessonsVector();
        void createClassesPerUcVector();
        void createStudentsVector();
        vector<Lesson> getLessonsVector();
        vector<pair<string, set<string>>> getClassesPerUcVector();
        vector<Student> getStudentsVector();

        //TODO: funções opostas, ou seja, passar as alterações do vetor para os ficheiros csv
        static void setFromLessonsVector();
        static void setFromClassesPerUcVector();
        void setFromStudentsVector();
};

#endif //AED2324_PRJ1_G1207_CSVANDVECTORS_H