#include <iostream>
#include "Lecture.h"
using namespace std;

Lecture::Lecture(const string &lecturecode_, const std::string &day_, float startHour_, float duration_, const std::string &type_) {
    lecturecode = lecturecode_;
    day = day_;
    startHour = startHour_;
    duration = duration_;
    type = type_;
    numberStudents = 0;
}

bool Lecture::overlapsWith(const Lecture &otherLecture) const {
    // cout << day << " " << otherLecture.day << endl;
    if (day == otherLecture.day) {
        if (type == "T" && (otherLecture.type == "TP" || otherLecture.type == "T" || otherLecture.type == "PL")) {
            return false; // aulas não se sobrepõem para o tipo "T"
        } else if (type == "TP" && (otherLecture.type == "T")) {
            return false; // aulas não se sobrepõem para o tipo "T"
        } else {
            //cout << "entrei";
            //cout << startHour << " " << otherLecture.startHour << endl;
            // Verifica se a aula começa antes da outra terminar e termina após a outra começar
            if ((startHour == otherLecture.startHour) || (startHour < (otherLecture.startHour + otherLecture.duration) && (startHour + duration) > otherLecture.startHour)
             || (otherLecture.startHour < (startHour + duration) && (otherLecture.startHour + otherLecture.duration > startHour))){
                //cout << "sobrepos" << endl;
                return true; // Palestras se sobrepõem
            }
        }
    }
    return false; // Palestras não se sobrepõem
}

int Lecture::getNumberStudents() {
    return numberStudents;
}

void Lecture::incrementNumberStudents() {
    numberStudents += 1;
}

string Lecture::getLectureCode() const{
    return lecturecode;
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
}