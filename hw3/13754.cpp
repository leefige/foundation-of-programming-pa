#include <iostream>
#include <cmath>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 100000000
#define DIGIT_NUM 9

char* prims;

vector<int> mirrors;

bool isPrim(int p) {
    if (prims[p] == -1) {   // haven't been checked yet
        prims[p] = 1;
        int stop = sqrt(p) + 1;
        for (int i = 2; i < stop; i++) {
            if (p % i == 0) {
                prims[p] = 0;
                break;
            }
        }
    }
    return prims[p];
}

bool isMirror(int m) {
    int tmp[9];
    int ptr = 0;
    while (m > 0) {
        int mod = m % 10;
        m /= 10;
        tmp[ptr++] = mod;
    }
    for (int i = 0; i < ptr/2; i++) {
        if (tmp[i] != tmp[ptr - i - 1]) {
            return false;
        }
    }
    return true;
}

int tens(int n) {
    if (n == 0) {
        return 1;
    }
    return 10 * tens(n - 1);
}

void genMirrow(int st, int ed) {
    // set up
    int digits[DIGIT_NUM] = {0};
    digits[0] = 1;
    int tmp = st;
    int cnt = 0;
    while (tmp > 0) {
        digits[cnt++] = tmp % 10;
        tmp /= 10;
    }
    cnt--;

    // generate
    int next = 0;
    while (next <= ed) {
        // for each cnt of digits
        for ( ; cnt <= DIGIT_NUM; cnt++) {
            // for each digit
            for (int i = 0; i <= (cnt - 1) / 2; i++) {
                int sum = 0;
                for (int cur = digits[i]; cur <= 9; cur++) {
                    sum += cur * (tens(i) + tens(cnt - i - 1));
                }
            }
            memset(digits, 0, DIGIT_NUM * sizeof(int));
            digits[0] = 1;
        }
    }

}

int main() {
    prims = new char[MAX];
    memset(prims, -1, MAX*sizeof(char));
    int st, ed;
    cin >> st >> ed;
    for (int i = st; i <= ed; i++) {
        if (isPrim(i) && isMirror(i)) {
            cout << i << endl;
        }
    }
    delete[] prims;
    return 0;
}