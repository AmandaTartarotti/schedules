
#ifndef SCHEDULES_LECTURE_H
#define SCHEDULES_LECTURE_H

#include <string>
#include <algorithm>
using namespace std;

class Lecture {
private:
    int numberStudents;
    string day, type, lecturecode;
    float startHour, duration;
public:
    Lecture(const string &lecturecode_, const string& day_, float startHour_, float duration_, const string& type_);
    int getNumberStudents();
    void incrementNumberStudents();
    string getDay() const;
    string getType() const;
    string getLectureCode() const;
    float getStartHour() const;
    float getDuration() const;
    bool operator<(const Lecture &lecture) const;
    bool overlapsWith(const Lecture &otherLecture) const;
};

#endif //SCHEDULES_LECTURE_H
