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
        /**
         * Default constructor.
         */
        ManageSchedule() = default;
        /**
         * @brief Reads and saves all students from the file 'students_classes.csv' in the private field 'students'.
         * @complexity O(n * log n)
         */
        void readStudentClasses(const string& path);
        /**
         * @brief Reads and saves all classes and lectures from the file 'classes.csv' in the private field 'classes'.
         * @complexity O(n * log n)
         */
        void readClasses(const string& path);
        /**
         * @brief accesses the field 'students' with all the students.
         * @complexity O(1)
         */
        set<Student> getAllStudents() const;
        /**
         * @brief accesses the field 'classes' with all the classes.
         * @complexity O(1)
         */
        set<UcClass> getAllClasses() const;
        /**
         * @brief finds a student inside 'students' by requesting the student's number.
         * @complexity O(log n)
         */
        Student getStudent() const;
        /**
         * @brief creates a class by requesting its UC code and class number.
         * @complexity O(1)
         */
        UcClass getUcClass() const;
        /**
         * @brief creates a request to remove a student from a class if that student is enrolled in that class.
         * @complexity O(n)
         */
        void requestRemove(int option);
        /**
         * @brief creates a request to add a student to a class if that class exists.
         * @complexity O(n)
         */
        void requestAdd(int option);
        /**
         * @brief creates a request to switch a student from a class that he is enrolled to another class in 'classes'.
         * @complexity O(n)
         */
        void requestSwitch();
        /**
         * @brief processes one or all the requests in the 'requests' queue.
         * @complexity O(n) if all the requests are processed. Otherwise, O(1)
         */
        void processRequests();
        /**
         * @brief searches the class in 'classes', the student in 'students' and removes that class from the student
         * @complexity O(log n)
         */
        void removeClassStudent(int numUp, const UcClass& class_);
        /**
         * @brief searches the class in 'classes', the student in 'students' and adds the class to a student if that class does not overlap other classes in the student's schedule, if the student is not enrolled in 7 or more UCs, if the class does not have more than 27 or more students and if the change does not unbalances the class occupation
         * @complexity O(n)
         */
        void addClassStudent(int numUp, const UcClass& class_);
        /**
         * @brief prints all the results of processing the requests.
         * @complexity O(n), being 'n' the number of requests.
         */
        void accessRecord();
        /**
         * @brief rewrites 'students_classes.csv' to maintain all the successful request
         * @complexity O(n^2)
         */
         void write(const string& path) const;
};

#endif //SCHEDULES_MANAGESCHEDULE_H
