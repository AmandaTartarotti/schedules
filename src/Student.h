//Student.h

#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <string>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include "UcClass.h"
using namespace std;


class Student {
private:
    int code;
    string name;
    vector<UcClass> classes;
public:
    Student() = default;
    Student(int code_): code(code_) {}
    Student(int code_, string name_): code(code_), name(std::move(name_)) {}
    int getCode() const;
    string getName() const;
    void addClass(const UcClass& class_);
    void printClasses();
    vector<UcClass> getClasses() const;
    bool operator<(const Student& s) const;
};


#endif //SCHEDULES_STUDENT_H
