#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 8
#define BOUND 8600

vector<int> arr[MAX + 1];
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
void genNum(int cur) {
    int last = cur - 1;
    for (vector<int>::iterator it = arr[last].begin(); it != arr[last].end(); it++) {
        int base = *it * 10;
        for (int j = 1; j < 10; j = j + 2) {
            int check = base + j;
            if (isPrim(check)) {
                arr[cur].push_back(check);
            }
        }
    }
}

int main() {
    // init
    genPrim();
    arr[1].push_back(2);
    arr[1].push_back(3);
    arr[1].push_back(5);
    arr[1].push_back(7);
    
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        genNum(i);
    }

    // print
    for (vector<int>::iterator it = arr[n].begin(); it != arr[n].end(); it++) {
        cout << *it << endl;
    }
    return 0;
}