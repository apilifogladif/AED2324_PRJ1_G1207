#ifndef AED2324_PRJ1_G1207_REQUEST_H
#define AED2324_PRJ1_G1207_REQUEST_H

#include "Student.h"
#include "UC.h"
#include <string>

using namespace std;

// this class represents a request
class Request {
    private:
        Student student;
        UC uc;
        string type;    // Enrollment, Removal, Switch
        string status;  // Accepted or Rejected
        string reason;
        string description; // description of the request

    public:
        /**
         * Class constructor
         *
         * Sets student, uc, and type
         *
         * @paramt student : private , Class code;
         * @paramt uc : private , Curricular unit code;
         * @paramt type : private , Lesson type;
         */
        Request(Student student, UC uc, string type);

        /**
         * Returns the student that made the request
         *
         * @return
         */
        Student getStudent();

        /**
         * Return the uc of the request
         *
         * @return
         */
        UC getUC();

        /**
         * Returns the type of the request
         *
         * @return
         */
        string getType();

        /**
        * Return the status of the request
        *
        * @return
        */
        string getStatus();

        /**
         * Return the reason of the request if it was rejected
         *
         * @return
         */
        string getReason();

        /**
         * Return the description of the request
         *
         * @return
         */
        string getDescription();

        void setStatus(string status);

        void setReason(string reason);

        void setDescription(string description);

        /**
         * Prints request
         */
        void printRequest();
};

#endif // AED2324_PRJ1_G1207_REQUEST_H
