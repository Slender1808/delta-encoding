//
// Created by jadson on 06/01/2022.
//

#include "index.h"

string Index::to_string() {
    //cout << "place: " << place << " block: " << block << '\n';

    string result;

    bitset<16> tmp(block);
    tmp.set(15,place);

    string sBlock = tmp.to_string();

    result.push_back(bitset<8>(sBlock.substr(0, 8)).to_ulong());

    result.push_back(bitset<8>(sBlock.substr(8, 8)).to_ulong());

    //cout << "bin: " << tmp << '\n';

    return result;
}

unsigned long int Index::to_int(char (&buffer)[2]){
    string s;
    s.append(bitset<8>(buffer[0]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[1]).to_string<char, string::traits_type, string::allocator_type>());
    bitset<16> tmp(strtoull(s.c_str(), NULL, 2));
    //cout << "bin: " << tmp << '\n';
    tmp.set(15,0);
    //cout << "bin: " << tmp << '\n';
    return tmp.to_ullong();
}

Index::Index(bool iPlace, unsigned int iBlock) {
    if(iBlock <= 32767){
        place = iPlace;
        block = iBlock;
    } else {
        cout << "error: index\n";
    }
}