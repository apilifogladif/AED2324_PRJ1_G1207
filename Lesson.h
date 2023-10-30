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
        /*
         * Class constructor
         *
         * Sets ClassCode, UcCode, weekday, startHour, endHour (startHour + duration) and type
         *
         * @paramt ClassCode : private , Class code;
         * @paramt UcCode : private , Curricular unit code;
         * @paramt weekday : private , Day of the week when the lesson happens;
         * @paramt startHour : private , Lesson start time;
         * @paramt duration : private , Lesson duration;
         * @paramt type : private , Lesson type;
         */
        Lesson(string UcCode, string ClassCode, string weekday, double startHour, double duration, string type);
        /*
         * Returns the uc
         */
        UC getUc() const;

        /*
         * Returns the weekday of the lesson
         */
        string getWeekday() const;

        /*
         * Returns the startHour of the lesson
         */
        double getStartHour() const;

        /*
         * Returns the endHour of the lesson
         */
        double getEndHour() const;

        /*
         * Return the duration of the lesson
         */
        double getDuration() const;

        /*
         * Returns the type of the lesson (T, P, PL)
         */
        string getType() const;

        /*
         * Prints the startHour, the endHour and the type of the lesson (T, TP, PL)
         */
        void drawLesson() const;

        /*
         * Checks if two classes are compatible
         *
         * @paramt lesson : lesson;
         */
        bool lessonOverlap(const Lesson& lesson);

        /*
         * Operator to compare the times of two Lessons
         *
         * @paramt l : lesson;
         */
        bool operator<(const Lesson& l) const;
};

#endif //AED2324_PRJ1_G1207_LESSON_H
