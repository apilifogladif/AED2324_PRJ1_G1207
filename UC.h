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
        /*
         * Class constructor
         *
         * Sets UcCode and ClassCode
         *
         * @paramt UcCode : private , Uc code;
         * @paramt ClassCode : private , Class code;
         */
        UC(string UcCode, string ClassCode);

        /*
         * Returns code of the Uc
         */
        string getUcCode() const;

        /*
         * Returns the code of the Uc
         */
        string getClassCode() const;

        /*
         * Sets a value to the Uc code
         */
        void setUcCode(string code);

        /*
         * Sets a value to the Class code
         */
        void setClassCode(string code);

        /*
         * Operator to compare the similarity between two Uc's
         */
        bool operator==(const UC& uc_);
        /*
         * Operator to compare two Uc's
         */
        bool operator<(const UC &uc_);

        bool hasSameUcCode(UC &uc_);
};

#endif //AED2324_PRJ1_G1207_UC_H

