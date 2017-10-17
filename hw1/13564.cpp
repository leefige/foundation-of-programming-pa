#include <cstdio>

long long calc(long long a, long long b, long long c) { // ALLERT: a < c
    if (b == 1) {
        return a;
    }
    if (b == 0) {
        return 1;
    }
    // odd
    if (b % 2 == 1) {
        long long mo = calc(a, b >> 1, c) % c;
        return (a * ((mo * mo) % c)) % c;
    }
    // even
    if (b % 2 == 0) {
        long long mo = calc(a, b >> 1, c) % c;
        return (mo * mo) % c;
    }
}

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long ans = calc(a % c, b, c);
    printf("%lld", ans);
    return 0;
}