
#include <iostream>
#include <iterator>
#include "ManageSchedule.h"

using namespace std;

int main(){
    ManageSchedule manageschedule;
    string path = "../givenDocs/";
    manageschedule.readStudentClasses(path);

    for (auto v : manageschedule.getAllStudents()) {
        cout << v.getCode() << " " << v.getName() << "\n";
        v.printClasses();
    }

    return 0;
}