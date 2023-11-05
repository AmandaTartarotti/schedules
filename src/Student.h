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
     * @brief Constructor of a Student object
     */
    Student() = default;
    /**
     * @brief Constructor of a Student object
     * @param code_
     */
    Student(int code_): code(code_) {}
    /**
     * @brief Constructor of a Student object
     * @param code_
     * @param name_
     */
    Student(int code_, string name_): code(code_), name(std::move(name_)) {}
    /**
     * @brief Acesses the up code of a Student
     * @complexity O(1)
     */
    int getCode() const;
    /**
     * @brief Acesses the name of a Student
     * @complexity O(1)
     */
    string getName() const;
    /**
     * @brief Adds a UcClass to the classes list
     * @complexity O(1)
     */
    void addClass(const UcClass& class_);
    /**
     * @brief Removes a UcClass from the classes list
     * @complexity O(n)
     */
    void removeClass(UcClass class_);
    /**
     * @brief Acesses the classes of a Student
     * @complexity O(1)
     */
    list<UcClass> getClasses() const;
    /**
     * @brief Defines the "<" operator to compare students by up code
     * @complexity O(1)
     */
    bool operator<(const Student& s) const;
    /**
    * @brief Defines the ">" operator to compare students by up code
    * @complexity O(1)
    * @return The larger of the students' up code
    */
    bool operator>(const Student& s) const;
    /**
     * @brief Checks if the students schedule has an available spot for a given lecture
     * @param lecture
     * @return true if there is a spot available and false if not
     * @complexity O(n^2)
     */
    bool checkAvailability(Lecture lecture) const;
};


#endif //SCHEDULES_STUDENT_H
