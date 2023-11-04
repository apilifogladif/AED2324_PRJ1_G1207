#ifndef AED2324_PRJ1_G1207_LESSON_H
#define AED2324_PRJ1_G1207_LESSON_H

#include <iostream>
#include <string>
#include "UC.h"
#include <cmath>
#include <iomanip>

using namespace std;

// this class represents a lesson in the schedule
/**
 * @file Lesson.h
 * @brief Class that represents a lesson
 */
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
         * @brief Lesson::Lesson
         * Class constructor
         *
         * Complexity: O(1)
         *
         * @param ClassCode : Class code;
         * @param UcCode : Uc code;
         * @param weekday : Day of the week when the lesson happens;
         * @param startHour : Lesson start time;
         * @param duration : Lesson duration;
         * @param type : Lesson type.
         */
        Lesson(string UcCode, string ClassCode, string weekday, float startHour, float duration, string type);

        /**
         * @brief Lesson::getUc
         * Gets the uc
         *
         * Complexity: O(1)
         *
         * @return The Uc of the lesson.
         */
        UC getUc() const;

        /**
         * @brief Lesson::getWeekday
         * Gets the weekday of the lesson
         *
         * Complexity: O(1)
         *
         * @return The weekday the lesson is in.
         */
        string getWeekday() const;

        /**
         * @brief Lesson::getStartHour
         * Gets the startHour of the lesson
         *
         * Complexity: O(1)
         *
         * @return The lesson's start time.
         */
        float getStartHour() const;

        /**
         * @brief Lesson::getEndHour
         * Gets the endHour of the lesson
         *
         * Complexity: O(1)
         *
         * @return The lesson's end time.
         */
        float getEndHour() const;

        /**
         * @brief Lesson::getDuration
         * Gets the duration of the lesson
         *
         * Complexity: O(1)
         *
         * @return The lesson's duration.
         */
        float getDuration() const;

        /**
         * @brief Lesson::getType
         * Gets the type of the lesson
         *
         * Complexity: O(1)
         *
         * @return The type of the lesson (T,P,PL or TP).
         */
        string getType() const;

        /**
         * @brief Lesson::timeInHoursAndMinutes
         * Convert the decimal time to a string
         *
         * Complexity: O(1)
         */
        void timeInHoursAndMinutes() const;

        /**
         * @brief Lesson::drawLesson
         * Prints ??
         *
         * Complexity: O(1)
         */
        void drawLesson() const;

        /**
         * @brief Lesson::lessonOverlap
         * Checks if two classes are compatible
         *
         * Complexity: O(1)
         *
         * @param lesson : The lesson that we are checking if overlaps;
         * @return true or false.
         */
        bool lessonOverlap(const Lesson& lesson);

        /**
         * @brief Lesson::operator<
         * Operator to compare the times of two Lessons
         *
         * Complexity: O(1)
         *
         * @param l : The Lesson we are comparing;
         * @return true or false.
         */
        bool operator<(const Lesson& l) const;

        /**
         * @brief Lesson::operator==
         * Operator to compare equality between two lessons
         *
         * Complexity: O(1)
         *
         * @param l : The Lesson we are comparing;
         * @return true or false.
         */
        bool operator==(const Lesson& l) const;
};

#endif //AED2324_PRJ1_G1207_LESSON_H
