//
// Created by jadson on 10/01/2022.
//

#include "decompress.h"

unsigned long long int Decompress::getPFileLength() {
    string fileType = ".compress";
    char *buffer = new char[9];
    string tmp;


    for (unsigned long long int i = 0; i < length; i++) {
        iFile.seekg(i, iFile.beg);
        iFile.read(buffer, 9);
        tmp = buffer;

        if (fileType.compare(tmp) == 0) {
            return iFile.tellg();
        }
    }

    return 0;
}

unsigned long long int Decompress::getFileLength(unsigned long long int p) {
    char buffer[9] = {0};

    iFile.seekg(p, iFile.beg);
    iFile.read(buffer, 8);

    return vecChar8toInt64(buffer);
}

unsigned long long int Decompress::getFileDate(unsigned long long int p) {
    char buffer[9] = {0};

    iFile.seekg(p + 8, iFile.beg);
    iFile.read(buffer, 8);

    return vecChar8toInt64(buffer);
}

string Decompress::getName(unsigned long long int length) {
    char *buffer = new char[length];

    iFile.seekg(0, iFile.beg);
    iFile.read(buffer, length);
    return string(buffer);
}

bool Decompress::start(string _fileName, Parent &parent) {
    unsigned long long int pFileLength = getPFileLength();
    unsigned long long int pBlocks = pFileLength + 16;
    unsigned long long int fileLength = getFileLength(pFileLength);
    unsigned long long int nBlock = (((fileLength % 8) > 0) ? (fileLength / 8) + 1 : (fileLength / 8));
    unsigned long long int fileDate = getFileDate(pFileLength);
    string fileName = getName(pFileLength);

    cout << "p: " << pFileLength
         << " length: " << fileLength
         << " nblock: " << nBlock
         << " fileName: " << fileName
         << " fileDate: " << fileDate
         << '\n';

    ofstream oFile(_fileName, ofstream::binary);
    for (unsigned int i = 0; i < nBlock; i++) {
        cout << "pB: " << pBlocks + i * 2 << '\n';
        iFile.seekg(pBlocks + i * 2, iFile.beg);

        char tmp[2];
        if (iFile.get(tmp[0])) {
            if (tmp[0] == -128) {
                // interno
                iFile.get(tmp[1]);
                unsigned int iP = Index(0, 0).to_int(tmp);

                cout << "i: " << (pBlocks) + i * 2 << " IPpiece: " << iP << '\n';
                cout << "pBlock: " <<  (pBlocks + (nBlock * 2)) + (iP-1) *8 <<  '\n';

                iFile.seekg((pBlocks + (nBlock * 2)) + (iP-1) *8, iFile.beg);
                char block[9] = {0};
                iFile.read(block, 8);
                cout << "85: " << block << '\n';
                string tmpS = block;
                oFile.write(tmpS.c_str(), tmpS.size());
            } else {
                // externo
                iFile.get(tmp[1]);
                unsigned int iP = Index(0, 0).to_int(tmp);
                cout << "i: " << pBlocks + i * 2 << " EPpiece: " << iP << '\n';
                cout << "externo save: " << parent.dic.block[iP] << '\n';
                oFile.write(parent.dic.block[iP].c_str(), 8);
            }
        }
    }

    return 1;
}

Decompress::Decompress(string _iFile) {
    if (_iFile != "") {
        path = _iFile;
        iFile.open(path.c_str());
        if (iFile.is_open()) {
            iFile.seekg(0, iFile.end);
            length = iFile.tellg();
            iFile.seekg(0, iFile.beg);
            cout << "length: " << length << '\n';
        } else {
            cout << "error: not is_open file decompress\n";
        }
    }
}