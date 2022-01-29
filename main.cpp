#include <iostream>

#include "src/parent.h"
#include "src/child.h"
#include "src/decompress.h"

using namespace std;

int main() {
    Parent parent = Parent("../test.txt");

    cout << "\nChild\n";
    Child child = Child("../test2.txt");
    child.save("../out.compress",parent);

    cout << "\nDec\n";
    Decompress decompress = Decompress("../out.compress");
    decompress.start("../out",parent);

    return 0;
}
