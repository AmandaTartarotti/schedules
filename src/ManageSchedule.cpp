//ManageSchedule.cpp
#include "ManageSchedule.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;


void ManageSchedule::readStudentClasses(const string& path) {
    ifstream input_file(path + "students_classes.csv");
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - 'students_classes.csv'" << endl;
        return;
    }

    getline(input_file, line);     // Skip first line

    vector<Student> studentvec;
    while (getline(input_file, line)){

        istringstream iss(line);
        string strCode, name, ucCode, classCode;
        getline(iss, strCode, ',');
        getline(iss, name, ',');
        getline(iss, ucCode, ',');
        getline(iss, classCode, ',');

        int code = stoi(strCode);
        UcClass class_(ucCode, classCode);

        auto pos = classes.find(class_);                 // Incrementar tamanho da turma
        if (pos != classes.end()) {
            UcClass newClass_ = *pos;
            classes.erase(pos);
            newClass_.incrementSize();
            classes.insert(newClass_);
            class_ = newClass_;
        }

        if (studentvec.empty() or studentvec.back().getCode() != code) {    //Adicionar alunos a um vetor com todos os alunos
            Student student = Student(code, name);
            student.addClass(class_);
            studentvec.push_back(student);
        } else {
            studentvec.back().addClass(class_);
        }
    }
    students = set<Student>(studentvec.begin(), studentvec.end()); //Set com todos os alunos ordenados por número
}

void ManageSchedule::readClasses(const string& path){
    ifstream input_file(path + "classes.csv");
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - 'students_classes.csv'" << endl;
        return;
    }

    getline(input_file, line);     // Skip first line

    vector<UcClass> classvec;
    while (getline(input_file, line)){

        istringstream iss(line);
        string classCode, ucCode, weekday, type, shour, dur;
        getline(iss, classCode, ',');
        getline(iss, ucCode, ',');
        getline(iss, weekday, ',');
        getline(iss, shour, ',');
        getline(iss, dur, ',');
        getline(iss, type, ',');

        float startHour = stof(shour);
        float duration = stof(dur);

        Lecture lecture(weekday,startHour, duration, type);

        // Adicionar uma aula a uma turma num vetor com todas as turmas
        if (classvec.empty() or classvec.back().getUcCode() != ucCode) {    // Caso mude o código da Uc, criar nova turma com novo UcCode
            UcClass class_(ucCode, classCode);
            class_.addLecture(lecture);
            classvec.push_back(class_);
        } else {                                                           // Caso UcCode seja igual ao último elemento do vetor

            int pos = classvec.size() - 1;                                             // Adicionar aula (TP, T) a uma turma já existente
            while (pos != -1 and classvec.at(pos).getUcCode() == ucCode) {
                if (classvec.at(pos).getClassNum() == classCode) {
                    classvec.at(pos).addLecture(lecture);
                    break;
                }
                pos -= 1;
            }

            if (pos == -1 or classvec.at(pos).getUcCode() != ucCode) {             // Caso a turma não exista ainda no vetor, criar nova turma
                UcClass class_(ucCode, classCode);
                class_.addLecture(lecture);
                classvec.push_back(class_);
            }
        }
    }
    classes = set<UcClass>(classvec.begin(), classvec.end()); //Set com todos os alunos ordenados por número
}

set<Student> ManageSchedule::getAllStudents() {
    return students;
}

set<UcClass> ManageSchedule::getAllClasses() {
    return classes;
}
