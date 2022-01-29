//
// Created by jadson on 10/01/2022.
//

#ifndef T3_DECOMPRESS_H
#define T3_DECOMPRESS_H

#include <iostream>
#include <fstream>
#include <cinttypes>
#include <array>
#include <time.h>
#include <chrono>

#include "dic.h"
#include "parent.h"
#include "int64toString.h"
#include "vecChar8toInt64.h"
#include "index.h"

using namespace std;

class Decompress {
public:
    ifstream iFile;
    string path;
    unsigned long long int length;

    bool start(string _fileName,Parent &dic);
    unsigned long long int getPFileLength();
    unsigned long long int getFileLength(unsigned long long int p);
    unsigned long long int getFileDate(unsigned long long int p);
    string getName(unsigned long long int length);

    Decompress(string _iFile);
};


#endif //T3_DECOMPRESS_H
