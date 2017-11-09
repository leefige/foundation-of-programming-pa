#include <iostream>
#include <cmath>
using namespace std;

int putBall(int n, int num) {
    if (n == 0) {
        return 1;
    }
    if (num == 1) {
        return 1;
    }
    if (n >= num) {
        return putBall(n, num - 1) + putBall(n - num, num);
    }
    else {
        return putBall(n, n);
    }
}

int main() {
    int n, num;
    cin >> n >> num;
    cout << putBall(n - num, num);
    return 0;
}