//
// Created by jadson on 20/01/2022.
//

#ifndef T3_PARENT_H
#define T3_PARENT_H

#include <iostream>

#include "dic.h"

using namespace std;

class Parent {
private:
public:
    Dic dic = Dic("");
    Parent(string _fileDic);
};


#endif //T3_PARENT_H
