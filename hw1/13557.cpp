#include <cstdio>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);

    int d = n / 1440;
    int rem = n % 1440;
    int h = rem / 60;
    int m = rem % 60;
    printf("%d %d %d", d, h, m);
    return 0;
}