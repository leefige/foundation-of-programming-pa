#include "Program.h"
#include <iostream>
#include <memory.h>
using namespace std;

#define MAX_NUM 800
#define MAX_TIME 1440   // 24 * 60

int size = 0;
int len[MAX_NUM][MAX_NUM];
int end[MAX_NUM][MAX_NUM];

int record[MAX_NUM][MAX_TIME];

int max(int a, int b) {
    return a >= b ? a : b;
}

bool comp(const Prog& a, const Prog& b) {
    if (a.st == b.st) {
        return a.ed < b.ed;
    }
    return a.st < b.st;
}

int watch(const vector<Prog>& pro, int n, int endTime) {
    if (n < 0) {
        return 0;
    }
    if (record[n][endTime] >= 0) {
        return record[n][endTime];
    }
    int max = watch(pro, n - 1, endTime);
    if (pro[n].ed <= endTime) {
        int val = watch(pro, n - 1, pro[n].st) + pro[n].len;
        if (val > max) {
            max = val;
        }
    }
    record[n][endTime] = max;
    return max;
}

int main(int argc, char** argv) {
    // init
    memset(record, -1, sizeof(int) * MAX_NUM * MAX_TIME);

    // pre-process
    Program program;
    program.sortProg(comp);

    // calc
    int maxLen = 0;
    const vector<Prog>& pro = program.getProg();
    size = pro.size();
    cout << watch(pro, size - 1, MAX_TIME - 1) << "min\n";
    return 0;
}

