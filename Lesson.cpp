#include "Lesson.h"

#include <utility>

Lesson::Lesson(string UcCode, string ClassCode, string weekday, double startHour, double duration, string type) :  uc(std::move(UcCode), std::move(ClassCode)) {
    this->weekday = std::move(weekday);
    this->startHour = startHour;
    this->endHour = startHour + duration;
    this->duration = duration;
    this->type = std::move(type);
}

UC Lesson::getUc() const {
    return uc;
}

string Lesson::getWeekday() const {
    return this->weekday;
}

double Lesson::getStartHour() const {
    return this->startHour;
}

double Lesson::getEndHour() const {
    return this->endHour;
}

double Lesson::getDuration() const {
    return this->duration;
}

string Lesson::getType() const {
    return this->type;
}

void Lesson::drawLesson() const {
    cout << this->getStartHour() << " - " << this->getEndHour() << "  " << this->getUc().getUcCode() << "(" << this->getType() << ");\n";
}

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

bool Lesson::operator<(const Lesson &l) const {
    return this->startHour < l.getStartHour();
}

bool Lesson::operator==(const Lesson &l) const {
    return this->uc.getClassCode() == l.getUc().getClassCode() && this->uc.getUcCode() == l.getUc().getUcCode() &&
            this->weekday == l.getWeekday() && this->startHour == l.getStartHour() &&
            this->duration == l.getDuration() && this->type == l.getType();
}

