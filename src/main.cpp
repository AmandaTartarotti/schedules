//
// Created by amand on 19/10/2023.
//

#include "readFile.h"
#include "readFile.cpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(){
    string filename("./givenDocs/classes.csv");
    string file_contents;
    file_contents = readFile::readClasses(filename);
    cout << file_contents;
    return 0;
}