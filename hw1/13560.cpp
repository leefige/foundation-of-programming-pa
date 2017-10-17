#include <cstdio>

int main() {
    for (int i = 1; i <=9 ; i++) {
        for (int j = 0; j <=9 ; j++) {
            for (int k = 0; k <=9 ; k++) {
                int num = 100 * i + 10 * j + k;
                if (i * i * i + j * j * j + k * k * k == num) {
                    printf("%d\n", num);
                }
            }
        }
    }
    return 0;
}