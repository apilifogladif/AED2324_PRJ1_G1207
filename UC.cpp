#include "UC.h"

#include <utility>

UC::UC() {
    this->UcCode = "";
    this->ClassCode = "";
}

UC::UC(string UcCode, string ClassCode) {
    this->UcCode = std::move(UcCode);
    this->ClassCode = std::move(ClassCode);
}

string UC::getUcCode() const{
    return this->UcCode;
}

string UC::getClassCode() const{
    return this->ClassCode;
}

void UC::setUcCode(string code){
    this->UcCode = std::move(code);
}


void UC::setClassCode(string code){
    this->ClassCode = std::move(code);
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
