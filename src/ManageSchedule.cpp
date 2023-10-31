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

void ManageSchedule::readClasses(const string& path) {
    ifstream input_file(path + "classes.csv");
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - 'classes.csv'" << endl;
        return;
    }

    getline(input_file, line);     // Skip first line

    while (getline(input_file, line)) {

        istringstream iss(line);
        string lectureCode, ucCode, weekday, type, shour, dur;
        getline(iss, lectureCode, ',');
        getline(iss, ucCode, ',');
        getline(iss, weekday, ',');
        getline(iss, shour, ',');
        getline(iss, dur, ',');
        getline(iss, type, ',');

        float startHour = stof(shour);
        float duration = stof(dur);

        UcClass class_(ucCode);
        Lecture lecture(lectureCode, weekday, startHour, duration, type);

        auto pos = classes.find(class_);
        if (pos != classes.end()) {                                        // Se encontrar um UC existente
            if (!pos->findLecture(lectureCode)) {             // E não encontrar a lecture nessa UC
                UcClass temp = *pos;
                classes.erase(pos);
                temp.addLecture(lecture);                                // adiciona essa turma
                classes.insert(temp);
            }
        } else {
            class_.addLecture(lecture);
            classes.insert(class_);                                     // adiciona a uc + lecture
        }
    }
}


void ManageSchedule::readStudentClasses(const string& path) {
    ifstream input_file(path + "students_classes.csv");
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - 'students_classes.csv'" << endl;
        return;
    }

    getline(input_file, line);     // Skip first line

    vector<Student> studentVec;
    while (getline(input_file, line)) {

        istringstream iss(line);
        string studentCode, name, ucCode, lectureCode;
        getline(iss, studentCode, ',');
        getline(iss, name, ',');
        getline(iss, ucCode, ',');
        getline(iss, lectureCode, ',');

        int code = stoi(studentCode);
        UcClass class_(ucCode);
        Student student = Student(code, name);


        auto pos = classes.find(class_);                 // Incrementar tamanho da turma
        if (pos != classes.end()) {                                        // Se encontrar um UC existente
            if (pos->findLecture(lectureCode)) {               // E encontrar a lecture nessa UC
                UcClass temp = *pos;
                classes.erase(pos);
                temp.incrementSize();                                      // incrementa a quantidade de estudantes da uc
                temp.addStudent(student, lectureCode);                             // add estudante ao vetor<Student> de class_
                temp.getLectureAndIncrement(lectureCode);        // add quantidade de estudante a lecture que está no vetor<Lecture> de class_
                classes.insert(temp);
                students.insert(student);                              //add o estudente ao set students
            } else {
                cout << "The student is enrolled in a class that does not exist!" << endl;
            }
        }
    }
}


    set<Student> ManageSchedule::getAllStudents() {
        return students;
    }

    set<UcClass> ManageSchedule::getAllClasses() {
        return classes;
    }

    /* TEM QUE REVISAR
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
     */


