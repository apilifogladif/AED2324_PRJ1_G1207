#ifndef AED2324_PRJ1_G1207_SCHEDULE_H
#define AED2324_PRJ1_G1207_SCHEDULE_H

#include "Lesson.h"
#include <iostream>
#include <vector>
#include <set>

namespace using std;

// this class represents a schedule
class Schedule {
    private:
        set<Lesson> lessons;
    public:
        Schedule(set<Lesson> lessons);
        void addLesson(const Lesson lesson);
        void removeLesson(const Lesson lesson);
        set<Lesson> getLesson() const;
        void drawSchedule() const;

};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
