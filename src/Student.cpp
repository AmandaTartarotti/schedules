
#include "Student.h"
using namespace std;

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}

bool Student::operator>(const Student &s) const {
    return code > s.getCode();
}

void Student::addLecture(Lecture lecture_){
    lectures.push_back(lecture_);
}

vector<Lecture> Student::getLectures() const{
    return lectures;
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


void Student::printClasses() {
    for (UcClass class_ : classes) {
        cout << class_.getUcCode() << endl;
    }
}

vector<UcClass> Student::getClasses() const {
    return classes;
}
