#include "Lesson.h"

#include <utility>

// O(1)
Lesson::Lesson(string UcCode, string ClassCode, string weekday, float startHour, float duration, string type) :  uc(std::move(UcCode), std::move(ClassCode)) {
    this->weekday = std::move(weekday);
    this->startHour = startHour;
    this->endHour = startHour + duration;
    this->duration = duration;
    this->type = std::move(type);
}

// O(1)
UC Lesson::getUc() const {
    return uc;
}

// O(1)
string Lesson::getWeekday() const {
    return this->weekday;
}

// O(1)
float Lesson::getStartHour() const {
    return this->startHour;
}

// O(1)
float Lesson::getEndHour() const {
    return this->endHour;
}

// O(1)
float Lesson::getDuration() const {
    return this->duration;
}

// O(1)
string Lesson::getType() const {
    return this->type;
}

// O(1)
void Lesson::timeInHoursAndMinutes() const {
    float h = round(this->getStartHour());
    if (h > this->getStartHour()) h -= 1;
    float m = (this->getStartHour() - h) * 60;
    if (h < 10 && m < 10) cout << "0" << h << ":" << "0" << m;
    else if (h < 10 && m > 10) cout << "0" << h << ":" << m;
    else if (h > 10 && m < 10) cout << h << ":" << "0" << m;
    else cout << h << ":" << m;
    cout << " - ";
    h = round(this->getEndHour());
    if (h > this->getEndHour()) h -= 1;
    m = (this->getEndHour() - h) * 60;
    if (h < 10 && m < 10) cout << "0" << h << ":" << "0" << m;
    else if (h < 10 && m > 10) cout << "0" << h << ":" << m;
    else if (h > 10 && m < 10) cout << h << ":" << "0" << m;
    else cout << h << ":" << m;
}

// O(1)
void Lesson::drawLesson() const {
    this->timeInHoursAndMinutes();
    cout << "  " << this->uc.getUcCode() << " | " << this->uc.getClassCode() << " (" << this->type << ");\n";
}

// O(1)
bool Lesson::lessonOverlap(const Lesson& lesson) {
    if (this->weekday != lesson.getWeekday()) {
        return false;
    }
    if ((this->startHour >= lesson.getEndHour()) || (this->endHour <= lesson.getStartHour())) {
        return false;
    }
    if (((this->type == "T") and (lesson.getType() == "TP")) ||
        ((this->type == "TP") and (lesson.getType() == "T")) ||
        ((this->type == "T") and (lesson.getType() == "T")) ||
        ((this->type == "T") and (lesson.getType() == "PL")) ||
        ((this->type == "PL") and (lesson.getType() == "T"))) {
        return false;
    }
    return true;
}

// O(1)
bool Lesson::operator<(const Lesson &l) const {
    return this->startHour < l.getStartHour();
}

// O(1)
bool Lesson::operator==(const Lesson &l) const {
    return this->uc.getClassCode() == l.getUc().getClassCode() && this->uc.getUcCode() == l.getUc().getUcCode() &&
            this->weekday == l.getWeekday() && this->startHour == l.getStartHour() &&
            this->duration == l.getDuration() && this->type == l.getType();
}

