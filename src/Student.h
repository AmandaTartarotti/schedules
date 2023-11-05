//Student.h

#ifndef SCHEDULES_STUDENT_H
#define SCHEDULES_STUDENT_H

#include <string>
#include <iostream>
#include <set>
#include <utility>
#include <list>
#include "UcClass.h"
using namespace std;


class Student {
private:
    int code;
    string name;
    list<UcClass> classes;
public:
    /**
     * @brief constructor of a Student object
     */
    Student() = default;
    /**
     * @brief constructor of a Student object
     */
    Student(int code_): code(code_) {}
    /**
     * @brief constructor of a Student object
     */
    Student(int code_, string name_): code(code_), name(std::move(name_)) {}
    /**
     * @brief accesses the up code of a Student
     * @complexity O(1)
     */
    int getCode() const;
    /**
     * @brief accesses the name of a Student
     * @complexity O(1)
     */
    string getName() const;
    /**
     * @brief adds a UcClass to the classes list
     * @complexity O(1)
     */
    void addClass(const UcClass& class_);
    /**
     * @brief removes a UcClass from the classes list
     * @complexity O(n)
     */
    void removeClass(UcClass class_);
    /**
     * @brief accesses the classes of a Student
     * @complexity O(1)
     */
    list<UcClass> getClasses() const;
    /**
     * @brief defines the "<" operator to compare students by up code
     * @complexity O(1)
     */
    bool operator<(const Student& s) const;
    /**
    * @brief defines the ">" operator to compare students by up code
    * @complexity O(1)
    */
    bool operator>(const Student& s) const;
    /**
     * @brief checks if the students schedule has an available spot for a given lecture
     * @complexity O(n^2)
     */
    bool checkAvailability(Lecture lecture) const;
};


#endif //SCHEDULES_STUDENT_H
