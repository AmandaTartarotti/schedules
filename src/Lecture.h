
#ifndef SCHEDULES_LECTURE_H
#define SCHEDULES_LECTURE_H

#include <string>
using namespace std;

class Lecture {
private:
    string day, type;
    float startHour, duration;
public:
    Lecture(const string& day_, float startHour_, float duration_, const string& type_);
    string getDay() const;
    string getType() const;
    float getStartHour() const;
    float getDuration() const;
    bool operator<(const Lecture &lecture) const;
    bool overlapsWith(const Lecture &lecture);
};

#endif //SCHEDULES_LECTURE_H
