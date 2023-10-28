#include "Lecture.h"
using namespace std;

Lecture::Lecture(const std::string &day_, float startHour_, float duration_, const std::string &type_) {
    day = day_;
    startHour = startHour_;
    duration = duration_;
    type = type_;
}

string Lecture::getDay() const {
    return day;
}

string Lecture::getType() const {
    return type;
}

float Lecture::getStartHour() const {
    return startHour;
}

float Lecture::getDuration() const {
    return duration;
}



