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
         * @brief UC::UC
         * Class constructor
         */
        UC();

        /**
         * @brief UC::UC
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param UcCode : The uc code;
         * @param ClassCode : The class code.
         */
        UC(string UcCode, string ClassCode);

        /**
         * @brief UC::getUcCode
         * Returns code of the uc
         *
         * Complexity: O(1)
         *
         * @return The uc code.
         */
        string getUcCode() const;

         /**
          * @brief UC::getClassCode
          * Returns the code of the class
          *
          * Complexity: O(1)
          *
          * @return The class code.
          */
        string getClassCode() const;

        /**
         * @brief UC::setUcCode
         * Sets a value to the uc code
         *
         * Complexity: O(1)
         *
         * @param code : Value to set the uc code.
         */
        void setUcCode(string code);

        /**
         * @brief UC::setClassCode
         * Sets a value to the class code
         *
         * Complexity: O(1)
         *
         * @param code : Value to set the class code.
         */
        void setClassCode(string code);

        /**
         * @brief UC::operator==
         * Operator to compare the similarity between two uc's
         *
         * Complexity: O(1)
         *
         * @param uc_ : The uc we are comparing with;
         * @return true or false.
         */
        bool operator==(const UC& uc_);

        /**
         * @brief UC::operator<
         * Operator to compare two uc's
         *
         * Complexity: O(1)
         *
         * @paramt uc_ : The uc we are comparing with;
         * @return true or false.
         */
        bool operator<(const UC &uc_);

        /**
         * @brief UC::hasSameUcCode
         * Operator to compare if two uc's have the same Uc code
         *
         * Complexity: O(1)
         *
         * @paramt uc_ : The uc we are comparing with;
         * @return true or false.
         */
        bool hasSameUcCode(UC &uc_);
};

#endif //AED2324_PRJ1_G1207_UC_H

