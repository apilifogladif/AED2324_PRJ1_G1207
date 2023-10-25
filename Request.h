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
    public:
        Request(Student *student, UC &uc, string type);
        Student getStudent();
        UC getUC();
        string getType();
        UC* getUCi();
        UC* getUCf();
        void typeAllocation(string type_);
        bool add(string type_);
        bool remove(string type_);
        bool swap(string type_);
};

#endif // AED2324_PRJ1_G1207_REQUEST_H
