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
        // nono ficou aqui e ainda não fez auxiliarFunctions and main: pf não apaguem o meu mega comentario :)

        /**
         * ????????????????????????????????????????
         */
        static queue<Request> enrollmentRequests;

        /**
         * ????????????????????????????????????????
         */
        static queue<Request> removalRequests;

        /**
         * ????????????????????????????????????????
         */
        static queue<Request> switchRequests;

        /**
         * ????????????????????????????????????????
         */
        static vector<Request> rejectedRequests;

        /**
         * ????????????????????????????????????????
         */
        static vector<Request> acceptedRequests;

        /**
         * ????????????????????????????????????????
         */
        static vector<Request> allRequests;

        /**
        * Class constructor
        * O(1)
        */
        AuxiliarFunctions();

        /**
         * Returns the student with the studentCode given
         * O(n), where n is the number of students in the vector of students
         *
         * @param studentCode : Student code;
         * @return student
         */
        static Student retStudent(const string &studentCode) ;

        /**
         * Concludes the enrollment request by adding that request to the queue of enrollmentRequests
         * O(1)
         *
         * @param student : info of the student who wants to enroll;
         * @param UcClass : Uc class that the student given wants to enroll;
         */
        void concludeEnrollment(const Student& student, const UC& UcClass);

        /**
         * Concludes the removal request by adding that request to the queue of removalRequests
         * O(1)
         *
         * @param student : info of the student who wants to leave;
         * @param UcClass : Uc class that the student given wants to leave;
         */
        void concludeRemoval(const Student& student, const UC& UcClass);

        /**
         * Concludes the switch request by adding that request to the queue of switchRequests
         * O(1)
         *
         * @param student : info of the student who wants to switch;
         * @param UcClass : Uc class that the student given wants to switch;
         */
        void concludeSwitch(const Student& student, const UC& UcClass);

        /**
         * Checks if there is no conflict between the student’s schedule and the new class’s schedule
         * O(log n) + O(mk) where n is the number of lines in classes_per_uc.csv, m is the number of lessons of the first class and k is the number of lessons of the second class
         *
         * @param uc1 : one Uc;
         * @param uc2 : another Uc;
         * @return bool : true or false
         */
         bool lessonOverlap(UC uc1, UC uc2);

        /**
         * Get the total number of rejected requests
         * O(1)
         *
         * @return rejectedRequests.size
         */
        int totalNumberOfRejectedRequests();

        /**
         * Get the total number of accepted requests
         * O(1)
         *
         * @return acceptedRequests.size
         */
        int totalNumberOfAcceptedRequests();


        /**
         * Get request current UC Class
         * O(m), where m is the number of classes associated in
         *
         * @param request : request;
         * @return current class
         */
        static UC getCurrentClass(Request &request);

        /**
         * Checks some conditions to secure the balance of the size os each class
         * O(log n), where n is the number of schedules / lines in 'classes_per_uc.csv'
         *
         * Requests:
         * A student cannot be in more than one class at once for a given UC;
         * A class can only accept a new student if its capacity has not been exceeded (consider that there is a maximum capacity Cap for classes);
         * A class can only accept a new student if the balance between class occupation is not disturbed (the balance of class occupation is maintained when the difference between the number of students in any class is less than or equal to 4).
         *
         * @param request : request;
         * @return bool : true or false
         */
        static bool requestBalance(Request &request);

        /**
         * Checks if the resulting schedule will not conflict with the student's original schedule
         * O(m log n + m*kl) : where m is the number of classes the student is in, n is the number of lines in classes_per_uc.csv, k is the number of lessons of the first class and l is the number of lessons of the second class
         *
         * @param request : request;
         * @return bool : true or false
         */
        bool requestConflict(Request &request);

        /**
         * Returns a vector with the students of an Uc
         * O(n), where n is the number of schedules / lines in 'classes_per_uc.csv'
         *
         * @param UcCode : Uc code;
         * @return classes
         */
        vector<Schedule> UcClasses(const string& UcCode);

        /**
         * A student cannot be registered in more than 7 UCs at any given type
         * O(n log n), where n is the number of schedules / lines in 'classes_per_uc.csv'
         *
         * @param request : request;
         * @return bool : true or false
         */
        bool requestMax(Request &request);

        /*
         * Returns a vector with the students of an Uc
         *
         * @param UcCode : Uc code;
         * @return
        vector<Student> UcStudents(const string& UcCode);*/


        /**
         * See if request has any problem (unbalanced, conflict, extends the max)
         * O(m log n + m*kl) + O(nlog n): where m is the number of classes the student is in, n is the number of schedules / lines in 'classes_per_uc,csv', k is the number of lessons of the first class and l is the number of lessons of the second class
         *
         * @param request : request;
         */
        void verifySwapRequest(Request &request);

        /**
         * See if request has any problem (conflict, extends the max)
         * O(m log n + m*kl) + O(nlog n): where m is the number of classes the student is in, n is the number of schedules / lines in 'classes_per_uc,csv', k is the number of lessons of the first class and l is the number of lessons of the second class
         *
         * @param request : request;
         */
        void verifyEnrollmentRequest(Request &request);

        /**
         * Does the removal requests as it does not need any problem verification
         * O(m log n + m*kl) + O(nlog n): where m is the number of classes the student is in, n is the number of schedules / lines in 'classes_per_uc,csv', k is the number of lessons of the first class and l is the number of lessons of the second class
         *
         * @param request : request;
         */
        void verifyRemovalRequest(Request &request);

        /**
         * Finalizes the requests
         * O(m) + O(log n * log n) + O(log k) + O(t log n + t*pl) + O(nlog n) where m is the number of classes of the student who is submitting the request,
         * n is the number of schedules / lines in 'classes_per_uc.csv',
         * k is the number of lines in 'students.csv'
         * t is the number of classes the student is in
         * p is the number of lessons of the first class and l is the number of lessons in the second class
         */
        void RequestsManager();

        /**
         * Prints the requests that were rejected
         * O(m), where m is the number of rejected requests
         */
        void seeRejectedRequests();

        /**
         * Prints the requests that were accepted
         * O(m), where m is the number of accepted requests
         */
        void seeAcceptedRequests();

        /**
         * Prints all the requests and respective status
         * O(m), where m is the number of all requests done
         */
        void seeAllRequests();

        /**
         * Prints the schedule of a given student
         * O(n) + O(lk), where n is the total number of students and lessons, l is the lesson in the student's schedule and k is the days of the week
         *
         *
         * @param StudentCode : Student code;
         */
        void seeStudentSchedule(const string& StudentCode) const;

        /**
         * Prints the schedule of a given class
         * O(n) + O(lk), where n is the total number of students and lessons, l is the lesson in the student's schedule and k is the days of the week
         *
         * @param ClassCode : Class code;
         */
        void seeClassSchedule(const string& ClassCode);

        /**
         * Prints the schedule of a given Uc
         * O(n) + O(lk), where n is the total number of students and lessons, l is the lesson in the student's schedule and k is the days of the week
         *
         * @param UcCode : Uc code;
         */
        void seeUcSchedule(const string& UcCode);

        /**
         * Prints the students of a given class
         * O(n) + O(q log q) where n is the number of lessons and students associated with that Class of that UC, q is the number of students in that Class of that UC
         *
         * @param UcClass : Uc class;
         * @param order_ : Way to sort the students of the class;
         */
        void seeClassStudents(const UC& UcClass, const int &order_);

        /**
         * Prints the students of a given Uc
         * O(n) + O(q log q) where n is the number of lessons and students associated with that UC code, q is the number of students in that UC
         *
         * @param UcCode : Uc code;
         * @param order_ : Way to sort the students of the Uc;
         */
        void seeUcStudents(const string &UcCode, const int &sort_);

        /**
         * Prints the students of a given year
         * O(n) + O(mk) + O(m) + O(m log m) where n is the number of students in students_classes.csv, m is the students and k is the UCs of each student
         *
         * @param year: Year;
         * @param sort : Way to sort the students of the Uc;
         */
        void seeYearStudents(int year, int sort);

        /**
         * Returns the number of students of a given Class and Uc
         * O(m + l) + O(1) where m is the number of lessons and l is the number of student in a Class of an UC
         *
         * @param UcClass : Uc code, Class code;
         * @return schedule.getStudents().size
         */
        static int numberClassStudents(const UC& UcClass);

        /**
         * Returns the number of students of a given Class
         * O(m + l) where m is the number of lessons and l is the number of student in an UC
         *
         * @param UcCode : Uc code;
         * @return schedule.getStudents().size
         */
        int numberUcStudents(const string &UcCode);

        /**
         * Returns the number of students of a given Year
         * O(n) where n is the total number of students
         *
         * @paramt Year : year;
         * @return students.size
         */
        int numberYearStudents(const int &Year);

        /**
         * Get requests
         * O(n) is the number of requests
         */
        void getRequests();
};
#endif //AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
