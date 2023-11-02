//ManageSchedule.h

#ifndef SCHEDULES_MANAGESCHEDULE_H
#define SCHEDULES_MANAGESCHEDULE_H

#include <string>
#include <set>
#include <vector>
#include <list>
#include "Student.h"
#include "UcClass.h"
using namespace std;

class ManageSchedule{
    private:
        set<Student> students;
        set<UcClass> classes;
        list<string> record;
    public:
        ManageSchedule() = default; // constructor
        void readStudentClasses(const string& path);
        void readClasses(const string& path);
        void addNewStudent(Student rockStar);
        void removeStudent(Student dropout);
        void switchUC(Student switched);
        set<Student> getAllStudents();
        set<UcClass> getAllClasses();
        Student getStudent();
        UcClass getUc(string ucCode);
        void accessRecord();
        void printSchedule(int n);                             //Listagem do horário de um aluno
        void printStudentsInClass();                           //Listagem de alunos em uma turma
};

#endif //SCHEDULES_MANAGESCHEDULE_H
