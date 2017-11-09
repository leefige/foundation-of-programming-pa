#include <iostream>
using namespace std;

long long getPos(long long** arr, int x, int y) {
    long long* row = arr[x];
    return row[y];
}

long long calc(long long** arr, int n) {
    if (n == 1) {
        cout << **arr << endl;
        return **arr;
    }
    long long step = 0;
    for (int i = 0; i < n; i++) {
        long long* row = arr[1];
        step += getPos(arr, 0, i) * calc(&(&row[i]), n);
    }
    return step;
}

int main() {
    int n;
    cin >> n;
    long long** arr = new long long*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new long long[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << calc(arr, n);
    return 0;
}