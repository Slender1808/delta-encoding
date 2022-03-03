#include <iostream>

#include "src/parent.h"
#include "src/child.h"
#include "src/decompress.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        Parent parent = Parent(argv[2]);
        if (argv[1] == "c") {
            cout << "\nCompress\n";
            Child child = Child(argv[3]);
            child.save(argv[4], parent);
        } else {
            cout << "\nDecompress\n";
            Decompress decompress = Decompress(argv[3]);
            decompress.start(argv[4], parent);
        }
        return 0;
    }
    return 1;
}
