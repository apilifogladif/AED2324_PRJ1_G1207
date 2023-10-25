#ifndef AED2324_PRJ1_G1207_LESSON_H
#define AED2324_PRJ1_G1207_LESSON_H

#include <iostream>
#include <string>
#include "UC.h"

using namespace std;

// this class represents a lesson in the schedule
class Lesson {
    private:
        UC uc;
        string weekday;
        double startHour;
        double endHour;
        double duration;
        string type;
    public:
        Lesson(string ClassCode, int UcCode, string weekday, double startHour, double duration, string type);
        string getWeekday() const;
        double getStartHour() const;
        double getEndHour() const;
        double getDuration() const;
        string getType() const;
        void drawLesson() const;
};

#endif //AED2324_PRJ1_G1207_LESSON_H
