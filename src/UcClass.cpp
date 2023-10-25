//UcClass.cpp

#include "UcClass.h"
#include "Student.h"

string UcClass::getClassNum() {
    return classnum;
}

string UcClass::getUcCode() {
    return uccode;
}

set<Student> UcClass::getClassStud() {
    return studentClass;
}

int UcClass::getSize() {
    return size;
}

void UcClass::incrementSize() {
    size += 1;
}

void UcClass::addStudent(Student s) {
    studentClass.insert(s);
    incrementSize();
}
