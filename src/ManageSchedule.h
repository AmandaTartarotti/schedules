//ManageSchedule.h

#ifndef SCHEDULES_MANAGESCHEDULE_H
#define SCHEDULES_MANAGESCHEDULE_H

#include <string>
#include <set>
#include <queue>
#include <stack>
#include "Student.h"
#include "UcClass.h"
#include "Request.h"
using namespace std;

class ManageSchedule{
    private:
        set<Student> students;
        set<UcClass> classes;
        queue<Request> requests;
        stack<string> record;
    public:

        ManageSchedule() = default; // constructor
        void readStudentClasses(const string& path);
        void readClasses(const string& path);
        set<Student> getAllStudents() const;
        set<UcClass> getAllClasses() const;
        Student getStudent() const;
        UcClass getUcClass() const;
        void requestRemove(int option);
        void requestAdd(int option);
        void requestSwitch();
        void processRequests();
        void removeClassStudent(int numUp, const UcClass& class_);
        void addClassStudent(int numUp, const UcClass& class_);
        void accessRecord();
};

#endif //SCHEDULES_MANAGESCHEDULE_H
