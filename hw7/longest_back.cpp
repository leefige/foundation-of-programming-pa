#include "Program.h"
#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;

#define MAX 200

int size = 0;
int len[MAX][MAX];
int end[MAX][MAX];

int record[MAX][1440];

bool comp(const Prog& a, const Prog& b) {
    if (a.st == b.st) {
        return a.ed < b.ed;
    }
    return a.st < b.st;
}

// force, not valid
int watch(const vector<Prog>& pro, int n, int curTime) {
    if (record[n][curTime] >= 0) {
        return record[n][curTime];
    }
    if (curTime > 1000) {
        printf("watching(%d, %d)\n", n, curTime);
    }
    if (n >= size) {
        return 0;  // check next
    }
    if (pro[n].st < curTime) {
        record[n][curTime] = watch(pro, n + 1, curTime);
        return record[n][curTime];  // check next
    }
    record[n][curTime] = max(pro[n].len + watch(pro, n + 1, pro[n].ed), watch(pro, n + 1, curTime));
    return record[n][curTime];
}

int main(int argc, char** argv) {
    // memset(len, 0, sizeof(int) * MAX * MAX);
    // memset(end, 0, sizeof(int) * MAX * MAX);
    memset(record, -1, sizeof(int) * MAX * 1440);
    Program program;
    program.sortProg(comp);
    int maxLen = 0;
    const vector<Prog>& pro = program.getProg();
    size = pro.size();
    printf("total cnt: %d\n", pro.size());

    // init
    // for (int i = 0; i < size; i++) {
        // len[i][i] = pro[i].len;
        // end[i][i] = pro[i].ed;
    // }
    
    // for (int i = 0; i < size; i++) {
    //     for (int j = 1; j < size; j++) {
    //         for (int k = i; k < j; k++) {       // [i, k] + [k+1, j]
    //             len[i][j] = max(len[i][j], len[i][k] + len[k+1][j]);
    //         }
    //     }
    // }
    cout << watch(pro, 0, 0);
    return 0;
}

