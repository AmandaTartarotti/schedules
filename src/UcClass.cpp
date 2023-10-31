//UcClass.cpp

#include "UcClass.h"
#include "Student.h"

UcClass::UcClass(const string &uccode_): lectureClass(), studentClass() {
    uccode = uccode_;
    size = 0;
}

void UcClass::getLectureAndIncrement(string lectureCode_) { //busca a referencia de uma lecture
    for (auto element : lectureClass){
        if (element.getLectureCode() == lectureCode_) {
            element.incrementNumberStudents();
        }
    }
}


bool UcClass::findLecture(string lectureCode_) const {
    for (auto element : lectureClass){
        if (element.getLectureCode() == lectureCode_)
            return true;
    }
    return false;
}

string UcClass::getUcCode() {
    return uccode;
}


int UcClass::getSize() {
    return size;
}

void UcClass::incrementSize() {
    size += 1;
}


bool UcClass::operator<(UcClass s) const {
    return uccode < s.getUcCode();
}

void UcClass::addLecture(const Lecture& lecture) {
    lectureClass.push_back(lecture);
}

vector<Lecture> UcClass::getLecture() {
    return lectureClass;
}


bool UcClass::operator==(UcClass s) {
    return uccode == s.getUcCode();
}

void UcClass::addStudent(const Student& stud) {
    studentClass.insert(stud);
}

set<Student> UcClass::getStudents() {
    return studentClass;
}


