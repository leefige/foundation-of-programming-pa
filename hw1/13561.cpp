#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // for a
    int suma = 0;
    for (int i = 1; i < a / 2 + 1; i++) {
        if (a % i == 0) {
            // printf("a: %d\n", i);
            suma += i;
        }
    }
    // for b
    int sumb = 0;
    for (int i = 1; i < b / 2 + 1; i++) {
        if (b % i == 0) {
            // printf("b: %d\n", i);
            sumb += i;
        }
    }

    // output
    if (suma == b && sumb == a) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}