#include "Lesson.h"

// class constructor that sets weekday, startHour, endHour(startHour + duration) and type
Lesson::Lesson(string ClassCode, int UcCode, string weekday, double startHour, double duration, string type) {
    this->uc = UC(ClassCode, UcCode);
    this->weekday = weekday;
    this->startHour = startHour;
    this->endHour = startHour + duration;
    this->duration = duration;
    this->type = type;
}

// returns the weekday of the lesson
string Lesson::getWeekday() const {
    return this->weekday;
}

// return the startHour of the lesson
double Lesson::getStartHour() const {
    return this->startHour;
}

// return the endHour of the lesson
double Lesson::getEndHour() const {
    return this->endHour;
}

// return the duration of the lesson
double Lesson::getDuration() const {
    return this->duration;
}

// return the type of the lesson (T, P, PL)
string Lesson::getType() const {
    return this->type;
}

// print startHour, endHour and type of the lesson
void Lesson::drawLesson() const {
    cout << lesson.getstartHour() << " - " << lesson.getendHour() << "  " << uc.getUcCode << "(" << lesson.getType << ");\n";
}