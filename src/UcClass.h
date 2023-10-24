//UcClass.h

#ifndef SCHEDULES_UCCLASS_H
#define SCHEDULES_UCCLASS_H

#include <utility>
#include <string>
#include <set>
#include "Student.h"
using namespace std;

class UcClass {
private:
    string uccode;
    string classnum;
    int size = 1;
    set<Student> studentClass;
public:
    UcClass(const string& uccode_, const string& classnum_): uccode(uccode_), classnum(classnum_) {}
    string getUcCode();
    string getClassNum();
    void addStudent(Student s);
    int getSize();
    set<Student> getStudents();
    void incrementSize();
};

#endif //SCHEDULES_UCCLASS_H
