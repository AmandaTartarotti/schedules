
#include <iostream>
#include <iterator>
#include "ManageSchedule.h"

using namespace std;

int main(){
    ManageSchedule manageschedule;
    string path = "../givenDocs/";
    manageschedule.readClasses(path);
    manageschedule.readStudentClasses(path);

    /**
    //Teste alunos
    for (auto c : manageschedule.getAllStudents()) {
        cout << c.getName() << " " << c.getCode() << "\n";
        for (auto v : c.getClasses()) {
            cout << v.getClassNum() << " " << v.getUcCode() << " " << v.getSize() << " ";
            for (auto z : v.getLecture()) {
                cout << z.getType() << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    **/

    /**
    //Teste turmas
    for (auto c : manageschedule.getAllClasses()) {
        cout << c.getUcCode() << " " << c.getClassNum() << " " << c.getSize() << "\n";
        for (auto v : c.getLecture()) {
            cout << v.getDay() << " " << v.getStartHour() << " " << v.getDuration() << " " << v.getType() << "\n";
        }
        cout << "\n";
    }
    **/

    /**
    //Teste classe Lecture
    Student stud(202205318, "Goncalo");
    UcClass class_("Leic01", "01Leic02");
    Lecture slot("Monday", 10.5, 1.5, "TP");
    class_.addLecture(slot);
    stud.addClass(class_);
    cout << stud.getName() << " " << stud.getCode() << "\n";
    for (auto c : stud.getClasses()) {
        cout << c.getUcCode() << " " << c.getClassNum() << " " << c.getSize() << "\n";
        for (auto v : c.getLecture()) {
            cout << v.getDay() << " " << v.getStartHour() << " " << v.getDuration() << " " << v.getType() << "\n";
        }
    }
    **/
    return 0;
}