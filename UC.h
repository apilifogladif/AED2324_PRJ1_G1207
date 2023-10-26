#ifndef AED2324_PRJ1_G1207_UC_H
#define AED2324_PRJ1_G1207_UC_H

#include <string>

using namespace std;

// this class represents a UC
class UC {
    private:
        string UcCode;
        string ClassCode;
    public:
    // constructor of the UC class
        UC(string UcCode, string ClassCode);

    // return the UcCode of the UC
        string getUcCode() const;

    // return the UcClassCode of the UC Class
        string getClassCode() const;

    // sets the UcCode of the Class
        void setUcCode(string code);

    // sets the UcClassCode of the Class
        void setClassCode(string code);
};

#endif //AED2324_PRJ1_G1207_UC_H