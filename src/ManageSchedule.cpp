//ManageSchedule.cpp
#include "ManageSchedule.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;


void ManageSchedule::readStudentClasses(const string& path) {
    ifstream input_file(path + "students_classes.csv");
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - 'students_classes.csv'" << endl;
        return;
    }

    getline(input_file, line);     // Skip first line

    vector<Student> studentvec;
    while (getline(input_file, line)){

        istringstream iss(line);
        string strCode, name, ucCode, classCode;
        getline(iss, strCode, ',');
        getline(iss, name, ',');
        getline(iss, ucCode, ',');
        getline(iss, classCode, ',');

        int code = stoi(strCode);
        UcClass class_(ucCode, classCode);
        Student student = Student(code, name);

        auto pos = classes.find(class_);                 // Incrementar tamanho da turma
        if (pos != classes.end()) {
            UcClass temp = *pos;
            classes.erase(pos);
            temp.incrementSize();
            class_ = temp;
            classes.insert(class_);
        }

        if (studentvec.empty() or studentvec.back().getCode() != code) {    //Adicionar alunos a um vetor com todos os alunos
            student.addClass(class_);
            studentvec.push_back(student);
        } else {
            studentvec.back().addClass(class_);
        }
    }
    students = set<Student>(studentvec.begin(), studentvec.end()); //Set com todos os alunos ordenados por número
}

void ManageSchedule::readClasses(const string& path){
    ifstream input_file(path + "classes.csv");
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - 'students_classes.csv'" << endl;
        return;
    }

    getline(input_file, line);     // Skip first line

    vector<UcClass> classvec;
    while (getline(input_file, line)){

        istringstream iss(line);
        string classCode, ucCode, weekday, type, shour, dur;
        getline(iss, classCode, ',');
        getline(iss, ucCode, ',');
        getline(iss, weekday, ',');
        getline(iss, shour, ',');
        getline(iss, dur, ',');
        getline(iss, type, ',');

        float startHour = stof(shour);
        float duration = stof(dur);

        Lecture lecture(weekday,startHour, duration, type);

        // Adicionar uma aula a uma turma num vetor com todas as turmas
        if (classvec.empty() or classvec.back().getUcCode() != ucCode) {    // Caso mude o código da Uc, criar nova turma com novo UcCode
            UcClass class_(ucCode, classCode);
            class_.addLecture(lecture);
            classvec.push_back(class_);
        } else {                                                           // Caso UcCode seja igual ao último elemento do vetor

            int pos = classvec.size() - 1;                                             // Adicionar aula (TP, T) a uma turma já existente
            while (pos != -1 and classvec.at(pos).getUcCode() == ucCode) {
                if (classvec.at(pos).getClassNum() == classCode) {
                    classvec.at(pos).addLecture(lecture);
                    break;
                }
                pos -= 1;
            }

            if (pos == -1 or classvec.at(pos).getUcCode() != ucCode) {             // Caso a turma não exista ainda no vetor, criar nova turma
                UcClass class_(ucCode, classCode);
                class_.addLecture(lecture);
                classvec.push_back(class_);
            }
        }
    }
    classes = set<UcClass>(classvec.begin(), classvec.end()); //Set com todos os alunos ordenados por número
}


set<Student> ManageSchedule::getAllStudents() const {
    return students;
}

set<UcClass> ManageSchedule::getAllClasses() const {
    return classes;
}


