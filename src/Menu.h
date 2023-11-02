//
// Created by amand on 30/10/2023.
//

#ifndef SCHEDULES_MENU_H
#define SCHEDULES_MENU_H

#include <iostream>
#include <iomanip>
#include "Student.h"

void printMenu();
void printAllStudents(const set<Student>& student);
void printStudentsInClass(const set<UcClass>& classes);
void printScheduleStudent(Student student);
void printScheduleClass(UcClass class_);


#endif //SCHEDULES_MENU_H
