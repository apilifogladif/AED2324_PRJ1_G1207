#include "UC.h"

// constructor of the UC class
UC::UC(string UcCode, string ClassCode) {
    this->UcCode = UcCode;
    this->ClassCode = ClassCode;
}

// return the UcCode of the UC
string UC::getUcCode() const{
    return this->UcCode;
}

// return the UcClassCode of the UC Class
string UC::getClassCode() const{
    return this->ClassCode;
}

// sets the UcCode of the Class
void UC::setUcCode(string code){
    this->UcCode = code;
}

// sets the UcClassCode of the Class
void UC::setClassCode(string code){
    this->ClassCode = code;
}