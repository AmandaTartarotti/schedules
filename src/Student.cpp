//Student.cpp
#include "Student.h"

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}

bool Student::operator>(const Student &s) const {
    return code > s.getCode();
}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

void Student::addClass(const UcClass& class_) {
    classes.push_back(class_);
}

list<UcClass> Student::getClasses() const {
    return classes;
}

void Student::removeClass(UcClass class_) {
    list<UcClass>::iterator itr;
    for (itr = classes.begin(); itr != classes.end(); itr++)
        if (itr->getUcCode() == class_.getUcCode() && itr->getClassNum() == class_.getClassNum()) {
            break;
        }
    classes.erase(itr);
}

bool Student::checkAvailability(Lecture lecture) const {
    for (UcClass class_ : classes) {
        for (Lecture scheduleLecture : class_.getLecture()) {
            if (scheduleLecture.overlapsWith(lecture)) {
                return false;
            }
        }
    }
    return true;
}

