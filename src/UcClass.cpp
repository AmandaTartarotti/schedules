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

string UcClass::getUcCode() const{
    return uccode;
}

int UcClass::getSize() {
    return size;
}

void UcClass::incrementSize() {
    size += 1;
}

void UcClass::decreaseSize() {
    size -= 1;
}

bool UcClass::operator<(UcClass s) const {
    return uccode < s.getUcCode();
}

void UcClass::addLecture(Lecture lecture_) {
    /* bool lectureExist = false;
    for (Lecture &element : this->lectureClass){
        if (element.getLectureCode() == lecture_.getLectureCode()) {
            element.incrementNumberStudents();
            element.addLeics(lecture_);
            lectureExist = true;
        }
    }

    if (!lectureExist )                             // Essa é uma nova lecture
        */
    lectureClass.push_back(lecture_);
}


vector<Lecture> UcClass::getLecture() {
    return lectureClass;
}


bool UcClass::operator==(UcClass s) {
    return uccode == s.getUcCode();
}

void UcClass::addStudent(Student &stud, string lectureCode_) {
    studentClass.insert(stud);
    /* stud.addClass(*this);
    for (Lecture &element: this->lectureClass) {
        if (element.getLectureCode() == lectureCode_)
            stud.addLecture(element);
    }**/
}

set<Student> UcClass::getStudents() {
    return studentClass;
}

string UcClass::newStudent(Student &student) {
    int upCode = student.getCode();
    string upCode_ = to_string(upCode);
    if (!findStudent(student.getCode())){
        bool vacancyFound = false;
        for (Lecture &element : lectureClass){                      // check the first lecture with a vacancy
            if (element.getNumberStudents() < 27){
                if (student.checkAvabialy(this->getUcCode(), element)){                 // check the first element where there is a place
                    element.incrementNumberStudents();
                    this->incrementSize();
                    studentClass.insert(student);
                    vacancyFound = true;
                    student.addClass(*this, element.getLectureCode());
                    cout << "Sucess! The student is now enrolled in this UC at Lecture " << element.getLectureCode() << endl;
                    string recordSting("The student " + upCode_ + " was successfully enrolled in the Uc " + this->getUcCode() + " and lecture " + element.getLectureCode() + ".");
                    return recordSting;
                    break;
                }
            }
        }
        if (!vacancyFound) {
            cout << "Sorry! There is no available vacancy in" << this->getUcCode() << "that suits the student's schedule." << endl;
            string recordString("The student " + upCode_ + " could not be enrolled in the UC " + this->getUcCode() + " because there was no available vacancy that suits the student's schedule.");
            return recordString;
        }
    } else {
        cout << "Hey, this student is already enrolled!" << endl;
        string recordString("The student " + upCode_ + " was already enrolled in the UC " + this->getUcCode() + ". It is not possible to enroll a student twice!");
        return recordString;
    }
}
void UcClass::newClass(Student &student, string desired){

    for (Lecture &element : lectureClass){                      // check the first lecture with a vacancy
        if(element.getLectureCode() == desired) {
            if (element.getNumberStudents() < 27) {
                if (student.checkAvabialy(this->getUcCode(),element)) {                 // check the first element where there is a place
                    element.incrementNumberStudents();
                    student.addClass(*this, element.getLectureCode());
                    cout << "Sucess! The student is now enrolled in class " << element.getLectureCode()
                         << endl;
                    break;
                }
            }
        }
    }
}


void UcClass::removeStudent(Student &dropout) {

    if (findStudent(dropout.getCode())) {
        string lectureCode = dropout.removeClass(*this);
        cout << "The student is been removed.. ";
        for (Lecture &element: lectureClass) {
            if (element.getLectureCode() == lectureCode) {
                element.decreaseNumberStudents();                 //remove student from Lecture object counting
            }
        }

        for (auto &element: studentClass) {
            if (element.getCode() == dropout.getCode()) {
                studentClass.erase(element);                // remove student from UC
                this->decreaseSize();                          // remove student from UC counting
                cout << "Done, the student is now removed from this UC!" << endl;
            }
        }


    } else {
        cout << "Hey, we just checked and the student is not enrolled in this UC!" << endl;
    }
}

void UcClass::removeStudentClass(Student &dropout, string desired) {
    if (findStudent(dropout.getCode())) {
        for (Lecture &element: lectureClass) {
            if (element.getLectureCode() == desired) {
                element.decreaseNumberStudents();                 //remove student from Lecture object counting
                dropout.removeClass(*this);
            }
        }
        cout << "The student has been removed from this class" << endl;
    }
}