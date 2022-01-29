//
// Created by jadson on 20/01/2022.
//

#ifndef T3_CHILD_H
#define T3_CHILD_H


#include <iostream>
#include <fstream>
#include <cinttypes>
#include <array>
#include <time.h>
#include <chrono>
#include <filesystem>
#include <climits>
#include<array>

#include "parent.h"
#include "int64toString.h"
#include "index.h"

using namespace std;
namespace fs = std::filesystem;

class Child {
public:
    int save(string _fileName, Parent &parent);
    Dic dic = Dic("");
    Child(string _fileName);
};


#endif //T3_CHILD_H
