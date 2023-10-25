#ifndef AED2324_PRJ1_G1207_UC_H
#define AED2324_PRJ1_G1207_UC_H

#include <string>

using namespace std;

// this class represents a UC
class UC {
    private:
        string UcCode;
        string ClassCode;
        //TODO
        vector<pair<string, int>> students;
    public:
        UC(string UcCode, string ClassCode);
        string getUcCode() const;
        string getClassCode() const;
        void setUcCode(string code);
        void setClassCode(string code);
};

#endif //AED2324_PRJ1_G1207_UC_H