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
    vector<Lecture> lectureClass;
    set<Student> studentClass;
public:
    UcClass(const string& uccode_, const string& classnum_);
    string getUcCode();
    string getClassNum();
    int getSize();
    void incrementSize();
    bool operator<(UcClass s) const;
    bool operator==(UcClass s);
    void addLecture(const Lecture& lecture);
    vector<Lecture> getLecture();
    set<Student> getStudents();
    void addStudent(const Student& stud);
};

#endif //SCHEDULES_UCCLASS_H
