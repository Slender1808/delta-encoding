//
// Created by jadson on 20/01/2022.
//

#include "dic.h"

int bcompare (const void *arg1, const void *arg2)
{
    return strcmp ((char *)arg1,*(char **)arg2);
}

unsigned int Dic::searchBlock(string key) {
    auto it = bsearch(key.c_str(), block.data(), block.size(),sizeof(string),bcompare);
    if (it != NULL) {
        return distance(block.data(), (string *)it);
    }
    return UINT_MAX;
}

Dic::Dic(string _fileName) {
    if (_fileName != "") {
        path = _fileName;
        name = fs::path(path).filename();
        file.open(path.c_str());

        if (file.is_open()) {

            file.seekg(0, file.end);
            length = file.tellg();
            file.seekg(0, file.beg);

            for (unsigned long long int i = 0; i < length; i = i + 8) {
                char buffer[9] = {0};
                file.read(buffer, 8);

                if(block.size() == 0){
                    //cout << i << ": " << buffer << '\n';
                    block.push_back(buffer);
                    sort(begin(block), end(block));
                } else {
                    unsigned int unic = searchBlock(buffer);

                    //cout << i << ": " << buffer << ' ' << unic << '\n';
                    if(unic == UINT_MAX){
                        block.push_back(buffer);
                        sort(begin(block), end(block));
                    }
                }
            }
            file.close();
        } else {
            cout << "error: not is_open file dic\n";
        }
    }
}