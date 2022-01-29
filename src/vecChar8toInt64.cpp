//
// Created by jadson on 05/01/2022.
//

#include "vecChar8toInt64.h"

unsigned long long vecChar8toInt64(char (&buffer)[sizeVecChar]) {
    string s;
    s.append(bitset<8>(buffer[0]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[1]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[2]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[3]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[4]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[5]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[6]).to_string<char, string::traits_type, string::allocator_type>());
    s.append(bitset<8>(buffer[7]).to_string<char, string::traits_type, string::allocator_type>());

    unsigned long long int result = strtoull(s.c_str(), NULL, 2);
    //cout << "data: " << result << endl;
    //cout << "BIN: " << s << endl;
    return result;
}