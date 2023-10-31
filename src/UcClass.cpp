//UcClass.cpp

#include "UcClass.h"
#include "Student.h"

UcClass::UcClass(const string &uccode_): lectureClass(), studentClass() {
    uccode = uccode_;
    size = 0;
}

void UcClass::getLectureAndIncrement(string lectureCode_) { //busca a referencia de uma lecture
    for (Lecture &element : this->lectureClass){
        if (element.getLectureCode() == lectureCode_) {
            element.incrementNumberStudents();
        }
    }
}


bool UcClass::findLecture(string lectureCode_) const {
    for (auto element : this->lectureClass){
        if (element.getLectureCode() == lectureCode_)
            return true;
    }
    return false;
}

bool UcClass::findStudent(int upCode) const {
    for (auto element : this->studentClass){
        if (element.getCode() == upCode)
            return true;
    }
    return false;
}

string UcClass::getUcCode() {
    return uccode;
}

int UcClass::getSize() {
    return size;
}

void UcClass::incrementSize() {
    size += 1;
}


bool UcClass::operator<(UcClass s) const {
    return uccode < s.getUcCode();
}

void UcClass::addLecture(const Lecture& lecture) {
    lectureClass.push_back(lecture);
}

vector<Lecture> UcClass::getLecture() {
    return lectureClass;
}


bool UcClass::operator==(UcClass s) {
    return uccode == s.getUcCode();
}

void UcClass::addStudent(Student &stud, string lectureCode_) {
    studentClass.insert(stud);
    for (Lecture &element: this->lectureClass) {
        if (element.getLectureCode() == lectureCode_)
            stud.addLecture(element);
    }
}

set<Student> UcClass::getStudents() {
    return studentClass;
}

void UcClass::newStudent(Student &student) {
    if (!findStudent(student.getCode())){
        bool vacancyFound = false;
        for (Lecture &element : lectureClass){                      // check the first lecture with a vacancy
            if (element.getNumberStudents() < 27){                 // check the first element where there is a place
                element.incrementNumberStudents();
                student.addLecture(element);
                cout << "Sucess! The student is now enrolled in this UC at Lecture " << element.getLectureCode() << endl;
                vacancyFound = true;
                break;
            }
        }
        if (!vacancyFound) {
            cout << "Sorry! There is no available vacancy in this UC." << endl;
        }
    } else {
        cout << "Hey, this student is already enrolled!" << endl;
    }
}
