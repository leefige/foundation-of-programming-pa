#include "Program.h"
using namespace std;

#define MAX_NUM 800
#define MAX_TIME 1440   // 24 * 60

struct Pair {
    int len;
    long long happy;

    Pair() {
        len = -1;
        happy = -1;
    }

    Pair(int l, long long h) {
        len = l;
        happy = h;
    }
};

int size = 0;

Pair happy[MAX_NUM][MAX_TIME];  // will use default ctor to init

bool comp(const Prog& a, const Prog& b) {
    if (a.st == b.st) {
        return a.ed < b.ed;
    }
    return a.st < b.st;
}

Pair watch(const vector<Prog>& pro, int n, int endTime) {
    if (n < 0) {
        return Pair(0, 0);
    }
    if (happy[n][endTime].happy >= 0) {
        return happy[n][endTime];
    }
    Pair max = watch(pro, n - 1, endTime);
    if (pro[n].ed <= endTime) {
        Pair lastVal = watch(pro, n - 1, pro[n].st);
        Pair val(lastVal.len + pro[n].len, lastVal.happy + pro[n].len * pro[n].pref);
        if (val.happy > max.happy) {
            max = val;
        }
    }
    happy[n][endTime] = max;
    return max;
}

int main(int argc, char** argv) {
    // pre-process
    Program program;
    program.sortProg(comp);

    // calc
    const vector<Prog>& pro = program.getProg();
    size = pro.size();
    Pair res = watch(pro, size - 1, MAX_TIME - 1);
    printf("%dmin,%lldhappiness\n", res.len, res.happy);
    return 0;
}

