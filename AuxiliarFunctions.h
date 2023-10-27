#ifndef AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
#define AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H

#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "Lesson.h"
#include "UC.h"
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

class AuxiliarFunctions {
    private:
        set<Student> students;
        vector<Schedule> schedules;
        queue<Request> enrollmentRequests;
        queue<Request> removalRequests;
        queue<Request> switchRequests;
        struct rejectedRequests_ {
            Request request;
            string reason;
            rejectedRequests_(Request request_, string reason_) : request(request_), reason(reason_) {};
        };
        vector<rejectedRequests_> rejectedRequests;

public:
        // returns the student with the studentCode passed
        Student* retStudent(const string &studentCode) const;
        // returns the schedule with the UcClass passed
        Schedule* UCSchedule(UC UcClass); // falta complexidade
        // returns the index of the schedule with the UcClass passed
        unsigned long binarySearch(UC UcClass);
        // auxiliary function to help with the recursion of the binary search
        unsigned long binarySearchAux(UC UcCLass, unsigned long left, unsigned long right);
        // concludes the enrollment request by adding that request (with the student and UcClass he wants to enroll in) to the queue of enrollmentRequests
        void concludeEnrollment(Student student, UC UcClass);
        // concludes the removal request by adding that request (with the student and UcClass he wants to leave) to the queue of removalRequests
        void concludeRemoval(Student student, UC UcClass);
        // concludes the switch request by adding that request (with the student and UcClass he wants to switch) to the queue of switchRequests
        void concludeSwitch(Student student, UC UcClass);
        // exceptions
        // UC changes
        // a student cannot be registered in more than 7 UCs at any given type
        bool requestMax(Request &request);
        // there mut be at leas one class with a vacancy in the new UC
        // the resulting schedule will not conflict with the student's original schedule
        bool requestConflict(Request &request);
        // Class changes
        // a student cannot be in more than one class at once for a given UC
        // a class can only accept a new student if its capacity has not been exceeded (consider that there is a maximum capacity Cap for classes)
        // a class can only accept a new student if the balance between class occupation is not disturbed; the balance of class occupation is maintained when the difference between the number of students in any class is less than or equal to 4
        bool requestBalance(Request &request);
        // There is no conflict between the student’s schedule and the new class’s schedule
        // a student’s schedule may overlap classes if they are neither TP nor PL, that is, there may be overlapping classes between T and TP, between T and T, and between T and P
        bool lessonOverlap(UC uc1, UC uc2);

        // get the number of students in a class in an UC
        int totalNumberOfStudentsUcClass(UC UcClass);
        // get request current UC Class
        UC getCurrentClass(Request &request);
        // see if request has any problem (unbalanced, conflict, extends the max)
        void verifySwapRequest(Request &request);

        // a implementar
        void verifyEnrollmentRequest(Request &request);
        void verifyRemovalRequest(Request &request);
        vector<Schedule> UcClasses(string UcCode);
};
#endif //AED2324_PRJ1_G1207_AUXILIARFUNCTIONS_H
