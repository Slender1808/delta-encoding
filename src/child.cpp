//
// Created by jadson on 20/01/2022.
//

#include "child.h"

int Child::save(string _fileName, Parent &parent) {
    fstream oFile(_fileName.c_str(), fstream::in | fstream::out | fstream::app);

    unsigned long long int getTime = chrono::system_clock::to_time_t(chrono::system_clock::now());

    cout << "name: " << dic.name << '\n';
    cout << "length: " << dic.length << '\n';
    cout << "time: " << getTime << '\n';

    string oFileName = dic.name + ".compress";
    oFile.write(oFileName.c_str(), oFileName.size());
    oFile.write(int64toString(dic.length).c_str(), 8);
    oFile.write(int64toString(getTime).c_str(), 8);

    dic.file.open(dic.path.c_str());

    vector<array<char,9>> tmpBlock;
    array<char,9> charray;
    for (unsigned long long int i = 0; i < dic.length; i = i + 8) {
        char buffer[9] = {0};
        dic.file.read(buffer, 8);
        //cout << i << ": " << buffer << '\n';
        unsigned int parentID = parent.dic.searchBlock(buffer);
        if (parentID != UINT_MAX) {
            oFile.write(Index(0, parentID).to_string().c_str(), 2);
        } else {
            unsigned int childID = dic.searchBlock(buffer);
            //cout << "childID: " << childID << '\n';
            if (childID != UINT_MAX) {
                oFile.write(Index(1, childID).to_string().c_str(), 2);
                memcpy(charray.data(),buffer,9);
                tmpBlock.push_back(charray);
            } else {
                cout << "error: block not found\n";
            }
        }
    }

    for (unsigned int i = 0; i < tmpBlock.size(); ++i) {
        //cout << i << " iBlock: " << tmpBlock[i].data() << '\n';
        oFile.write(tmpBlock[i].data(), 8);
    }

    return true;
}

Child::Child(string _fileName) {
    dic = Dic(_fileName);
}