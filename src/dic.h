//
// Created by jadson on 20/01/2022.
//

#ifndef T3_DIC_H
#define T3_DIC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <climits>
#include <iterator>
#include <algorithm>
#include <string.h>

using namespace std;
namespace fs = std::filesystem;

class Dic {
public:
    ifstream file;
    string path;
    string name;
    unsigned long long int length;
    vector<string> block;
    unsigned int searchBlock(string key);

    Dic(string _fileName);
};


#endif //T3_DIC_H
