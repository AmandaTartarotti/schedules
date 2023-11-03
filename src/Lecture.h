
#ifndef SCHEDULES_LECTURE_H
#define SCHEDULES_LECTURE_H

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Lecture {
private:
    int numberStudents;
    string day, type, ucCode, lecturecode;
    float startHour, duration;
public:
    Lecture(const string &ucCode, const string &lecturecode_, const string& day_, float startHour_, float duration_, const string& type_);
    int getNumberStudents();
    void incrementNumberStudents();
    void decreaseNumberStudents();
    string getDay() const;
    string getType() const;
    string getLectureCode() const;
    string getUCCode() const;
    float getStartHour() const;
    float getDuration() const;
    bool operator<(const Lecture &lecture) const;
    bool operator==(const Lecture& otherLecture) const;
    bool overlapsWith(const Lecture &otherLecture) const;
};

#endif //SCHEDULES_LECTURE_H
