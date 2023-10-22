//ManageSchedule.h

#ifndef SCHEDULES_MANAGESCHEDULE_H
#define SCHEDULES_MANAGESCHEDULE_H

#include <string>
#include "Student.h"

using namespace std;
class Student;

class ManageSchedule{
    private:
        set<Student> students;
    public:
        ManageSchedule() = default; // constructor
        void readStudentClasses(const string& path);
        void readClasses(const string& path);
        void readClassesPerUc(const string& path);

};

#endif //SCHEDULES_MANAGESCHEDULE_H
