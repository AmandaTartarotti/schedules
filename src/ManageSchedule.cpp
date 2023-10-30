//ManageSchedule.cpp
#include "ManageSchedule.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <algorithm>

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
        Student student = Student(code, name);


        auto pos = classes.find(class_);                 // Incrementar tamanho da turma
        if (pos != classes.end()) {
            UcClass temp = *pos;
            classes.erase(pos);
            temp.incrementSize();
            class_ = temp;
            class_.addStudent(student);
            classes.insert(class_);
        }

        if (studentvec.empty() or studentvec.back().getCode() != code) {    //Adicionar alunos a um vetor com todos os alunos
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

        Lecture lecture(classCode, weekday,startHour, duration, type);

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

void ManageSchedule::printSchedule(int n) {
    Student student(n);
    auto it = students.find(student);
    if (it == students.end()) {
        cout << "Estudante não encontrado.\n";
        return;
    }
    student = *it;

    //Criar set ordenado por Dia/Hora
    set<pair<Lecture, UcClass>> schedule;
    for (UcClass class_ : student.getClasses()) {
        for (const Lecture& lecture : class_.getLecture()) {
            pair<Lecture, UcClass> temp = make_pair(lecture, class_);
            schedule.insert(temp);
        }
    }

    //Cout do horario
    cout << "Horario de " << student.getName() << " (" << student.getCode() << ")\n";
    cout << "\nUcCode-----Class----Lecture\n";
    for (pair<Lecture, UcClass> item : schedule) {
        cout << item.second.getUcCode() << " - " << item.second.getClassNum() << ": ";
        cout << item.first.getDay() << ", " << item.first.getStartHour() << ", " << item.first.getDuration() << ", " << item.first.getType() << "\n";
    }
}

void ManageSchedule::printAllStudents(const set<Student>& student) {
    char option = '0', option2 = '0';
    cout << "--------------------------------------------------\n";
    cout << "Selecione a opcao\n";
    cout << "1 - Ordenar por numero UP\n";
    cout << "2 - Ordenar alfabeticamente\n";
    cout << "3 - Ordenar ascendentemente\n";
    cout << "4 - Ordenar decrescentemente\n";
    cout << "--------------------------------------------------" << endl;
    cout << "Option 1:";
    cin >> option;
    cout << "Option 2:";
    cin >> option2; cout << "\n";
    vector<Student> temp = vector<Student>(student.begin(),student.end());
    if (option == '1' and option2 == '3') {
        sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getCode() < b.getCode();});
    } else if (option == '1' and option2 == '4') {
        sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getCode() > b.getCode();});
    } else if (option == '2' and option2 == '3') {
        sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getName() < b.getName();});
    } else if (option == '2' and option2 == '4') {
        sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getName() > b.getName();});
    } else {
        cout << "Opcoes invalidas. Por favor, tente novamente." << endl;
        return;
    }
    if (option == '1') {
        for (const Student& stud : temp) {
            cout << stud.getCode() << " - " << stud.getName() << "\n";
        }
    } else {
        for (const Student& stud : temp) {
            cout << stud.getName() << " - " << stud.getCode() << "\n";
        }
    }
}

void ManageSchedule::printStudentsInClass() {
    string ucCode, classCode;
    cout << "Introduza o codigo da UC (L.EICXXX)\n";
    cin >> ucCode; cout << "\n";
    cout << "Introduza o codigo da turma (XLEICXX)\n";
    cin >> classCode; cout << "\n";
    UcClass class_(ucCode, classCode);
    auto it = classes.find(class_);
    if (it != classes.end()) {
        UcClass newClass = *it;
        printAllStudents(newClass.getStudents());
        return;
    }
    cout << "Não foi possível encontrar a turma. Por favor, tente novamente.\n";
}
