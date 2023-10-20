//
// Created by amand on 19/10/2023.
//

#ifndef SCHEDULES_READFILE_H
#define SCHEDULES_READFILE_H

#include <string>

using namespace std;

    class readFile{

        public:
        readFile(); // constructor
        static string readClasses(const string& path);
        static string readClassesPerUc();
        static string readStudentClasses();

    };

#endif //SCHEDULES_READFILE_H
