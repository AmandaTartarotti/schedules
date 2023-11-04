
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
    int menuId = 0;

    while(state) {
        printMenu();
        cin >> menuId;
        switch (menuId) {
            case 1:
                menuStudents(manageschedule);
                break;
            case 2:
                menuSchedule(manageschedule);
                break;
            case 3:
                printMenuRequest();
                cin >> menuId;
                switch (menuId) {
                    case 0:
                        break;
                    default:
                        cout << "Invalid option. Exiting." << endl;
                        break;
                    case 1:
                        manageschedule.requestAdd(menuId);
                        break;
                    case 2:
                        manageschedule.requestRemove(menuId);
                        break;
                    case 3:
                        manageschedule.requestSwitch();
                        break;
                }
                break;
            case 4:
                manageschedule.processRequests();
                break;
            case 5:
                showOccupation(manageschedule.getAllClasses());
                break;
            case 6:
                studentsInAtLeastN_UCs(manageschedule.getAllStudents());
                break;
            case 7:
                manageschedule.accessRecord();
                break;
            case 0:
                cout << "--------------------------------------------------\n";
                cout << "Goodbye!";
                state = false;
                break;
            default:
                cout << "Invalid option. Exiting." << endl;
                break;
        }
    }
    return 0;
}
