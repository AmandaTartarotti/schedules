#include "Menu.h"
using namespace std;

void printMenu(){
    cout << "--------------------------------------------------\n";
    cout << "Welcome the Schedule Project!" << endl;
    cout << "These are the menu options. What do you want to consult today?" << endl;
    //cout << "0 - Check menu options" << endl;
    cout << "1 - Check all students names" << endl;
    cout << "2 - Consult the students within a given class" << endl;
    cout << "3 - Consult the schedule of a given student" << endl;
    // AVISO: tem que criar ainda
    cout << "4 - Consult the schedule of a given class" << endl;
    cout << "5 - Add Student to a new UC" << endl;
    cout << "6 - Remove Student from a UC" << endl;
    cout << "7 - Switch Student from a UC to another" << endl;
    cout << "8 - Access record of all changes made to the system" << endl;
    cout << "10 - Exit" << endl;
}

void printAllStudents(const set<Student>& student)  {
    char option = '0', option2 = '0';
    cout << "--------------------------------------------------\n";
    cout << "You choose to check all students names. First, select a student sorting option (1 or 2):\n";
    cout << "1 - Sort by UP number\n";
    cout << "2 - Sort alphabetically\n";
    cout << "--------------------------------------------------" << endl;
    cin >> option;

    if (option != '1' && option != '2') {
        cout << "Invalid option. Exiting." << endl;
        return;
    }
    cout << "Now, please select a sorting order option (1 or 2)\n";
    cout << "1 - Ascending (Low to High)\n";
    cout << "2 - Descending (High to Low)\n";
    cout << "--------------------------------------------------" << endl;
    cin >> option2; cout << "\n";

    if (option2 != '1' && option != '2') {
        cout << "Invalid option. Exiting." << endl;
        return;
    }

    vector<Student> temp = vector<Student>(student.begin(),student.end());
    if (option == '1'){
        if (option2 == '1'){
            sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getCode() < b.getCode();});
        } else{
            sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getCode() > b.getCode();});
        }
    } else {
        if (option2 == '1') {
            sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getName() < b.getName();});
        } else {
            sort(temp.begin(), temp.end(),[](Student const &a, Student const &b){return a.getName() > b.getName();});
        }
    }

    if (option == '1') {
        for (const Student& stud : temp) {
            cout << "Student ID: " << stud.getCode() << ", Name: " << stud.getName() << endl;
        }
    } else {
        for (const Student& stud : temp) {
            cout << "Name: " << stud.getName() << ", Student ID: " << stud.getCode() << endl;
        }
    }
}


void printStudentsInClass(const set<UcClass>& classes) {
    string ucCode, classCode;
    cout << "Enter the UC code (L.EICXXX): \n";
    cin >> ucCode; cout << "\n";
    cout << "Enter the class code (XLEICXX): \n";
    cin >> classCode; cout << "\n";
    UcClass class_(ucCode);
    auto it = classes.find(class_);
    if (it != classes.end()) {
        UcClass newClass = *it;
        printAllStudents(newClass.getStudents());
        return;
    } else{
        cout << "Oh no! It was not possible to find the class.. Please try again.\n";
    }
}


void printScheduleStudent(Student student) {

    //Criar set ordenado por Dia/Hora
    set<Lecture> schedule;

    vector<Lecture> leicsStudent = student.getLectures();
    //vector<UcClass> ucsStudent = student.getClasses();

    for (int i = 0; i < leicsStudent.size(); i++){
        schedule.insert(leicsStudent[i]);
    }

    // Cout do horario
    cout << "Horario de " << student.getName() << " (" << student.getCode() << ")\n";
    cout << "\nUcCode    Lecture   Day        StartHour   Duration   Type\n";

    for ( auto item : schedule) {
        cout << left << setw(9) << item.getUCCode() << " ";
        cout << left << setw(9) << item.getLectureCode() << " ";
        cout << left << setw(10) << item.getDay() << " ";
        cout << fixed << setprecision(1) << setw(12) << item.getStartHour() << " ";
        cout << setw(10) << item.getDuration() << " ";
        cout << setw(6) << item.getType() << "\n";
    }
}

void printScheduleClass(UcClass class_){
    //Criar set ordenado por Dia/Hora
    set<Lecture> scheduleClass;
    cout << class_.getLecture().size() << endl;
    for (auto element : class_.getLecture()){
        scheduleClass.insert(element);
    }

    cout << scheduleClass.size() << endl;

    // Cout do horario
    cout << "Horario de " << class_.getUcCode() << "\n";
    cout << "\nLecture   Day        StartHour   Duration   Type\n";

    for (auto item : scheduleClass) {
        cout << left << setw(9) << item.getLectureCode() << " ";
        cout << left << setw(10) << item.getDay() << " ";
        cout << fixed << setprecision(1) << setw(12) << item.getStartHour() << " ";
        cout << setw(10) << item.getDuration() << " ";
        cout << setw(6) << item.getType() << "\n";
    }
}