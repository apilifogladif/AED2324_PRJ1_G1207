#ifndef AED2324_PRJ1_G1207_REQUEST_H
#define AED2324_PRJ1_G1207_REQUEST_H

#include "Student.h"
#include "UC.h"

using namespace std;

// this class represents a request
class Request {
    private:
        Student* student;
        UC uc;
        string type;
        string UCi;
        string UCf;
        UC* UCi_ptr;
        UC* UCf_ptr;
    public
        /*
         * Class constructor
         *
         * Sets student, uc, and type
         *
         * @paramt student : private , Class code;
         * @paramt uc : private , Curricular unit code;
         * @paramt type : private , Lesson type;
         */
        Request(Student *student, UC &uc, string type);

        /*
         * Returns the student that made the request
         */
        Student getStudent();

        /*
         * Returnx the uc of the request
         */
        UC getUC();

        /*
         * Returns the type of the request
         */
        string getType();
        /*
         * Allocate to each type which function it must use
         *
         * Enrollment - add method
         * Removal - remove method
         * Swap - swap method
         */
        void typeAllocation(string type_);



        UC* getUCi();
        UC* getUCf();
        bool add(string type_);
        bool remove(string type_);
        bool swap(string type_);
};

#endif // AED2324_PRJ1_G1207_REQUEST_H
