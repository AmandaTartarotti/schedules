#ifndef SCHEDULES_MENU_H
#define SCHEDULES_MENU_H

#include <iostream>
#include <iomanip>
#include "Student.h"
#include "ManageSchedule.h"

//TODO
/**
 * @brief prints the basic menu for the user.
 *  Complexity O(1)
 */
void printMenu();
//TODO
/**
 * @brief prints a menu that allows the user to check the amount of students in different situations.
 *  Complexity O(1)
 */
void menuStudents(const ManageSchedule& schedule);
//TODO
/**
 * @brief prints a menu that allows the user to consult the schedule of a student, class or uc.
 *  Complexity O(1)
 */
void menuSchedule(const ManageSchedule& schedule);
//TODO
/**
 * @brief prints a menu that allows the user to choose between different requests options.
 *  Complexity O(1)
 */
void printMenuRequest();
//TODO
/**
 * @brief allows the user to choose between different sorting options.
 *  Complexity O(n * log(n))
 */
void printAllStudents(const set<Student>& student);
//TODO
/**
 * @brief access the students of an especific class and call printAllStudents to print them.
 *  Complexity O(n^2)
 */
void printStudentsInClass(const set<Student>& students);
//TODO
/**
 * @brief access the students of an especific UC and call printAllStudents to print them.
 *  Complexity O(n^2)
 */
void printStudentsInUC(const set<Student>& students);
//TODO
/**
 * @brief count the amount of students registered in at least N UC's and prints it.
  *  Complexity O(n)
 */
void studentsInAtLeastN_UCs(const set<Student>& student);
//TODO
/**
 * @brief builds the schedule of a student and prints it.
  *  Complexity O(n + n^2 + log(n))
 */
void printStudentSchedule(const set<Student>& students);
//TODO
/**
 * @brief builds the schedule of a class and prints it.
  *  Complexity O(n + n^2)
 */
void printClassSchedule(const set<UcClass>& classes);
//TODO
/**
 * @brief builds the schedule of a UC and prints it.
  *  Complexity O(n + n^2)
 */
void printUcSchedule(const set<UcClass>& classes);
//TODO
/**
 * @brief prints a menu that allows the user to consult the occupation of a class or uc.
  *  Complexity O(1)
 */
void printMenuOccupation();
//TODO
/**
 * @brief calculates how many students are enrolled in a UC and prints this value
  *  Complexity O(n)
 */
void showOccupationUc(const set<UcClass>& classes);
//TODO
/**
 * @brief calculates how many students are enrolled in a class and prints this value
  *  Complexity O(log n)
 */
void showOccupation(const set<UcClass>& classes);
//TODO
/**
 * @brief checks it all characters of a string are numeric values
  *  Complexity O(n)
 */
bool isNumber(const string &num);

#endif //SCHEDULES_MENU_H
