#ifndef AED2324_PRJ1_G1207_LESSON_H
#define AED2324_PRJ1_G1207_LESSON_H

#include <iostream>
#include <string>
#include "UC.h"
#include <cmath>
#include <iomanip>

using namespace std;

// this class represents a lesson in the schedule
class Lesson {
    private:
        UC uc;
        string weekday;
        float startHour;
        float endHour;
        float duration;
        string type;
    public:
        /**
         * Class constructor
         *
         * Sets ClassCode, UcCode, weekday, startHour, endHour (startHour + duration) and type
         *
         * @param ClassCode : private , Class code;
         * @param UcCode : private , Curricular unit code;
         * @param weekday : private , Day of the week when the lesson happens;
         * @param startHour : private , Lesson start time;
         * @param duration : private , Lesson duration;
         * @param type : private , Lesson type;
         */
        Lesson(string UcCode, string ClassCode, string weekday, float startHour, float duration, string type);

        /**
         * Returns the uc
         *
         * @return uc
         */
        UC getUc() const;

        /**
         * Returns the weekday of the lesson
         *
         * @return weekday
         */
        string getWeekday() const;

        /**
         * Returns the startHour of the lesson
         *
         * @return startHour
         */
        float getStartHour() const;

        /**
         * Returns the endHour of the lesson
         *
         * @return endHour
         */
        float getEndHour() const;

        /**
         * Return the duration of the lesson
         *
         * @return duration
         */
        float getDuration() const;

        /**
         * Returns the type of the lesson
         *
         * @return string with type : T,P,PL or TP
         */
        string getType() const;

        /**
         * Convert the decimal time to a string
         */
        void timeInHoursAndMinutes() const;

        /**
         * Prints the startHour, the endHour and the type of the lesson (T, TP, PL)
         */
        void drawLesson() const;

        /**
         * Checks if two classes are compatible
         *
         * @param lesson : lesson;
         * @return bool : true or false
         */
        bool lessonOverlap(const Lesson& lesson);

        /**
         * Operator to compare the times of two Lessons
         *
         * @param l : lesson;
         * @return bool : true or false
         */
        bool operator<(const Lesson& l) const;

        /**
         * Operator to compare equality between two lessons
         *
         * @param l : lesson;
         * @return bool : true or false
         */
        bool operator==(const Lesson& l) const;
};

#endif //AED2324_PRJ1_G1207_LESSON_H
