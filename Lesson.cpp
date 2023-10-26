#include "Lesson.h"

Lesson::Lesson(string ClassCode, int UcCode, string weekday, double startHour, double duration, string type) {
    this->uc = UC(ClassCode, UcCode);
    this->weekday = weekday;
    this->startHour = startHour;
    this->endHour = startHour + duration;
    this->duration = duration;
    this->type = type;
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
    cout << lesson.getstartHour() << " - " << lesson.getendHour() << "  " << uc.getUcCode << "(" << lesson.getType << ");\n";
}