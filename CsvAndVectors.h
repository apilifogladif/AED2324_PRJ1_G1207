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
#include "Request.h"
#include "Schedule.h"


using namespace std;

class CsvAndVectors {
    private:

    public:
        /**
         * Class constructor
         */
        CsvAndVectors();

        /**
         * Has the information of classes.csv
         */
        static vector<Lesson> LessonsVector;

        /**
         * Has the information of classes_per_uc.csv
         */
        static vector<pair<string, set<string>>> ClassesPerUcVector;

        /**
         * Has the information of students_classes.csv
         */
        static vector<Student> StudentsVector;

        /**
         * Has the information of requests.csv
         */
        static vector<Request> RequestsVector;

        /**
         * Set of all the students codes
         */
        static set<string> StudentsSet;

        /**
         * Set of all the classes codes
         */
        static set<string> ClassesSet;

        /**
         * Set of all the uc's codes
         */
        static set<string> UcSet;

        /**
         * Creates a set with the classes and uc's codes
         */
        static void createClassesAndUcSet();

        /**
         * Creates a set with the students codes
         */
        static void createStudentsSet();
        /**
         * Creates a vector with the lessons
         */
        void createLessonsVector();

        /**
         * Creates a vector with the requests
         */
        void createRequestsVector();

        /**
         * Creates a vector with the classes and uc's
         */
        void createClassesPerUcVector();

        /**
         * Creates a vector with the students
         */
        void createStudentsVector();

        /**
         * Returns students set
         *
         * @return StudentsSet : set  with the students
         */
        set<string> getStudentsSet();

        /**
         * Returns classes set
         *
         * @return ClassesSet : set  with the classes
         */
        set<string> getClassesSet();

        /**
         * Returns uc's set
         *
         * @return UcSet : set  with the uc's
         */
        set<string> getUcSet();

        /**
         * Returns lessons vector
         *
         * @return LessonsVector : vector  with the lessons
         */
        vector<Lesson> getLessonsVector();

        /**
         * Returns requests vector
         *
         * @return RequestVector : vector  with the requests
         */
        vector<Request> getRequestVector();

        /**
         * Returns a vector with the classes per uc
         *
         * @return ClassesPerUcVector : vector with the classes per uc
         */
        vector<pair<string, set<string>>> getClassesPerUcVector();

        /**
         * Returns a vector with the students
         *
         * @return StudentsVector : vector with the students
         */
        vector<Student> getStudentsVector();

        // funções opostas, ou seja, passar as alterações do vetor para os ficheiros csv

        /**
         * Updates classes.csv with the new information
         */
        static void setFromLessonsVector();

        /**
         * Updates classes_per_uc.csv with the new information
         */
        static void setFromClassesPerUcVector();

        /**
         * Updates students_classes.csv with the new information
         */
        static void setFromStudentsVector();

        /**
         * Updates requests.csv with the new information
         */
        static void setRequestVector();
};

#endif //AED2324_PRJ1_G1207_CSVANDVECTORS_H