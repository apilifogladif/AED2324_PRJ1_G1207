#ifndef AED2324_PRJ1_G1207_REQUEST_H
#define AED2324_PRJ1_G1207_REQUEST_H

#include "Student.h"
#include "UC.h"
#include <string>

using namespace std;

// this class represents a request
class Request {
    private:
        Student* student;
        UC* uc;
        string type;
    public:
        /*
         * Class constructor
         *
         * Sets student, uc, and type
         *
         * @paramt student : private , Class code;
         * @paramt uc : private , Curricular unit code;
         * @paramt type : private , Lesson type;
         */
        Request(Student* student, UC* uc, string type);

        /*
         * Returns the student that made the request
         */
        Student getStudent();

        /*
         * Return the uc of the request
         */
        UC getUC();

        /*
         * Returns the type of the request
         */
        string getType();
        // prints request
        void printRequest();
};

#endif // AED2324_PRJ1_G1207_REQUEST_H
