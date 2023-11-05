
#ifndef SCHEDULES_LECTURE_H
#define SCHEDULES_LECTURE_H

#include <string>
using namespace std;

class Lecture {
private:
    string day, type;
    float startHour, duration;
public:
    //TODO
    /**
     * @brief the constructor of an object Lecture.
     */
    Lecture(const string& day_, float startHour_, float duration_, const string& type_);
    //TODO
    /**
     * @brief accesses the day of a lecture.
     *  Complexity O(1)
     */
    string getDay() const;
    //TODO
    /**
     * @brief accesses the type of a lecture.
     *  Complexity O(1)
     */
    string getType() const;
    //TODO
    /**
     * @brief accesses the start hour of a lecture.
     *  Complexity O(1)
     */
    float getStartHour() const;
    //TODO
    /**
     * @brief accesses the duration of a lecture.
     *  Complexity O(1)
     */
    float getDuration() const;
    //TODO
    /**
<<<<<<< HEAD
     * @brief defines de < operator and return each lecture starts earlier or has the smallest duration.
     *  Complexity O(1)
=======
     * @brief defines the "<" operator and return each lecture starts earlier or has the smallest duration
     * @complexity O(1)
>>>>>>> 4d02ae83edd2c6d180bd437b206df1419ec985a0
     */
    bool operator<(const Lecture &lecture) const;
    //TODO
    /**
     * @brief check if the schedule of a given lecture overlaps another one.
     *  Complexity O(1)
     */
    bool overlapsWith(const Lecture &lecture);
};

#endif //SCHEDULES_LECTURE_H