#ifndef AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
#define AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H

#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "Lesson.h"
#include "UC.h"
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <queue>


using namespace std;

class AuxiliarFunctions {
    private:
        vector<Schedule> schedules;
    public:
        static queue<Request> enrollmentRequests;
        static queue<Request> removalRequests;
        static queue<Request> switchRequests;
        static vector<Request> rejectedRequests;
        static vector<Request> acceptedRequests;
        static vector<Request> allRequests;

        /**
        * Class constructor
        */
        AuxiliarFunctions();

        /**
         * Returns the student with the studentCode given
         *
         * @param studentCode : Student code;
         * @return
         */
        static Student retStudent(const string &studentCode) ;

        /**
         * Concludes the enrollment request by adding that request to the queue of enrollmentRequests
         *
         * @param student : info of the student who wants to enroll;
         * @param UcClass : Uc class that the student given wants to enroll;
         */
        void concludeEnrollment(const Student& student, const UC& UcClass);

        /**
         * Concludes the removal request by adding that request to the queue of removalRequests
         *
         * @param student : info of the student who wants to leave;
         * @param UcClass : Uc class that the student given wants to leave;
         */
        void concludeRemoval(const Student& student, const UC& UcClass);

        /**
         * Concludes the switch request by adding that request to the queue of switchRequests
         *
         * @param student : info of the student who wants to switch;
         * @param UcClass : Uc class that the student given wants to switch;
         */
        void concludeSwitch(const Student& student, const UC& UcClass);

        /**
         * Returns a vector with the students of an Uc
         *
         * @param UcCode : Uc code;
         * @return
         */
        vector<Schedule> UcClasses(const string& UcCode);

        /**
         * A student cannot be registered in more than 7 UCs at any given type
         *
         * @param request : request;
         * @return
         */
        bool requestMax(Request &request);

        // there mut be at leas one class with a vacancy in the new UC/////////////////////////////////

        /**
         * Checks if the resulting schedule will not conflict with the student's original schedule
         *
         * @param request : request;
         * @return
         */
        bool requestConflict(Request &request);

        /**
         * Checks some conditions to secure the balance of the size os each class
         *
         * Requests:
         * A student cannot be in more than one class at once for a given UC;
         * A class can only accept a new student if its capacity has not been exceeded (consider that there is a maximum capacity Cap for classes);
         * A class can only accept a new student if the balance between class occupation is not disturbed (the balance of class occupation is maintained when the difference between the number of students in any class is less than or equal to 4).
         *
         * @param request : request;
         * @return
         */
        static bool requestBalance(Request &request);

        /**
         * Checks if there is no conflict between the student’s schedule and the new class’s schedule
         *
         * @param uc1 : one Uc;
         * @param uc2 : another Uc;
         * @return
         */
        bool lessonOverlap(UC uc1, UC uc2);

        /**
         * Returns a vector with the students of an Uc
         *
         * @param UcCode : Uc code;
         * @return
         */
        vector<Student> UcStudents(const string& UcCode);

        /**
         * Get the total number of accepted requests
         *
         * @return
         */
        int totalNumberOfAcceptedRequests();

        /**
         * Get the total number of rejected requests
         *
         * @return
         */
        int totalNumberOfRejectedRequests();

        /**
         * Get request current UC Class
         *
         * @param request : request;
         * @return
         */
        static UC getCurrentClass(Request &request);

        /**
         * See if request has any problem (unbalanced, conflict, extends the max)
         *
         * @param request : request;
         */
        void verifySwapRequest(Request &request);

        /**
         * See if request has any problem (conflict, extends the max)
         *
         * @param request : request;
         */
        void verifyEnrollmentRequest(Request &request);

        /**
         * Does the removal requests as it does not need any problem verification
         *
         * @param request : request;
         */
        void verifyRemovalRequest(Request &request);

        /**
         * Finalizes the requests
         */
        void RequestsManager();

        /**
         * Prints the requests that were rejected
         */
        void seeRejectedRequests();

        /**
         * Prints the requests that were accepted
         */
        void seeAcceptedRequests();

        /**
         * Prints all the requests and respective status
         */
        void seeAllRequests();

        /**
         * Prints the schedule of a given student
         *
         * @param StudentCode : Student code;
         */
        void seeStudentSchedule(const string& StudentCode) const;

        /**
         * Prints the schedule of a given class
         *
         * @param ClassCode : Class code;
         */
        void seeClassSchedule(const string& ClassCode);

        /**
         * Prints the schedule of a given Uc
         *
         * @param UcCode : Uc code;
         */
        void seeUcSchedule(const string& UcCode);

        /**
         * Prints the students of a given class
         *
         * @param UcClass : Uc class;
         * @param order_ : Way to sort the students of the class;
         */
        void seeClassStudents(const UC& UcClass, const int &order_);

        /**
         * Prints the students of a given Uc
         *
         * @param UcCode : Uc code;
         * @param order_ : Way to sort the students of the Uc;
         */
        void seeUcStudents(const string &UcCode, const int &sort_);

        /**
         * Prints the students of a given year
         *
         * @param year: Year;
         * @param sort : Way to sort the students of the Uc;
         */
        void seeYearStudents(int year, int sort);

        /**
         * Returns the number of students of a given Class and Uc
         *
         * @param UcClass : Uc code, Class code;
         * @return
         */
        static int numberClassStudents(const UC& UcClass);

        /**
         * Returns the number of students of a given Class
         *
         * @param UcCode : Uc code;
         * @return
         */
        int numberUcStudents(const string &UcCode);

        /**
         * Returns the number of students of a given Year
         *
         * @paramt Year : year;
         * @return
         */
        int numberYearStudents(const int &Year);

        void getRequests();
};
#endif //AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
