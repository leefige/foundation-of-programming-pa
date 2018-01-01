#include <iostream>
#include <memory.h>
using namespace std;

int num[40][900];

int getNum(int n, int rest) {
    if (num[n][rest] >= 0) {
        return num[n][rest];
    }
    if (n > rest) {
        num[n][rest] = getNum(n - 1, rest); // won't take this num
    } else {
        num[n][rest] = getNum(n - 1, rest) + getNum(n - 1, rest - n);
    }
    // cout << n << ", " << rest << "=" << num[n][rest] << "\n";
    return num[n][rest];
}

int main() {
    memset(num, -1, sizeof(int)*40*900);
    int N;
    cin >> N;

    int sum = (1 + N) * N / 2;
    if (sum % 2) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i <= N; i++) {
        num[i][0] = 1;
    }

    for (int i = 0; i <= sum / 2; i++) {
        num[0][i] = 0;
    }

    cout << getNum(N, sum / 2);
    return 0;
}