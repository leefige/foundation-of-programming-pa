#include <cstdio>
#include <cstdlib>

int main() {
    int st, ed;
    scanf("%d %d", &st, &ed);
    int cnt = 0;
    for (int i = st; i <= ed; i++) {
        if (i / 1000 == 2)
            cnt++;
        int tmp = i % 1000;
        if (tmp / 100 == 2)
            cnt++;
        tmp %= 100;
        if (tmp / 10 == 2)
            cnt++;
        tmp %= 10;
        if (tmp / 1 == 2)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}