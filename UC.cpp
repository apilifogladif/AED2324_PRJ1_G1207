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

bool UC::hasSameUcCode(UC &uc_) {
    return this->UcCode == uc_.UcCode;
}

bool UC::operator==(const UC &uc_) {
    return this->UcCode == uc_.UcCode && this->ClassCode == uc_.ClassCode;
}

bool UC::operator<(const UC &uc_) {
    if (this->UcCode == uc_.UcCode) {
        return this->ClassCode < uc_.ClassCode;
    }
    return this->UcCode < uc_.UcCode;
}
