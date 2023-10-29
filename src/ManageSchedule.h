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
        void printSchedule(int n);                             //Listagem do horário de um aluno
        void printAllStudents(const set<Student>& student);    //Listagem de todos os alunos
        void printStudentsInClass();                           //Listagem de alunos em uma turma
};

#endif //SCHEDULES_MANAGESCHEDULE_H
