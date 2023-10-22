//Student.cpp
#include "Student.h"

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}