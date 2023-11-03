#include "UC.h"

#include <utility>

// O(1)
UC::UC() {
    this->UcCode = "";
    this->ClassCode = "";
}

// O(1)
UC::UC(string UcCode, string ClassCode) {
    this->UcCode = std::move(UcCode);
    this->ClassCode = std::move(ClassCode);
}

// O(1)
string UC::getUcCode() const{
    return this->UcCode;
}

// O(1)
string UC::getClassCode() const{
    return this->ClassCode;
}

// O(1)
void UC::setUcCode(string code){
    this->UcCode = std::move(code);
}

// O(1)
void UC::setClassCode(string code){
    this->ClassCode = std::move(code);
}

// O(1)
bool UC::hasSameUcCode(UC &uc_) {
    return this->UcCode == uc_.UcCode;
}

// O(1)
bool UC::operator==(const UC &uc_) {
    return this->UcCode == uc_.UcCode && this->ClassCode == uc_.ClassCode;
}

// O(1)
bool UC::operator<(const UC &uc_) {
    if (this->UcCode == uc_.UcCode) {
        return this->ClassCode < uc_.ClassCode;
    }
    return this->UcCode < uc_.UcCode;
}
