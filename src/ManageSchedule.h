//ManageSchedule.h

#ifndef SCHEDULES_MANAGESCHEDULE_H
#define SCHEDULES_MANAGESCHEDULE_H

#include <string>
#include <set>
#include "Student.h"
#include "UcClass.h"
using namespace std;

class ManageSchedule{
    private:
        set<Student> students;
        set<UcClass> classes;
    public:
        ManageSchedule() = default; // constructor
        void readStudentClasses(const string& path);
        void readClasses(const string& path);
        set<Student> getAllStudents();
        set<UcClass> getAllClasses();
};

#endif //SCHEDULES_MANAGESCHEDULE_H
