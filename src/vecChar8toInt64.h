//
// Created by jadson on 05/01/2022.
//

#ifndef T3_VECCHAR8TOINT64_H
#define T3_VECCHAR8TOINT64_H

#define SIZE_VEC_CHAR 9;

#include <iostream>
#include <bitset>

using namespace std;

const int sizeVecChar = SIZE_VEC_CHAR;

unsigned long long vecChar8toInt64(char (& buffer)[sizeVecChar]);

#endif //T3_VECCHAR8TOINT64_H
