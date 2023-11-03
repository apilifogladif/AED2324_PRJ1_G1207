#ifndef AED2324_PRJ1_G1207_REQUEST_H
#define AED2324_PRJ1_G1207_REQUEST_H

#include "Student.h"
#include "UC.h"
#include <string>

using namespace std;

// this class represents a request
/**
 * @file Request.h
 * @brief Class that represents a request
 */
class Request {
    private:
        Student student;
        UC uc;
        UC oldUc; // if it's a switch request
        string type;    // Enrollment, Removal, Switch
        string status;  // Accepted or Rejected
        string reason;

    public:

        /**
         * Class constructor
         *
         * O(1)
         *
         * Sets student, uc, and type
         *
         * @param student : private , Class code;
         * @param uc : private , Curricular unit code;
         * @param type : private , Lesson type;
         */
        Request(Student student, UC uc, string type);

        /**
         * Returns the student that made the request
         *
         * O(1)
         *
         * @return student
         */
        Student getStudent();

        /**
         * Return the old uc of the switch request
         *
         * O(1)
         *
         * @return uc
         */
        UC getoldUC();

        /**
         * Return the uc of the request
         *
         * O(1)
         *
         * @return uc
         */
        UC getUC();

        /**
         * Returns the type of the request
         *
         * O(1)
         *
         * @return type
         */
        string getType();

        /**
        * Return the status of the request
         *
         * O(1)
        *
        * @return status
        */
        string getStatus();

        /**
         * Return the reason of the request if it was rejected
         *
         * O(1)
         *
         * @return reason
         */
        string getReason();

        /**
         * Sets status to new value
         *
         * O(1)
         *
         * @param status : new value for status
         */
        void setStatus(string status_);
        /**
         * Sets reason to new value
         *
         * O(1)
         *
         * @param reason : new value for reason
         */
        void setReason(string reason_);


        /**
         * Sets old uc of the switch request
         *
         * O(1)
         */
        void setoldUC(UC oldUc_);

        /**
         * Prints request
         *
         * O(1)
         */
        void printRequest();
};

#endif // AED2324_PRJ1_G1207_REQUEST_H
