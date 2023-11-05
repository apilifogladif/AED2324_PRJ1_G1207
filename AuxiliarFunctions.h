#ifndef AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
#define AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H

#include "Schedule.h"
#include "Student.h"
#include "Request.h"
#include "Lesson.h"
#include "UC.h"
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <queue>


using namespace std;
/**
 * @file AuxiliarFunctions.h
 * @brief Class that has some auxiliar functions
 */
class AuxiliarFunctions {
    private:
        static vector<Schedule> schedules;
    public:

        /**
         * Queue of the enrollment requests
         */
        static queue<Request> enrollmentRequests;

        /**
         * Queue of the removal requests
         */
        static queue<Request> removalRequests;

        /**
         * Queue of the switch requests
         */
        static queue<Request> switchRequests;

        /**
         * Vector of rejected requests
         */
        static vector<Request> rejectedRequests;

        /**
         * Vector of accepted requests
         */
        static vector<Request> acceptedRequests;

        /**
         * Vector of all requests
         */
        static vector<Request> allRequests;

        /**
        * @brief AuxiliarFunctions::AuxiliarFunctions
        * Class constructor
        *
        * Complexity: O(1)
        */
        AuxiliarFunctions();

        /**
         * @brief AuxiliarFunctions::retStudent
         * Returns the student with the studentCode given
         *
         * Complexity: O(n)
         *
         * @param studentCode : Student code;
         * @return The student.
         */
        static Student retStudent(const string &studentCode) ;

        /**
         * @brief AuxiliarFunctions::concludeEnrollment
         * Concludes the enrollment request by adding that request to the queue of enrollmentRequests
         *
         * Complexity: O(1)
         *
         * @param student : The student who wants to enroll;
         * @param UcClass : Uc class that the student given wants to enroll.
         */
        static void concludeEnrollment(const Student &student, const UC &UcClass);

        /**
         * @brief AuxiliarFunctions::concludeRemoval
         * Concludes the removal request by adding that request to the queue of removalRequests
         *
         * Complexity: O(1)
         *
         * @param student : info of the student who wants to leave;
         * @param UcClass : Uc class that the student given wants to leave.
         */
        static void concludeRemoval(const Student &student, const UC &UcClass);

        /**
         * @brief AuxiliarFunctions::concludeSwitch
         * Concludes the switch request by adding that request to the queue of switchRequests
         *
         * Complexity: O(1)
         *
         * @param student : info of the student who wants to switch;
         * @param UcClass : Uc class that the student given wants to switch.
         */
        static void concludeSwitch(const Student &student, const UC &oldUc, const UC &newUc);

        /**
         * @brief AuxiliarFunctions::lessonOverlap
         * Checks if there is no conflict between the student’s schedule and the new class’s schedule
         *
         * Complexity: O(max(q * r, n * m)), where q is the lessons in class 1, r is the lessons in class 2 and O(n*m) is the time complexity of the Schedule constructor
         *
         * @param uc1 : one class;
         * @param uc2 : another class;
         * @return true or false.
         */
         static bool lessonOverlap(UC uc1, UC uc2);

        /**
         * @brief AuxiliarFunctions::requestBalance
         * Checks some conditions to secure the balance of the size os each class
         *
         * Complexity: O(n * m), where n is the number of Ucs and m is the number of Classes from each uc
         *
         * Requests:
         * A student cannot be in more than one class at once for a given UC;
         * A class can only accept a new student if its capacity has not been exceeded (consider that there is a maximum capacity Cap for classes);
         * A class can only accept a new student if the balance between class occupation is not disturbed (the balance of class occupation is maintained when the difference between the number of students in any class is less than or equal to 4).
         *
         * @param request : The request made;
         * @return true or false.
         */
        static bool requestBalance(Request &request);

        /**
         * @brief AuxiliarFunctions::requestConflict
         * Checks if the resulting schedule will not conflict with the student's original schedule
         *
         * Complexity: O(n)
         *
         * @param request : The request made;
         * @return true or false.
         */
        static bool requestConflict(Request &request);

        /**
         * @brief AuxiliarFunctions::requestMax
         * Returns true if the capacity of the class has been exceeded
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param request : The request made;
         * @return true or false.
         */
        static bool requestMax(Request &request);

