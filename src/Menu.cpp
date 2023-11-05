#include <algorithm>
#include "Menu.h"
using namespace std;



void printMenu(){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check students" << endl;
    cout << "2 - Consult schedule" << endl;
    cout << "3 - Make a request" << endl;
    cout << "4 - Process requests" << endl;
    cout << "5 - Consult occupation" << endl;
    cout << "6 - Consult students with, at least, 'n' UCs" << endl;
    cout << "7 - Consult the record of all recent changes made to the system" << endl;
    cout << "8 - Undo the previous requests" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
}

void menuStudents(const ManageSchedule& schedule) {
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check all students" << endl;
    cout << "2 - Check students within a class" << endl;
    cout << "3 - Check students within a curricular unit" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    int option = 0;
    cin >> option;
    switch (option) {
        case 1:
            printAllStudents(schedule.getAllStudents());
            break;
        case 2:
            printStudentsInClass(schedule.getAllStudents());
            break;
        case 3:
            printStudentsInUC(schedule.getAllStudents());
            break;
        case 0:
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}

void menuSchedule(const ManageSchedule& schedule) {
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Consult the schedule of a student" << endl;
    cout << "2 - Consult the schedule of a class" << endl;
    cout << "3 - Consult all schedules of an UC" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    int option = 0;
    cin >> option;
    switch (option) {
        case 0:
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
        case 1:
            printStudentSchedule(schedule.getAllStudents());
            break;
        case 2:
            printClassSchedule(schedule.getAllClasses());
            break;
        case 3:
            printUcSchedule(schedule.getAllClasses());
            break;
    }
}

void printMenuRequest() {
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Add Student to a new UC" << endl;
    cout << "2 - Remove Student from a UC" << endl;
    cout << "3 - Switch Student from a UC/class to another" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
}

void printAllStudents(const set<Student>& student)  {
    char option = '0', option2 = '0';
    cout << "--------------------------------------------------\n";
    cout << "Select a student sorting option:\n";
    cout << "1 - Sort by UP number\n";
    cout << "2 - Sort alphabetically\n";
    cout << "--------------------------------------------------" << endl;
    cout << "Option:";
    cin >> option;
    cout << "--------------------------------------------------" << endl;
    if (option != '1' && option != '2') {
        cout << "Invalid option. Please, try again." << endl;
        return;
    }
    cout << "Select a sorting order option:\n";
    cout << "1 - Ascending (Low to High)\n";
    cout << "2 - Descending (High to Low)\n";
    cout << "--------------------------------------------------" << endl;
    cout << "Option:"; cin >> option2;
    cout << "--------------------------------------------------" << endl;
    if (option2 != '1' && option2 != '2') {
        cout << "Invalid option. Please, try again." << endl;
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
        cout << "Student ID          Name\n";
        for (const Student& stud : temp) {
            cout << stud.getCode() << "           " << stud.getName() << endl;
        }
    } else {
        cout << "Name                          Student ID\n";
        for (const Student& stud : temp) {
            cout << left << setw(25) << stud.getName() << "     " << stud.getCode() << endl;
        }
    }
}

void printStudentsInClass(const set<Student>& students) {
    string ucCode, classCode;
    cout << "Enter the UC code (L.EICXXX or UPXXX):";
    cin >> ucCode;
    cout << "Enter the class code (XLEICXX):";
    cin >> classCode;
    UcClass newClass(ucCode, classCode);

    set<Student> studentset;
    for (const Student & student : students) {
        for (const UcClass & class_ : student.getClasses()) {
            if ((UcClass) class_ == newClass) {
                studentset.insert(student);
                break;
            }
        }
    }

    if (!studentset.empty()) {
        printAllStudents(studentset);
        return;
    } else {
        cout << "--------------------------------------------------\n";
        cout << "It was not possible to find that class. Please, try again.\n";
    }
}

void printStudentsInUC(const set<Student>& students){
    string ucCode, classCode;
    cout << "Enter the UC code (L.EICXXX or UPXXX):";
    cin >> ucCode;

    set<Student> studentset;
    for (const Student & student : students) {
        for (const UcClass & class_ : student.getClasses()) {
            if (class_.getUcCode() == ucCode) {
                studentset.insert(student);
                break;
            }
        }
    }

    if (!studentset.empty()) {
        printAllStudents(studentset);
        return;
    } else {
        cout << "--------------------------------------------------\n";
        cout << "It was not possible to find that UC. Please, try again.\n";
    }
}

void studentsInAtLeastN_UCs(const set<Student>& student){
    string num;
    int count = 0;
    cout << "--------------------------------------------------\n";
    cout << "Enter the minimum number of UCs a student must be registered in:";
    cin >> num;
    cout << "--------------------------------------------------\n";

    if (!isNumber(num)) {
        cout << "The given number is not valid. Please, try again.\n";
        return;
    }

    int n = stoi(num);
    for (const Student& stud : student){
        if (stud.getClasses().size() > n){
            count++;
        }
    }
    cout << "The number of students registered in at least " << num << " UC's is " << count << "." << endl;
}

void printStudentSchedule(const set<Student>& students) {
    string num;
    cout << "--------------------------------------------------\n";
    cout << "Please, enter the student's up number:";
    cin >> num;
    cout << "--------------------------------------------------\n";

    if (!isNumber(num)) {
        cout << "The given number is not valid. Please, try again.\n";
        return;
    }

    int numUp = stoi(num);
    Student student(numUp);
    auto it = students.find(student);
    if (it == students.end()) {
        cout << "Student not found. Please, try again.\n";
        return;
    }
    student = *it;

    set<pair<Lecture, UcClass>> schedule;
    for (UcClass class_ : student.getClasses()) {
        for (const Lecture& lecture : class_.getLecture()) {
            pair<Lecture, UcClass> temp = make_pair(lecture, class_);
            schedule.insert(temp);
        }
    }

    // Cout do horario
    cout << student.getName() <<  "'s schedule (" << student.getCode() << "):\n";
    cout << "\nUC        Class     Day        StartHour   Duration   Type\n";

    for (pair<Lecture, UcClass> lecture : schedule) {
        cout << left << setw(9) << lecture.second.getUcCode() << " ";
        cout << left << setw(9) << lecture.second.getClassNum() << " ";
        cout << left << setw(10) << lecture.first.getDay() << " ";
        cout << fixed << setprecision(1) << setw(12) << lecture.first.getStartHour() << " ";
        cout << setw(10) << lecture.first.getDuration() << " ";
        cout << setw(6) << lecture.first.getType() << "\n";
    }
}

void printClassSchedule(const set<UcClass>& classes) {
    string classCode;
    cout << "--------------------------------------------------\n";
    cout << "Enter the class code (XLEICXX):";
    cin >> classCode;
    cout << "--------------------------------------------------\n";

    set<pair<Lecture, UcClass>> schedule;
    for (UcClass class_ : classes) {
        if (class_.getClassNum() == classCode) {
            for (const Lecture& lecture : class_.getLecture()) {
                pair<Lecture, UcClass> temp = make_pair(lecture, class_);
                schedule.insert(temp);
            }
        }
    }

    if (schedule.empty()) {
        cout << "It was not possible to find that class. Please, try again.\n";
        return;
    }
    // Cout do horario
    cout << "Schedule of class " << classCode << "\n";
    cout << "\nUC        Day        StartHour   Duration   Type\n";

    for (pair<Lecture, UcClass> lecture : schedule) {
        cout << left << setw(9) << lecture.second.getUcCode() << " ";
        cout << left << setw(10) << lecture.first.getDay() << " ";
        cout << fixed << setprecision(1) << setw(12) << lecture.first.getStartHour() << " ";
        cout << setw(10) << lecture.first.getDuration() << " ";
        cout << setw(6) << lecture.first.getType() << "\n";
    }
}

void printUcSchedule(const set<UcClass>& classes) {
    string ucCode;
    cout << "--------------------------------------------------\n";
    cout << "Enter the UC code (L.EICXXX or UPXXX):";
    cin >> ucCode;
    cout << "--------------------------------------------------\n";


    set<pair<Lecture, UcClass>> schedule;
    for (UcClass class_ : classes) {
        if (class_.getUcCode() == ucCode) {
            for (const Lecture& lecture : class_.getLecture()) {
                pair<Lecture, UcClass> temp = make_pair(lecture, class_);
                schedule.insert(temp);
            }
        }
    }

    if (schedule.empty()) {
        cout << "It was not possible to find that UC. Please, try again.\n";
        return;
    }

    // Cout do horario
    cout << "Schedule of UC " << ucCode << "\n";
    cout << "\nClass     Day        StartHour   Duration   Type\n";

    for (pair<Lecture, UcClass> lecture : schedule) {
        cout << left << setw(9) << lecture.second.getClassNum() << " ";
        cout << left << setw(10) << lecture.first.getDay() << " ";
        cout << fixed << setprecision(1) << setw(12) << lecture.first.getStartHour() << " ";
        cout << setw(10) << lecture.first.getDuration() << " ";
        cout << setw(6) << lecture.first.getType() << "\n";
    }
}

void printMenuOccupation() {
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Consult occupation of a class" << endl;
    cout << "2 - Consult occupation of a UC" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
}

void showOccupationUc(const set<UcClass>& classes){
    string ucCode;
    int ocuppation = 0;
    bool classExist = false;
    cout << "--------------------------------------------------\n";
    cout << "Enter the UC code (L.EICXXX or UPXXX):";
    cin >> ucCode;

    for (auto class_ : classes) {
        if (class_.getUcCode() == ucCode){
            classExist = true;
            ocuppation += class_.getSize();
        }
    }

    if (!classExist) {
        cout << "It was not possible to find the UC. Please try again.\n";
        return;
    }

    cout << "The UC " << ucCode << " has " << ocuppation << " student(s) enrolled." << endl;
    return;
}

void showOccupation(const set<UcClass>& classes) {
    string ucCode, classCode;
    cout << "--------------------------------------------------\n";
    cout << "Enter the UC code (L.EICXXX or UPXXX):";
    cin >> ucCode;
    cout << "Enter the class code (XLEICXX):";
    cin >> classCode;
    cout << "--------------------------------------------------\n";
    UcClass class_(ucCode, classCode);
    auto it = classes.find(class_);
    if (it != classes.end()) {
        UcClass newClass = *it;
        cout << "The class " << classCode << " from UC " << ucCode << " has " << newClass.getSize() << " student(s) enrolled." << endl;
        return;
    }
    cout << "It was not possible to find the class. Please try again.\n";
}

bool isNumber(const string& num) {
    for (char digit : num) {
        if (!isdigit(digit)) {
            return false;
        }
    }
    return (!num.empty());
}
