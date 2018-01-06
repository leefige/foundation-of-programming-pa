#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> prims;
int maxPrim = 1;

bool isPrim(int p) {
    if (p < maxPrim) {
        if (find(prims.begin(), prims.end(), p) == prims.end()) {
            return 0;
        }
        else {
            return 1;
        }
    }

    // haven't been checked yet
    for (int i = 2; i < p / 2 + 1; i++) {
        if (p % i == 0) {
            maxPrim = p;
            prims.push_back(maxPrim);
            return 0;
        }
    }
    return 1;
}

int main() {
    int p = 1000;
    isPrim(p);
    for (int i = 0; i < prims.size(); i++) {
        cout << prims[i] << " ";
    }
    return 0;
}