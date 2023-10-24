//Student.cpp
#include "Student.h"

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}