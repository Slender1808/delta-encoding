#include <iostream>

#include "src/parent.h"
#include "src/child.h"
#include "src/decompress.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        Parent parent = Parent(argv[2]);
        cout << "Type: " << argv[1] << '\n' << argv[2] << '\n';
        if (strcmp(argv[1], "c") == 0) {
            cout << "Compress\n" << argv[3] << '\n' << argv[4] << '\n';
            Child child = Child(argv[3]);
            child.save(argv[4], parent);
        } else {
            cout << "Decompress\n" << argv[3] << '\n' << argv[4] << '\n';
            Decompress decompress = Decompress(argv[3]);
            decompress.start(argv[4], parent);
        }
        return 0;
    }
    return 1;
}
