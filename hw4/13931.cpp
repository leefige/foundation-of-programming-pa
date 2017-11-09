#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 21

long long mem[MAX];

long long step(const int& n);

int main() {
    memset(mem, -1, MAX * sizeof(long long));
    int h; 
    cin >> h;
    if (h > 20 || h < 4) {
        cout << 0;
    }
    else {
        cout << step(h);
    }
    return 0;
}

long long step(const int& n) {
    if (mem[n] != -1) {
        return mem[n];
    }
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    long long cnt = 0;
    for (int i = 1; i <= 3; i++) {
        cnt += step(n - i);
    }
    mem[n] = cnt;
    return cnt;
}