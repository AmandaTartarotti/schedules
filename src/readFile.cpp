//
// Created by amand on 19/10/2023.
//

#include "readFile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

string readFile::readClasses(const string& path){
    string file_content;
    ifstream input_file(path);

    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << path << "'" << endl;
        file_content = "bobo de peixe";
    }

    istringstream iss(file_content);
    vector<string> items;

    while (getline(input_file, file_content)){
        items.push_back(file_content);
        cout<<file_content<<endl;
    }

    return file_content;
}



