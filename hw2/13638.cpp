#include <iostream>
#include <memory.h>
using namespace std;

int fib[20];

int getFib(int i) {
    if (fib[i] != 0) {
        return fib[i];
    }
    return getFib(i - 1) + getFib(i - 2);
}

void calculate(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += getFib(i);
    }
    cout << sum << endl;
    return;
}

int main() {
    memset(fib, 0, 20 * sizeof(int));
    fib[0] = fib[1] = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        calculate(n);
    }
}