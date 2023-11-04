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
         * @brief Request::Request
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param student : Student code;
         * @param uc : Uc code;
         * @param type : Lesson type.
         */
        Request(Student student, UC uc, string type);

        /**
         * @brief Request::getStudent
         * Gets the student that made the request
         *
         * Complexity: O(1)
         *
         * @return The student that made the request.
         */
        Student getStudent();

        /**
         * @brief Request::getoldUc
         * Gets the old uc of the switch request
         *
         * Complexity: O(1)
         *
         * @return The Uc before the switch.
         */
        UC getoldUC();

        /**
         * @brief Request::getUc
         * Gets the uc of the request
         *
         * Complexity: O(1)
         *
         * @return The Uc.
         */
        UC getUC();

        /**
         * @brief Request::getType
         * Gets the type of the request
         *
         * Complexity: O(1)
         *
         * @return The type of request.
         */
        string getType();

        /**
        * @brief Request::getStatus
        * Gets the status of the request
        *
        * Complexity: O(1)
        *
        * @return The status of the request.
        */
        string getStatus();

        /**
         * @brief Request::getReason
         * Gets the reason of the request if it was rejected
         *
         * Complexity: O(1)
         *
         * @return The reason why the request was rejected.
         */
        string getReason();

        /**
         * @brief Request::setStatus
         * Sets status to new value
         *
         * Complexity: O(1)
         *
         * @param status : New value for status
         */
        void setStatus(string status_);

        /**
         * @brief Request::setReason
         * Sets reason to new value
         *
         * Complexity: O(1)
         *
         * @param reason : New value for reason
         */
        void setReason(string reason_);


        /**
         * @brief Request::setoldUC
         * Sets old uc of the switch request to new value
         *
         * Complexity: O(1)
         *
         * @param oldUc_ : New value for old Uc
         */
        void setoldUC(UC oldUc_);

        /**
         * @brief Request::printRequest
         * Prints the request
         *
         * Complexity: O(1)
         */
        void printRequest();
};

#endif // AED2324_PRJ1_G1207_REQUEST_H
