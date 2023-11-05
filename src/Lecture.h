
#ifndef SCHEDULES_LECTURE_H
#define SCHEDULES_LECTURE_H

#include <string>
using namespace std;

class Lecture {
private:
    string day, type;
    float startHour, duration;
public:
    /**
     * @brief the constructor of an object Lecture.
     */
    Lecture(const string& day_, float startHour_, float duration_, const string& type_);
    /**
     * @brief accesses the day of a lecture.
     * @complexity O(1)
     */
    string getDay() const;
    /**
     * @brief accesses the type of a lecture.
     * @complexity O(1)
     */
    string getType() const;
    /**
     * @brief accesses the start hour of a lecture.
     * @complexity O(1)
     */
    float getStartHour() const;
    /**
     * @brief accesses the duration of a lecture.
     * @complexity O(1)
     */
    float getDuration() const;
    /**
     * @brief defines the "<" operator and return each lecture starts earlier or has the smallest duration
     * @complexity O(1)
     */
    bool operator<(const Lecture &lecture) const;
    /**
     * @brief check if the schedule of a given lecture overlaps another one.
     * @complexity O(1)
     */
    bool overlapsWith(const Lecture &lecture);
};

#endif //SCHEDULES_LECTURE_H