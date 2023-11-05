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
