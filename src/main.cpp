
#include <iostream>
#include "ManageSchedule.h"


using namespace std;

int main(){
    ManageSchedule manageschedule;
    string path = "../givenDocs/";
    manageschedule.readStudentClasses(path);

    //Teste classe UcClass
    UcClass classe("Leic01", "01Leic02");
    Student s1(202205318, "Goncalo");
    Student s2(202205322, "Rodrigo");
    classe.addStudent(s1);
    classe.addStudent(s2);
    for (auto v : classe.getStudents()) {
        cout << v.getName() << "|" << v.getCode() << "\n";
    }
    cout << classe.getSize() << "|" << classe.getUcCode() << "|" << classe.getClassNum();
    return 0;
}