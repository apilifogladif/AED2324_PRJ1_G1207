#ifndef AED2324_PRJ1_G1207_CLASS_H
#define AED2324_PRJ1_G1207_CLASS_H

#include <string>

namespace using std;

class Class {
    private:
        string UcCode;
        string ClassCode;
    public:
        Class(string UcCode, string ClassCode);
        string getUcCode() const;
        string getClassCode() const;
        void setUcCode(string code);
        void setClassCode(string code);
};

#endif