//Student.h

#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <string>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

class Student {
private:
    int code;
    string name;
public:
    Student() = default;
    Student(int code_): code(code_) {}
    Student(int code_, string name_): code(code_), name(std::move(name_)) {}
    int getCode() const;
    string getName() const;
    bool operator<(const Student& s) const;
};


#endif //SCHEDULES_STUDENT_H
