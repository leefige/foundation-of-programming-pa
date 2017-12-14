#include "Program.h"
#include <memory.h>
using namespace std;

#define MAX_NUM 800
#define MAX_TIME 1440   // 24 * 60

int size = 0;

int record[MAX_NUM][MAX_TIME];

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
    const vector<Prog>& pro = program.getProg();
    size = pro.size();
    printf("%dmin\n", watch(pro, size - 1, MAX_TIME - 1));
    return 0;
}

