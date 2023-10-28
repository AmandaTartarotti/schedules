//UcClass.h

#ifndef SCHEDULES_UCCLASS_H
#define SCHEDULES_UCCLASS_H

#include <utility>
#include <string>
#include <set>
#include <vector>
#include "Lecture.h"
using namespace std;
class Student;

class UcClass {
private:
    string uccode;
    string classnum;
    int size;
    set<Student> studentClass;
    vector<Lecture> lectureClass;
public:
    UcClass(const string& uccode_, const string& classnum_);
    string getUcCode();
    string getClassNum();
    void addStudent(Student s);
    int getSize();
    set<Student> getClassStud();
    void incrementSize();
    bool operator<(UcClass s) const;
    void addLecture(const Lecture& lecture);
    vector<Lecture> getLecture();
};

#endif //SCHEDULES_UCCLASS_H
