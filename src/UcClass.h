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
    string getUcCode() const;
    bool findLecture(string lectureCode_) const;
    void getLectureAndIncrement(string lectureCode_);
    int getSize();
    void incrementSize();
    void decreaseSize();
    bool operator<(UcClass s) const;
    bool operator==(UcClass s);
    void addLecture(Lecture lecture);
    vector<Lecture> getLecture();
    set<Student> getStudents();
    void addStudent(Student &stud, string lectureCode_);
    string newStudent(Student &student);
    bool findStudent(int upCode) const;
    void removeStudent(Student &dropout);
    void newClass(Student &rockStar, string desired);
    void removeStudentClass(Student &dropout, string desired);
    };

#endif //SCHEDULES_UCCLASS_H