void ManageSchedule::processRequests() {
    if (requests.empty()) {
        cout << "--------------------------------------------------\n";
        cout << "There are no requests in the waiting list." << "\n";
        return;
    }

    char option = '0';
    cout << "--------------------------------------------------" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Process one request" << endl;
    cout << "2 - Process all requests" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option:"; cin >> option;

    switch (option) {
        case '0':
            return;
        default:
            cout << "Invalid option. Please try again." << endl;
            return;
        case '2':
            while (!requests.empty()) {
                Request request = requests.front();
                requests.pop();
                switch (request.operation) {
                    case 1:
                        addClassStudent(request.numUp, UcClass(request.ucCode, request.classNum));
                        break;
                    case 2:
                        removeClassStudent(request.numUp, UcClass(request.ucCode, request.classNum));
                        break;
                }
            }
        case '1':
            Request request = requests.front();
            requests.pop();
            switch (request.operation) {
                case 1:
                    addClassStudent(request.numUp, UcClass(request.ucCode, request.classNum));
                    break;
                case 2:
                    removeClassStudent(request.numUp, UcClass(request.ucCode, request.classNum));
                    break;
            }
    }
}

Student ManageSchedule::getStudent() const {
    string nUp;
    cout << "--------------------------------------------------\n";
    cout << "Please, enter the student's up number:";
    cin >> nUp;
    cout << "--------------------------------------------------\n";

    for (char digit : nUp) {
        if (!isdigit(digit)) {
            return Student(-1);
        }
    }

    int numUp = stoi(nUp);
    Student student(numUp);
    auto it = students.find(student);
    if (it == students.end()) {
        cout << "Student not found. Please, try again.\n";
        return Student(-1);
    }
    return *it;
}

UcClass ManageSchedule::getUcClass() const{
    string classCode, ucCode;
    cout << "Enter the UC code (L.EICXXX or UPXXX):";
    cin >> ucCode;
    cout << "Enter the class code (XLEICXX):";
    cin >> classCode;
    cout << "--------------------------------------------------\n";

    UcClass class_(ucCode, classCode);

    return class_;
}

void ManageSchedule::requestRemove(int option) {
    Student newStudent = getStudent();
    if (newStudent.getCode() == -1) {
        cout << "The given number is not valid. Please, try again.\n";
        return;
    }

    UcClass class_ = getUcClass();

    for (auto newClass : newStudent.getClasses()) {
        if (newClass == class_) {
            Request request;
            request.numUp = newStudent.getCode();
            request.operation = option;
            request.ucCode = class_.getUcCode();
            request.classNum = class_.getClassNum();
            requests.push(request);
            cout << "Your request has been registered with the number " << requests.size() << "." << endl;
            return;
        }
    }
    cout << "Class not found. Please, try again.\n";
}

void ManageSchedule::removeClassStudent(int numUp, const UcClass& class_) {
    auto it = classes.find(class_);

    Student student(numUp);
    auto it1 = students.find(student);

    Student newStudent = *it1;
    UcClass newClass_ = *it;

    newStudent.removeClass(class_);
    newClass_.decrementSize();
    classes.erase(it);
    classes.insert(newClass_);

    students.erase(it1);
    students.insert(newStudent);

    record.push("The Student " + to_string(numUp) + " was successfully removed from UC " + class_.getUcCode() + ".");
}

void ManageSchedule::requestAdd(int option) {
    Student newStudent = getStudent();
    if (newStudent.getCode() == -1) {
        cout << "The given number is not valid. Please, try again.\n";
        return;
    }

    UcClass class_ = getUcClass();
    auto it1 = classes.find(class_);
    if (it1 == classes.end()) {
        cout << "Class not found. Please, try again.\n";
        return;
    }

    for (UcClass tClass_ : newStudent.getClasses()) {
        if (tClass_ == class_) {
            cout << "The student is already enrolled on that class. Please, try again.\n";
            return;
        }
        if (tClass_.getUcCode() == class_.getUcCode()) {
            cout << "The student is already enrolled on that UC. Please, try again.\n";
            return;
        }
    }

    Request request;
    request.numUp = newStudent.getCode();
    request.operation = option;
    request.ucCode = class_.getUcCode();
    request.classNum = class_.getClassNum();
    requests.push(request);
    cout << "Your request has been registered with the number " << requests.size() << "." << endl;
}

