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
/**
 * @file CsvAndVectors.h
 * @brief Class that helps with docs and vectors
 */
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
         *
         * O(n) where n is the number of lines in the 'classes_per_uc.csv'
         */
        static void createClassesAndUcSet();

        /**
         * Creates a set with the students codes
         *
         * O(n) where n is the number of lines in the 'students_classes.csv'
         */
        static void createStudentsSet();
        /**
         * Creates a vector with the lessons
         *
         * O(n) where n is the number of lines in the 'classes.csv'
         */
        static void createLessonsVector();

        /**
         * Creates a vector with the requests
         *
         * O(n) where n is the number of lines in the 'requests.csv'
         */
        static void createRequestsVector();

        /**
         * Creates a vector with the classes and uc's
         *
         * O(n) where n is the number of lines in the 'classes_per_uc.csv'
         */
        static void createClassesPerUcVector();

        /**
         * Creates a vector with the students
         *
         * O(n) where n is the number of lines in the 'students_classes.csv'
         */
        static void createStudentsVector();

        // funções opostas, ou seja, passar as alterações do vetor para os ficheiros csv

        /**
         * Updates students_classes.csv with the new information
         *
         * O(n*k) where n is the number of Student objects in StudentsVector and k is the average number of UC objects associated with each Student
         */
        static void setFromStudentsVector();

        /**
         * Updates requests.csv with the new information
         *
         * O(n) where n is the number of Request objects in RequestVectors
         */
        static void setFromRequestVector();
};

#endif //AED2324_PRJ1_G1207_CSVANDVECTORS_H