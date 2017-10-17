#include <cstdio>
#include <cmath>
#include <memory.h>

#define MAX 50001

int prims[MAX];

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

int main() {
    memset(prims, -1, sizeof(int) * MAX);
    prims[0] = prims[1] = 0;
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        int num;
        bool isSon = 0;
        scanf("%d", &num);
        int stop = num / 2 + 1;
        for (int j = 2; j < stop; j++) {
            if (isPrim(j) && (num % j == 0) && isPrim(num / j)) {
                isSon = 1;
                break;
            }
        }
        isSon ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}