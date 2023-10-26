#ifndef AED2324_PRJ1_G1207_SCHEDULE_H
#define AED2324_PRJ1_G1207_SCHEDULE_H

#include "Lesson.h"
#include <iostream>
#include <vector>
#include <set>
#include <set>
using namespace std;

// this class represents a schedule
class Schedule {
    private:
        set<Lesson> lessons;
    public:
    /*
     * Class constructor
     *
     * Sets lessons
     *
     * @paramt lessons : private , Lessons to allocate to the students;
     */
        Schedule(set<Lesson> lessons);

        /*
         * Adds a lesson to the schedule
         */
        void addLesson(const Lesson lesson);

        /*
         * Removes a lesson from the schedule
         */
        void removeLesson(const Lesson lesson);

        /*
         * Returns a lesson from the schedule
         */
        set<Lesson> getLesson() const;

        /*
         * Prints the schedule
         */
        void drawSchedule() const;

};

#endif //AED2324_PRJ1_G1207_SCHEDULE_H
