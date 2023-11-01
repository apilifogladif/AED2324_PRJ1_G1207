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
        static set<string> StudentsSet;
        static set<string> ClassesSet;
        static set<string> UcSet;
        void createStudentsSet();
        void createClassesAndUcSet();
        void createLessonsVector();
        void createClassesPerUcVector();
        void createStudentsVector();
        set<string> getStudentsSet();
        set<string> getClassesSet();
        set<string> getUcSet();
        vector<Lesson> getLessonsVector();
        vector<pair<string, set<string>>> getClassesPerUcVector();
        vector<Student> getStudentsVector();

        // funções opostas, ou seja, passar as alterações do vetor para os ficheiros csv
        static void setFromLessonsVector();
        static void setFromClassesPerUcVector();
        static void setFromStudentsVector();
};

#endif //AED2324_PRJ1_G1207_CSVANDVECTORS_H