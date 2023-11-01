//ManageSchedule.h

#ifndef SCHEDULES_MANAGESCHEDULE_H
#define SCHEDULES_MANAGESCHEDULE_H

#include <string>
#include <set>
#include <vector>
#include <queue>
#include <any>
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
        void addNewStudent(int upcode);
        set<Student> getAllStudents();
        set<UcClass> getAllClasses();
        Student getStudent(int upCode);
        UcClass getUc(string ucCode);
        void printSchedule(int n);                             //Listagem do horário de um aluno
        void printStudentsInClass();                           //Listagem de alunos em uma turma
};

#endif //SCHEDULES_MANAGESCHEDULE_H
