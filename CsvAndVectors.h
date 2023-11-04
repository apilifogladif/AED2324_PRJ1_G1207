#ifndef AED2324_PRJ1_G1207_CSVANDVECTORS_H
#define AED2324_PRJ1_G1207_CSVANDVECTORS_H

#include <iostream>
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
         * @brief CsvAndVectors::CsvAndVectors
         * Class constructor
         *
         * Complexity: O(n)
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
         * @brief CsvAndVectors::createClassesAndUcSet
         * Creates a set with the classes and uc's codes
         *
         * Complexity: O(n) where n is the number of lines in the 'classes_per_uc.csv'
         */
        static void createClassesAndUcSet();

        /**
         * @brief CsvAndVectors::createStudentsSet
         * Creates a set with the students codes
         *
         * Complexity: O(n) where n is the number of lines in the 'students_classes.csv'
         */
        static void createStudentsSet();

        /**
         * @brief CsvAndVectors::createLessonsVector
         * Creates a vector with the lessons
         *
         * Complexity: O(n) where n is the number of lines in the 'classes.csv'
         */
        static void createLessonsVector();

        /**
         * @brief CsvAndVectors::createRequestsVector
         * Creates a vector with the requests
         *
         * Complexity: O(n) where n is the number of lines in the 'requests.csv'
         */
        static void createRequestsVector();

        /**
         * @brief CsvAndVectors::createClassesPerUcVector
         * Creates a vector with the classes and uc's
         *
         * Complexity: O(n) where n is the number of lines in the 'classes_per_uc.csv'
         */
        static void createClassesPerUcVector();

        /**
         * @brief CsvAndVectors::createStudentsVector
         * Creates a vector with the students
         *
         * Complexity: O(n) where n is the number of lines in the 'students_classes.csv'
         */
        static void createStudentsVector();

        // funções opostas, ou seja, passar as alterações do vetor para os ficheiros csv

        /**
         * @brief CsvAndVectors::setFromStudentsVector
         * Updates students_classes.csv with the new information
         *
         * Complexity: O(n*k) where n is the number of Student objects in StudentsVector and k is the average number of UC objects associated with each Student
         */
        static void setFromStudentsVector();

        /**
         * @brief CsvAndVectors::setFromRequestVector
         * Updates requests.csv with the new information
         *
         * Complexity: O(n) where n is the number of Request objects in RequestVectors
         */
        static void setFromRequestVector();
};

#endif //AED2324_PRJ1_G1207_CSVANDVECTORS_H