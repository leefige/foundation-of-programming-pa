#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();

    // case 1
    if (lena != lenb) {
        cout << "1\n";
        return 0;
    }

    // others
    bool caseDiff = true;
    bool same = true;
    for (int i = 0; i < lena; i++) {
        if (a.at(i) == b.at(i)) {
            continue;
        }
        same = false;
        if (abs(a.at(i) - b.at(i)) == 32) {
            continue;
        }
        caseDiff = false;
    }
    if (same) {
        cout << "2\n";
    }
    else if (caseDiff) {
        cout << "3\n";
    }
    else {
        cout << "4\n";
    }
    return 0;
}