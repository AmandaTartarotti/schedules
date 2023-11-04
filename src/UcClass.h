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
public:
    UcClass(const string& uccode_, const string& classnum_);
    string getUcCode() const;
    string getClassNum() const;
    int getSize() const;
    void incrementSize();
    void decrementSize();
    bool operator<(UcClass s) const;
    bool operator==(UcClass s);
    void addLecture(const Lecture& lecture);
    vector<Lecture> getLecture() const;
};

#endif //SCHEDULES_UCCLASS_H