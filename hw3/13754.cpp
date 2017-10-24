#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define DIGIT_NUM 9
#define BOUND 3163

vector<int> mirrors;

vector<int> prims;

void genPrim() {
    bool notPrim[BOUND];
    memset(notPrim, 0, BOUND * sizeof(bool));
    int ed = sqrt(BOUND);
    for (int i = 2; i <= ed; i++)
        if (!notPrim[i])
            for (int j = i * i; j <= BOUND; j += i)
                notPrim[j] = 1;
    for (int i = 2; i <= BOUND; i++)
        if (!notPrim[i])
            prims.push_back(i);
}

bool isPrim(int p) {
    if (p < prims.at(prims.size() - 1)) {
        if (find(prims.begin(), prims.end(), p) == prims.end()) {
            return 0;
        }
        else {
            return 1;
        }
    }
    // haven't been checked yet
    for (int i = 0; i < prims.size(); i++) {
        if (p % prims[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int tens(int n) {
    if (n == 0) {
        return 1;
    }
    return 10 * tens(n - 1);
}

void genMirrow(int st, int ed) {
    if (5 >= st) {
        mirrors.push_back(5);
    }

    if (7 >= st) {
        mirrors.push_back(7);
    }

    if (11 >= st) {
        mirrors.push_back(11);
    }

    // 3 digits
    for (int i = 1; i <= 9; i ++) {
        for (int j = 0; j <= 9; j++) {
            int sum = 101 * i + 10 * j;
            if (sum > ed) {
                return;
            }
            if (sum >= st && isPrim(sum)) {
                mirrors.push_back(sum);
            }
        }
    }
    // 5 digits
    for (int i = 1; i <= 9; i ++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                int sum = 10001 * i + 1010 * j + 100 * k;
                if (sum > ed) {
                    return;
                }
                if (sum >= st && isPrim(sum)) {
                    mirrors.push_back(sum);
                }
            }
        }
    }

    // 7 digits
    for (int i = 1; i <= 9; i ++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int h = 0; h <= 9; h++) {
                    int sum = 1000001 * i + 100010 * j + 10100 * k + 1000 * h;
                    if (sum > ed) {
                        return;
                    }
                    if (sum >= st && isPrim(sum)) {
                        mirrors.push_back(sum);
                    }
                }
            }
        }
    }
}

int main() {
    int st, ed;
    cin >> st >> ed;
    genPrim();

    genMirrow(st, ed);
    int size = mirrors.size();
    for (int i = 0; i < size; i++) {
        cout << mirrors[i] << endl;
    }
    return 0;
}