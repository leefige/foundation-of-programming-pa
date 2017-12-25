#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
using namespace std;

#define BOUND 20000

vector<int> prims;

void genPrim() {
    bool notPrim[BOUND];
    memset(notPrim, 0, BOUND * sizeof(bool));
    int ed = sqrt(BOUND);
    for (int i = 2; i <= ed; i++) {
        if (!notPrim[i]) {
            for (int j = i * i; j <= BOUND; j += i) {
                notPrim[j] = 1;
            }
        }
    }
    for (int i = 2; i <= BOUND; i++) {
        if (!notPrim[i]) {
            prims.push_back(i);
        }
    }
}

int main() {
    genPrim();
    int p;
    cin >> p;
    vector<int>::iterator it = find(prims.begin(), prims.end(), p);
    int pre = *(it - 1);
    int after = *(it + 1);
    int dis1 = p - pre;
    int dis2 = after - p;
    // cout << pre << " " << after << endl;
    if (dis1 <= dis2) {
        cout << pre << " " << dis1;
    } else {
        cout << after << " " << dis2;
    }
    return 0;
}