        /**
         * @brief AuxiliarFunctions::verifySwapRequest
         * Checks if the request has any problem (unbalanced, conflict, extends the max)
         *
         * Complexity: O(n)
         *
         * @param request : The request made.
         */
        static void verifySwapRequest(Request &request);

        /**
         * @brief AuxiliarFunctions::verifyEnrollmentRequest
         * Checks if request has any problem (conflict, extends the max)
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param request : The request made.
         */
        static void verifyEnrollmentRequest(Request &request);

        /**
         * @brief AuxiliarFunctions::verifyRemovalRequest
         * Does the removal requests as it does not need any problem verification
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param request : The request made.
         */
        static void verifyRemovalRequest(Request &request);

        /**
         * @brief AuxiliarFunctions::changeAllRequests
         * Makes all status (and the reason) on the vector all requests
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param status : The status of the request;
         * @param request : The request made.
         */
        static void changeAllRequests(bool status, Request request);

        /**
         * @brief AuxiliarFunctions::RequestsManager
         * Finalizes the requests
         *
         * Complexity: O(max(n, m, k, q)), where n is the number of removal requests,
         * m is the number of enrollment requests,
         * k is the number of switch request,
         * q is the number of requests (n + m + k)
         */
        static void RequestsManager();

        /**
         * @brief AuxiliarFunctions::seeRejectedRequests
         * Prints the requests that were rejected
         *
         * Complexity: O(n)
         */
        static void seeRejectedRequests();

        /**
         * @brief AuxiliarFunctions::seeAcceptedRequests
         * Prints the requests that were accepted
         *
         * Complexity: O(n)
         */
        static void seeAcceptedRequests();

        /**
         * @brief AuxiliarFunctions::seeAllRequests
         * Prints all the requests and respective status
         *
         * Complexity: O(n)
         */
        static void seeAllRequests();

        /**
         * @brief AuxiliarFunctions::seeStudentSchedule
         * Prints the schedule of a given student
         *
         * Complexity: O(n)
         *
         * @param StudentCode : The student code.
         */
        static void seeStudentSchedule(const string& StudentCode) ;

        /**
         * @brief AuxiliarFunctions::seeClassSchedule
         * Prints the schedule of a given class
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param ClassCode : The class code.
         */
        static void seeClassSchedule(const string& ClassCode);

        /**
         * @brief AuxiliarFunctions::seeUcSchedule
         * Prints the schedule of a given Uc
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param UcCode : The uc code;
         */
        static void seeUcSchedule(const string& UcCode);

        /**
         * @brief AuxiliarFunctions::seeClassStudents
         * Prints the students of a given class
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param UcClass : The uc class;
         * @param order_ : Way to sort the students of the class.
         */
        static void seeClassStudents(const UC& UcClass, const int &order_);

        /**
         * @brief AuxiliarFunctions::seeUcStudents
         * Prints the students of a given Uc
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param UcCode : The uc code;
         * @param order_ : Way to sort the students of the Uc.
         */
        static void seeUcStudents(const string &UcCode, const int &sort_);

        /**
         * @brief AuxiliarFunctions::seeYearStudents
         * Prints the students of a given year
         *
         * Complexity: O(max(n, m)), where n is the number of students,
         * m i the number of students in the given year
         *
         * @param year: The year of the students;
         * @param sort : Way to sort the students of the Uc;
         */
        static void seeYearStudents(int year, int sort);

        /**
         * @brief AuxiliarFunctions::numberClassStudents
         * Returns the number of students of a given Class and Uc
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param UcClass : The uc class;
         * @return The number of students of a given class and uc.
         */
        static int numberClassStudents(const UC& UcClass);

        /**
         * @brief AuxiliarFunctions::numberUcStudents
         * Returns the number of students of a given Class
         *
         * Complexity: O(n*m), where O(n*m) is the time complexity of the Schedule constructor
         *
         * @param UcCode : The uc code;
         * @return The number of students of a given class.
         */
        static int numberUcStudents(const string &UcCode);

        /**
         * @brief AuxiliarFunctions::numberYearStudents
         * Returns the number of students of a given Year
         *
         * Complexity: O(n)
         *
         * @param Year : The year of the students;
         * @return The number of students of a given year.
         */
        static int numberYearStudents(char &Year);
};
#endif //AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
