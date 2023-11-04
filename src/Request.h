#ifndef SCHEDULES_REQUEST_H
#define SCHEDULES_REQUEST_H

#include <string>
using namespace std;

struct Request {
    int numUp = 0;
    int operation = 0;
    string ucCode;
    string classNum;
};


#endif //SCHEDULES_REQUEST_H
