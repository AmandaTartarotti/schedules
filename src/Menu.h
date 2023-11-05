#ifndef SCHEDULES_MENU_H
#define SCHEDULES_MENU_H

#include <iostream>
#include <iomanip>
#include "Student.h"
#include "ManageSchedule.h"

void printMenu();
void menuStudents(const ManageSchedule& schedule);
void menuSchedule(const ManageSchedule& schedule);
void printMenuRequest();

void showOccupation(const set<UcClass>& classes);
void printAllStudents(const set<Student>& student);
void printStudentsInClass(const set<Student>& students);
void printStudentSchedule(const set<Student>& students);
void printClassSchedule(const set<UcClass>& classes);
void printUcSchedule(const set<UcClass>& classes);
void studentsInAtLeastN_UCs(const set<Student>& student);

bool isNumber(const string &num);

#endif //SCHEDULES_MENU_H
