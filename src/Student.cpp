
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

bool Student::checkAvabialy(string ucCode, Lecture otherLecture) const{

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
    classes.push_back({{class_, lectureCode_}});
    for (Lecture &element : class_.getLecture()) {
        if (element.getLectureCode() == lectureCode_)
            lectures.push_back(element);
    }
}

string Student::removeClass(UcClass& class_){
    string lectureCode_;

    if (class_.findStudent(this->getCode())) {
        for (auto i: classes) {
            for (auto it = i.begin(); it != i.end();) {
                if (it->first.getUcCode() == class_.getUcCode()) {
                    it->second = lectureCode_;
                    it = i.erase(it);
                } else {
                    it++;
                }
            }
        }

        for (auto removeLeic = lectures.begin(); removeLeic != lectures.end();){
            if (removeLeic->getLectureCode() == lectureCode_ && class_.getUcCode() == removeLeic->getUCCode()){
                removeLeic = lectures.erase(removeLeic);
            }else{
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

vector<map<UcClass,string>> Student::getClasses() const {
    return classes;
}

bool Student::isEnroled(string ucCode) const {
    for (auto i: classes) {
        for (auto it = i.begin(); it != i.end();) {
            if(it->first.getUcCode() == ucCode) return true;
        }
    }
    return false;
}