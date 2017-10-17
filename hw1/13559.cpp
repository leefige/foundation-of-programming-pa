#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ) {
        int sum = 0;
        int st = i;
        for (int j = i; j < n; j++) {
            sum += j;
            if (sum == n) {
                sum = 0;
                printf("%d %d\n", st, j);
                break;
            }
        }
        i++;
    }
    return 0;
}