#include <cstdio>
#include <vector>
#include <algorithm>

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

struct Factor {
    int prim;
    int cnt;

    Factor(int p) {
        prim = p;
        cnt = 1;
    }

    void inc() {
        cnt++;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    int n = N;

    vector<Factor> facs;
    for (int i = 2; i <= n; i++) {
        if (isPrim(i)) {
            if (n % i == 0) {
                facs.push_back(Factor(i));
                n /= i;
            }
            while (n % i == 0) {
                facs.back().inc();
                n /= i;
            }
        }
    }

    // output
    printf("%d=", N);
    for (int i = 0; i < facs.size(); i++) {
        if (i > 0) {
            printf("*");
        }
        printf("%d", facs[i].prim);
        if (facs[i].cnt > 1) {
            printf("^%d", facs[i].cnt);
        }
    }
    return 0;
}