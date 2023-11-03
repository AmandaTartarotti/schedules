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
        Lecture lecture(ucCode, lectureCode, weekday, startHour, duration, type);

        auto pos = classes.find(class_);
        if (pos != classes.end()) {                                        // Se encontrar um UC existente
            UcClass temp = *pos;
            classes.erase(pos);
            temp.addLecture(lecture);                                       // adiciona essa turma
            classes.insert(temp);
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
        string leicCode = lectureCode;
        UcClass class_(ucCode);
        Student student(code, name);

        auto pos = classes.find(class_);                 // Incrementar tamanho da turma
        if (pos != classes.end()) {                                        // Se encontrar um UC existente
            if (pos->findLecture(lectureCode)) {               // E encontrar a lecture nessa UC
                UcClass modifiedClass = *pos;
                classes.erase(pos);
                modifiedClass.incrementSize();                                      // incrementa a quantidade de estudantes da uc
                modifiedClass.getLectureAndIncrement(lectureCode);      // add quantidade de estudante a lecture que está no vetor<Lecture> de class_
                modifiedClass.addStudent(student, lectureCode);       // add estudante ao vetor<Student> de class_
                classes.insert(modifiedClass);

                if (studentVec.empty() or studentVec.back().getCode() != code) {    //Adicionar alunos a um vetor com todos os alunos
                    student.addClass(modifiedClass, leicCode);
                    studentVec.push_back(student);
                } else {
                    studentVec.back().addClass(modifiedClass, leicCode);
                }

            } else
                cout << "The student is enrolled in a class that does not exist!" << endl;
        }

    }
    students = set<Student>(studentVec.begin(), studentVec.end()); //Set com todos os alunos ordenados por número
}

set<Student> ManageSchedule::getAllStudents() {
    return students;
}

set<UcClass> ManageSchedule::getAllClasses() {
    for (auto element : classes){
       vector<Lecture> teste = element.getLecture();
       for (auto element_ : teste){
           cout << element.getUcCode() << endl << element_.getLectureCode() << " " << element_.getNumberStudents() << endl;
       }
    }
    return classes;
}

Student ManageSchedule::getStudent(){
    int numUp;
    cout << "Please, enter the student's up number" << endl;
    cin >> numUp;
    for (auto &element : this->students){
            if (element.getCode() == numUp){
                cout << "We are talking about " << element.getName() << "!" << endl;
                return element;
            }
    }
    throw std::runtime_error("Bad news, no student was not found! Are you sure this is the right number?");
}

UcClass ManageSchedule::getUc(string ucCode){
    for (auto element : this->classes){
        if (element.getUcCode() == ucCode){
            return element;
        }
    }
    throw std::runtime_error("Bad news, no UC was not found! Are you sure this is the right code?");
}


void ManageSchedule::addNewStudent(Student rockStar){
        int upCode = rockStar.getCode();
        string upCode_ = to_string(upCode);
        vector<map<UcClass,string>> uc = rockStar.getClasses();
        if (uc.size() < 7){                                    // check how many lectures the student is enrolled
            string ucCode;
            cout << "Now, please enter the UC code the student wants to join (L.EICXXX): " << endl;
            cin >> ucCode;
            UcClass uc = getUc(ucCode);
            string recordString = uc.newStudent(rockStar);
            record.push_back(recordString);
        } else {
            cout << "Ops! This student is already registered in 7 UCs";
        }
}

void ManageSchedule::addNewClass(Student rockStar){
    string ucCode;
    cout << "Now, please enter the UC code of the class the student wants to join (L.EICXXX): " << endl;
    cin >> ucCode;
    if (rockStar.isEnroled(ucCode)) {
        cout << "This student already has a class in this UC" << endl;
        return;
    }
    string classCode;
    cout << "Now, please enter the code of the class the student would like to join: " << endl;
    cin >> classCode;
    UcClass uc = getUc(ucCode);
    uc.newClass(rockStar, classCode);
}

void ManageSchedule::removeStudent(Student dropout){
    string ucCode;
    cout << "Now, please enter the UC code the student wants to leave: " << endl;
    cin >> ucCode;
    UcClass uc = getUc(ucCode);
    uc.removeStudent(dropout);
    int upCode = dropout.getCode();
    string upCode_ = to_string(upCode);
    record.push_back("The Student " + upCode_ + " was successfully removed from UC " + ucCode + ".");
}

void ManageSchedule::removeStudentClass(Student dropout) {
    string ucCode;
    cout << "Now, please enter the UC code of the class the student wants to leave: " << endl;
    cin >> ucCode;
    UcClass uc = getUc(ucCode);
    string classCode;
    cout << "Now, please enter the class code the student wants to leave: " << endl;
    cin >> classCode;
    uc.removeStudentClass(dropout, classCode);
}

void ManageSchedule::switchUC(Student switched){
    removeStudent(switched);
    addNewStudent(switched);
}

void ManageSchedule::switchClass(Student switched) {
    removeStudentClass(switched);
    addNewClass(switched);
}
void ManageSchedule::accessRecord(){
    for (const std::string& element : record) {
        std::cout << element << std::endl;
    }
}


