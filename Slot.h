//
// Created by filipag on 24-10-2023.
//

#ifndef AED2324_PRJ1_G1207_SLOT_H
#define AED2324_PRJ1_G1207_SLOT_H

#include <string>
using namespace std;

class Slot {
    private:
        string weekday;
        double startHour;
        double endHour;
        double duration;
        string type;
    public:
        Slot(string weekday, double startHour, double endHour, double duration, string type);
        string getWeekday() const;
        double getStartHour() const;
        double getEndHour() const;
        double getDuration() const;
        string getType() const;
};

#endif //AED2324_PRJ1_G1207_SLOT_H
