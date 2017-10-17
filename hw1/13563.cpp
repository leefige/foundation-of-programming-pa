#include <cstdio>
#include <cmath>

int main() {
    const double PI = 3.14159265;
    int T;
    scanf("%d", &T);
    for (int i = 0; i <T; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        double area = PI * (x * x + y * y);
        int yr = ceil(area / 100);
        printf("%d\n", yr);
    }
    return 0;
}