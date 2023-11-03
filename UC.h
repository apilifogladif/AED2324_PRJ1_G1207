#ifndef AED2324_PRJ1_G1207_UC_H
#define AED2324_PRJ1_G1207_UC_H

#include <string>

using namespace std;

// this class represents a UC7
/**
 * @file  UC.h
 * @brief Class that represents a uc
 */
class UC {
    private:
        string UcCode;
        string ClassCode;
    public:
        /**
         * Class constructor simple
         */
        UC();

        /**
         * Class constructor
         *
         * Sets UcCode and ClassCode
         *
         * @param UcCode : private , Uc code;
         * @param ClassCode : private , Class code;
         */
        UC(string UcCode, string ClassCode);

        /**
         * Returns code of the Uc
         *
         * @return UcCode
         */
        string getUcCode() const;

         /**
          * Returns the code of the Uc
          *
          * @return ClassCode
          */
        string getClassCode() const;

        /**
         * Sets a value to the Uc code
         *
         * @param code : value to set the Uc code
         */
        void setUcCode(string code);

        /**
         * Sets a value to the Class code
         *
         * @param code : value to set the Class code
         */
        void setClassCode(string code);

        /**
         * Operator to compare the similarity between two Uc's
         *
         * @param uc_ : Uc;
         * @return bool : true or false
         */
        bool operator==(const UC& uc_);

        /**
         * Operator to compare two Uc's
         *
         * @paramt uc_ : Uc;
         * @return bool : true or false
         */
        bool operator<(const UC &uc_);

        /**
         * Operator to compare if two Uc's have the same Uc code
         *
         * @paramt uc_ : Uc;
         * @return bool : true or false
         */
        bool hasSameUcCode(UC &uc_);
};

#endif //AED2324_PRJ1_G1207_UC_H

