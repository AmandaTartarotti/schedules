
#ifndef SCHEDULES_LECTURE_H
#define SCHEDULES_LECTURE_H

#include <string>
#include <algorithm>
using namespace std;

class Lecture {
private:
    string day, type, lecturecode;
    float startHour, duration;
public:
    Lecture(const string &lecturecode_, const string& day_, float startHour_, float duration_, const string& type_);
    string getDay() const;
    string getType() const;
    string getLectureCode() const;
    float getStartHour() const;
    float getDuration() const;
    bool operator<(const Lecture &lecture) const;
};

#endif //SCHEDULES_LECTURE_H
