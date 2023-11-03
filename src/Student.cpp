
#include "Student.h"
using namespace std;

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}

bool Student::operator>(const Student &s) const {
    return code > s.getCode();
}

list<Lecture> Student::getLectures() const{
    return lectures;
}

bool Student::checkAvabialy(Lecture otherLecture) const{
    for (auto element : lectures){
        if(element.overlapsWith(otherLecture)){
            return false;
        }
    }
    return true;
}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

void Student::addClass(UcClass class_, string lectureCode_) {
    numUC++;
    for (Lecture &element : class_.getLecture()) {
        if (element.getLectureCode() == lectureCode_)
            lectures.push_back(element);
    }
}

string Student::removeClass(UcClass& class_){

    string lectureCode_;

    if (class_.findStudent(this->getCode())) {
        for (auto removeLeic = lectures.begin(); removeLeic != lectures.end();) {
            if (class_.getUcCode() == removeLeic->getUCCode()) {
                removeLeic = lectures.erase(removeLeic);
                lectureCode_ = removeLeic->getLectureCode();
            } else {
                removeLeic++;
            }
        }
    }
    else {
        cout << "Hey, this student was not enrolled in this UC!" << endl;
    }

    return lectureCode_;
}

/* NÃO TA A SER UTILIZADO
void Student::printClasses() {
    for (UcClass class_ : classes) {
        cout << class_.getUcCode() << endl;
    }
}*/

int Student::getNumUc() const {
    return numUC;
}
