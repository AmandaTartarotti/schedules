//Student.cpp
#include "Student.h"

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}

bool Student::operator>(const Student &s) const {
    return code > s.getCode();
}


int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

void Student::addClass(const UcClass& class_) {
    classes.push_back(class_);
}

void Student::printClasses() {
    for (UcClass class_ : classes) {
        cout << class_.getUcCode() << " " << class_.getClassNum() << "\n";
    }
}

vector<UcClass> Student::getClasses() const {
    return classes;
}
