#include <algorithm>
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
    } else{
        const std::string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        auto it1 = std::find(std::begin(days), std::end(days), day);
        auto it2 = std::find(std::begin(days), std::end(days), lecture.day);

        if (it1 != std::end(days) && it2 != std::end(days)) {
            return std::distance(std::begin(days), it1) < std::distance(std::begin(days), it2);
        }
    }
    return false;
}

bool Lecture::overlapsWith(const Lecture &lecture) {
    if (day == lecture.day) {
        if (type == "T" and (lecture.type == "TP" or lecture.type == "T" or lecture.type == "PL")) {
            return false;
        } else if (type == "TP" and (lecture.type == "T")) {
            return false;
        } else {
            if ((startHour == lecture.startHour) or (startHour < (lecture.startHour + lecture.duration) and (startHour + duration) > lecture.startHour)
                or (lecture.startHour < (startHour + duration) && (lecture.startHour + lecture.duration > startHour))){
                return true;
            }
        }
    }
    return false;
}