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

bool Lecture::operator<(const Lecture &lecture) const {
    if (day == lecture.day) {
        if (startHour == lecture.startHour) {
            return duration < lecture.duration;
        }
        return startHour < lecture.startHour;
    }
    if (day == "Monday") {
        return (lecture.day == "Tuesday" or lecture.day == "Wednesday" or lecture.day == "Thursday" or lecture.day == "Friday" or lecture.day == "Saturday");
    }
    if (day == "Tuesday") {
        return (lecture.day == "Wednesday" or lecture.day == "Thursday" or lecture.day == "Friday" or lecture.day == "Saturday");
    }
    if (day == "Wednesday") {
        return (lecture.day == "Thursday" or lecture.day == "Friday" or lecture.day == "Saturday");
    }
    if (day == "Thursday") {
        return (lecture.day == "Friday" or lecture.day == "Saturday");
    }
    return lecture.day == "Saturday";
}