void ManageSchedule::addClassStudent(int numUp, const UcClass& class_) {
    auto it = classes.find(class_);
    Student stud(numUp);
    auto it1 = students.find(stud);
    if (it1->getClasses().size() == 7) {
        record.push("The student " + to_string(numUp) + " is already registered in 7 UCs. It was not possible to include him/her in the UC " + class_.getUcCode() + ".");
    }

    if (it->getSize() >= 27) {
        record.push("The class " + class_.getClassNum() + " is already full. It is not possible to include the student " + to_string(numUp) + ".");
    }
    for (auto itr = it; itr != classes.end() and itr->getUcCode() == it->getUcCode(); itr++) {
        if (it->getSize() + 1 - itr->getSize() > 4) {
            record.push("The class " + class_.getClassNum() + " cannot receive another student to maintain the balance of classes occupation. It is not possible to include the student " + to_string(numUp) + ".");
            return;
        }
    }
    for (auto itr = it; itr != --classes.begin() and itr->getUcCode() == it->getUcCode(); itr--) {
        if (it->getSize() + 1 - itr->getSize() > 4) {
            record.push("The class " + class_.getClassNum() + " cannot receive another student to maintain the balance of classes occupation. It was not possible to include the student " + to_string(numUp) + ".");
            return;
        }
    }
    for (const Lecture& lecture : it->getLecture()) {
        if (!it1->checkAvailability(lecture)) {
            record.push("The new class " + class_.getClassNum() + " overlaid the student " + to_string(numUp) + " schedule. It was not possible to conclude the request.");
            return;
        }
    }

    Student newStudent = *it1;
    UcClass newClass_ = *it;
    newStudent.addClass(newClass_);
    newClass_.incrementSize();
    classes.erase(it);
    classes.insert(newClass_);
    students.erase(it1);
    students.insert(newStudent);
    record.push("The Student " + to_string(numUp) + " was successfully added to UC " + class_.getUcCode() + " in " + class_.getClassNum() + " class.");
}

void ManageSchedule::requestSwitch(){
    Student newStudent = getStudent();
    if (newStudent.getCode() == -1) {
        cout << "The given number is not valid. Please, try again.\n";
        return;
    }

    cout << "Enter the Uc and Class that you want to leave:" << endl;
    UcClass classLeave = getUcClass();

    bool classFound = false;
    for (auto newClass : newStudent.getClasses()) {
        if (newClass ==classLeave) {
            Request request_;
            request_.numUp = newStudent.getCode();
            request_.operation = 2;
            request_.ucCode = classLeave.getUcCode();
            request_.classNum = classLeave.getClassNum();
            requests.push(request_);
            classFound = true;
            break;
        }
    }

    if (!classFound) {
        cout << "Class not found. Please, try again.\n";
        return;
    }

    cout << "Now, please, enter the Uc and Class that you want to get in:" << endl;
    UcClass classAdd = getUcClass();
    auto it1 = classes.find(classAdd);
    if (it1 == classes.end()) {
        requests.pop();
        cout << "Class not found. Please, try again.\n";
        return;
    }

    for (UcClass tClass_ : newStudent.getClasses()) {
        if (tClass_ == classAdd) {
            requests.pop();
            cout << "The student is already enrolled on that class. Please, try again.\n";
            return;
        }
        if (tClass_.getUcCode() == classAdd.getUcCode()) {
            requests.pop();
            cout << "The student is already enrolled on that UC. Please, try again.\n";
            return;
        }
    }

    Request request;
    request.numUp = newStudent.getCode();
    request.operation = 1;
    request.ucCode = classAdd.getUcCode();
    request.classNum = classAdd.getClassNum();
    requests.push(request);
    cout << "Your request has been registered with the number " << requests.size() << "." << endl;
}

void ManageSchedule::accessRecord(){
    if (record.empty()) {
        cout << "--------------------------------------------------\n"
        cout << "There are no processed requests.\n";
    }
    while(!record.empty()) {
        string record_ = record.top();
        std::cout << record_ << std::endl;
        record.pop();
    }
}
