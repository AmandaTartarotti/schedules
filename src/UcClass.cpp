//UcClass.cpp

#include "UcClass.h"
#include "Student.h"

UcClass::UcClass(const string &uccode_, const string &classnum_) {
    uccode = uccode_;
    classnum = classnum_;
    size = 0;
}

string UcClass::getClassNum() {
    return classnum;
}

string UcClass::getUcCode() {
    return uccode;
}

set<Student> UcClass::getClassStud() {
    return studentClass;
}

int UcClass::getSize() {
    return size;
}

void UcClass::incrementSize() {
    size += 1;
}

void UcClass::addStudent(Student s) {
    studentClass.insert(s);
    incrementSize();
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

vector<Lecture> UcClass::getLecture() {
    return lectureClass;
}

