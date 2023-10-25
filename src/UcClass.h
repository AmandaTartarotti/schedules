//UcClass.h

#ifndef SCHEDULES_UCCLASS_H
#define SCHEDULES_UCCLASS_H

#include <utility>
#include <string>
#include <set>
using namespace std;
class Student;

class UcClass {
private:
    string uccode;
    string classnum;
    int size;
    set<Student> studentClass;
public:
    UcClass(const string& uccode_, const string& classnum_): uccode(uccode_), classnum(classnum_) {size = 0;}
    string getUcCode();
    string getClassNum();
    void addStudent(Student s);
    int getSize();
    set<Student> getClassStud();
    void incrementSize();
};

#endif //SCHEDULES_UCCLASS_H
