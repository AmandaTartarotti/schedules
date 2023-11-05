
#include <iostream>
#include <iterator>
#include "ManageSchedule.h"
#include "Menu.h"

using namespace std;

int main(){
    ManageSchedule manageschedule;
    string path = "../givenDocs/";
    manageschedule.readClasses(path);
    manageschedule.readStudentClasses(path);
    bool state = true;
    char menuId = '0';
    stack<ManageSchedule> scheduleState;
    scheduleState.push(manageschedule);
    while(state) {
        printMenu();
        cin >> menuId;
        switch (menuId) {
            case '1':
                menuStudents(manageschedule);
                break;
            case '2':
                menuSchedule(manageschedule);
                break;
            case '3':
                printMenuRequest();
                cin >> menuId;
                switch (menuId) {
                    case '0':
                        break;
                    default:
                        cout << "--------------------------------------------------\n";
                        cout << "Invalid option. Exiting." << endl;
                        break;
                    case '1':
                        manageschedule.requestAdd(menuId - '0');
                        break;
                    case '2':
                        manageschedule.requestRemove(menuId - '0');
                        break;
                    case '3':
                        manageschedule.requestSwitch();
                        break;
                }
                break;
            case '4':
                manageschedule.processRequests();
                scheduleState.push(manageschedule);
                break;
            case '5':
                showOccupation(manageschedule.getAllClasses());
                break;
            case '6':
                studentsInAtLeastN_UCs(manageschedule.getAllStudents());
                break;
            case '7':
                manageschedule.accessRecord();
                break;
            case '8':
                if (scheduleState.size() >= 2) {
                    scheduleState.pop();
                    manageschedule = scheduleState.top();
                    cout << "--------------------------------------------------\n";
                    cout << "Undo successful.\n";
                } else {
                    cout << "--------------------------------------------------\n";
                    cout << "Nothing to undo.\n";
                }
                break;
            case '0':
                cout << "--------------------------------------------------\n";
                cout << "Goodbye!";
                state = false;
                break;
            default:
                cout << "--------------------------------------------------\n";
                cout << "Invalid option. Exiting." << endl;
                break;
        }
    }
    return 0;
}