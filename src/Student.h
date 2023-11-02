//Student.h

#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include "UcClass.h"
using namespace std;


class Student {
private:
    int code;
    string name;
    vector<map<UcClass,string>> classes;            // guarda o objeto uc e a lectureCode
    vector<Lecture> lectures;                       // guarda os obejtos lectures e a UCcode
public:
    Student() = default;
    vector<Lecture> getLectures() const;
    Student(int code_): code(code_) {}
    Student(int code_, string name_): code(code_), name(std::move(name_)) {}
    int getCode() const;
    string getName() const;
    void addClass(UcClass class_, string lectureCode_);
    string removeClass(UcClass& class_);
    void printClasses();
    vector<map<UcClass,string>> getClasses() const;
    bool operator<(const Student& s) const;
    bool operator>(const Student& s) const;
    bool checkAvabialy(string UCcode, Lecture otherLecture) const;
};


#endif //SCHEDULES_STUDENT_H
