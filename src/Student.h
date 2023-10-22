//Student.h

#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <string>
#include <iostream>
#include <set>
#include <utility>
#include "ManageSchedule.h"

using namespace std;
class ManageSchedule;

class Student {
private:
    int code;
    string name;
public:
    Student() = default;
    Student(int code_): code(code_) {}
    Student(int code_, string name_): code(code_), name(std::move(name_)) {}
    int getCode() const {return code;};
    string getName() const {return name;};
    bool operator<(const Student& s) const;
};


#endif //SCHEDULES_STUDENT_H
