//
// Created by jadson on 06/01/2022.
//

#ifndef T3_INDEX_H
#define T3_INDEX_H

#include <iostream>
#include <bitset>

using namespace std;

class Index {
public:
    unsigned char place;
    unsigned int block;

    string to_string();
    unsigned long int to_int(char (&buffer)[2]);

    Index(bool iPlace,unsigned int iBlock);
};


#endif //T3_INDEX_H
