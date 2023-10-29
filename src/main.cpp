
#include <iostream>
#include <iterator>
#include <cctype>
#include "ManageSchedule.h"

using namespace std;

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return (!str.empty());
}

void listas(ManageSchedule &manageschedule) {
    char option = '0';
    cout << "--------------------------------------------------\n";
    cout << "Selecione a opcao\n";
    cout << "1 - Todos os estudantes\n";
    cout << "2 - Estudantes por turma de uma UC\n";
    //cout << "3 - Estudantes por ano\n";
    //cout << "4 - Estudantes por UC\n";
    cout << "0 - Voltar ao menu principal\n";
    cout << "--------------------------------------------------" << endl;
    cout << "Option:";
    cin >> option;
    switch (option) {
        default:
            cout << "Opcao invalida. Por favor, tente novamente." << endl;
            break;
        case '0':
           return;
        case '1':
            manageschedule.printAllStudents(manageschedule.getAllStudents());
            break;
        case '2':
            manageschedule.printStudentsInClass();
            break;
    }
}

int main(){
    ManageSchedule manageschedule;
    string path = "../givenDocs/";
    manageschedule.readClasses(path);
    manageschedule.readStudentClasses(path);

    bool exit = false;
    char option = '0';
    while (!exit) {
        cout << "--------------------------------------------------\n";
        cout << "Selecione a opcao\n";
        cout << "1 - Consultar horario de estudante\n";
        cout << "2 - Efetuar listagem\n";
        cout << "0 - Sair\n";
        cout << "--------------------------------------------------" << endl;
        cout << "Option:";
        cin >> option;
        string n;

        switch (option) {
            case '0':
                exit = true;
                break;
            case '1':
                cout << "--------------------------------------------------\n";
                cout << "Insira o seu numero UP: ";
                cin >> n; cout << "\n";
                if(n.length() != 9 or !isNumber(n)) {
                    cout << "Numero invalido. Por favor, tente novamente." << endl;
                    break;
                }
                manageschedule.printSchedule(stoi(n));
                break;
            case '2':
                listas(manageschedule);
                break;
            default:
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
                break;
        }
    }
    cout << "Goodbye!" << endl;

    return 0;
}