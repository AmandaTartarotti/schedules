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
    int size;
    vector<Lecture> lectureClass;
    set<Student> studentClass;
public:
    UcClass(const string& uccode_);
    string getUcCode();
    bool findLecture(string lectureCode_) const;
    Lecture getLecture(string lectureCode_) const;
    void getLectureAndIncrement(string lectureCode_);
    int getSize();
    void incrementSize();
    bool operator<(UcClass s) const;
    bool operator==(UcClass s);
    void addLecture(const Lecture& lecture);
    vector<Lecture> getLecture();
    set<Student> getStudents();
    void addStudent(Student &stud, string lectureCode_);
};

#endif //SCHEDULES_UCCLASS_H
