//
// Created by jadson on 05/01/2022.
//

#include "int64toString.h"


string int64toString(unsigned long long int number) {
    string str = bitset<64>(number).to_string();
    string result;

    for (int i = 0; i < 8; i++) {
        string tmp = str.substr(i * 8, 8);

        //cout << "i: " << i << " tmp: " << tmp << endl;

        unsigned char value = bitset<8>(tmp).to_ullong(); //binToDec
        result.push_back(value);
    }

    return result;
}
