#include "UC.h"

UC::UC(string UcCode, string ClassCode) {
    this->UcCode = UcCode;
    this->ClassCode = ClassCode;
}

string UC::getUcCode() const{
    return this->UcCode;
}

string UC::getClassCode() const{
    return this->ClassCode;
}

void UC::setUcCode(string code){
    this->UcCode = code;
}


void UC::setClassCode(string code){
    this->ClassCode = code;
}