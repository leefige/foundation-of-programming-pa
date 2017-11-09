#include <iostream>
#include <cmath>
using namespace std;

void divide(int n, int num, int& cnt) {
    // cout << "call divide(" << n << "," << num <<")\n";
    if (n < 1 || num < 1 || n < num) {
        // cout << "fail\n";
        return;
    }
    if (num == 1) {
        cnt++;
        // cout<< n << " success!\n";
        return;
    }
    // cout << "[n * (num - 1) / num: " << n * (num - 1) / num << "] ";
    double bound = (double)(n) / (double)(num);
    for (int i = n - 1; (double)i >= bound; i--) {
        // cout << i << " ";
        divide(n - i, num - 1, cnt);
        // cout << "\n";
    }
    return;
}

int main() {
    int cnt = 0;
    int n, num;
    cin >> n >> num;
    divide(n, num, cnt);
    cout << cnt;
    return 0;
}