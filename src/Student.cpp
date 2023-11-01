
#include "Student.h"
using namespace std;

bool Student::operator<(const Student &s) const {
    return code < s.getCode();
}

bool Student::operator>(const Student &s) const {
    return code > s.getCode();
}

vector<Lecture> Student::getLectures() const{
    return lectures;
}

bool Student::checkAvabialy(Lecture otherLecture) const{
    //cout << "Estudante inscrito em:" << endl;
    //cout << classes.size();
    for (auto element : classes){
        //cout << element.getUcCode();
    }
    for (auto element : lectures){
        //cout << " comparando com " << element.getLectureCode() << " ";
        if (element.overlapsWith(otherLecture)){
            //cout << "vish nn da" << endl;
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

void Student::addClass(UcClass& class_, string lectureCode_) {
    classes.push_back(class_);
    for (Lecture &element : class_.getLecture()) {
        if (element.getLectureCode() == lectureCode_)
            lectures.push_back(element);
    }
}


void Student::printClasses() {
    for (UcClass class_ : classes) {
        cout << class_.getUcCode() << endl;
    }
}

vector<UcClass> Student::getClasses() const {
    return classes;
}
