//UcClass.cpp

#include "UcClass.h"
#include "Student.h"

UcClass::UcClass(const string &uccode_, const string &classnum_) {
    uccode = uccode_;
    classnum = classnum_;
    size = 0;
}

string UcClass::getClassNum() const{
    return classnum;
}

string UcClass::getUcCode() const{
    return uccode;
}

int UcClass::getSize() {
    return size;
}

void UcClass::incrementSize() {
    size += 1;
}

bool UcClass::operator<(UcClass s) const {
    if (uccode == s.getUcCode()) {
        return classnum < s.getClassNum();
    }
    return uccode < s.getUcCode();
}

void UcClass::addLecture(const Lecture& lecture) {
    lectureClass.push_back(lecture);
}

vector<Lecture> UcClass::getLecture() const {
    return lectureClass;
}

bool UcClass::operator==(UcClass s) {
    return uccode == s.getUcCode() and classnum == s.getClassNum();
}

void UcClass::decrementSize() {
    size -= 1;
}
