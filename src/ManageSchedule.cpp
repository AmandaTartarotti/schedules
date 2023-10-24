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

        if (studentvec.empty() or studentvec.back().getCode() != code) {    //Adicionar alunos a um vetor com todos os alunos
            Student student = Student(code, name);
            // Falta ainda meter aqui as turmas
            studentvec.push_back(student);
        }
    }
    students = set<Student>(studentvec.begin(), studentvec.end()); //Set com todos os alunos ordenados por número
}

void ManageSchedule::readClassesPerUc(const string& path) {
    string file_content;
    ifstream input_file(path);

    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << path << "'" << endl;
    }

    istringstream iss(file_content);
    vector<string> items;

    getline(input_file, file_content);     // Skip first line

    while (getline(input_file, file_content)){
        items.push_back(file_content);
    }

}

void ManageSchedule::readClasses(const string& path){
    string file_content;
    ifstream input_file(path);

    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << path << "'" << endl;
    }

    istringstream iss(file_content);
    vector<string> items;

    getline(input_file, file_content);     // Skip first line

    while (getline(input_file, file_content)){
        items.push_back(file_content);
    }
}