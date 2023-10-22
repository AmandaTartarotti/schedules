
#include <iostream>
#include "ManageSchedule.h"
#include "Student.h"


using namespace std;

int main(){
    ManageSchedule manageschedule;
    string path = "../givenDocs/";
    manageschedule.readStudentClasses(path);
    return 0;
}