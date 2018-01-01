#include <iostream>
using namespace std;

int chess[8][8];
int pos[8] = {-1};
long long maxNum = -1;

bool attack(int x, int y) {
    if (pos[x] == pos[y])			// 直线攻击
        return true;
    if (pos[x] + x == pos[y] + y)	// 斜线攻击
        return true;
    if (pos[x] - x == pos[y] - y)	// 反斜线攻击
        return true;
    return false;

}

void queen(int n) {
    for (int i = 0; i < 8; i++) {
        pos[n] = i;
        bool attacked = false;
        for (int j = 0; j < n; j++) {
            if (attack(j, n)) { 
                attacked = true; 
                break; 
            }
        }
        if (attacked) {
            continue;
        }
        if (n == 7) { // 如果所有的皇后已经放置了，输出
            long long sum = 0;
            for (int q = 0; q < 8; q++) {
                sum += chess[pos[q]][q];
            }
            if (sum > maxNum) {
                maxNum = sum;
            }
        } else {	  // 如果没有，则继续放下一个皇后
            queen(n + 1);
        }
        // for (int m = n; m < 8; m++) {
        //     pos[m] = -1;
        // }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }
    queen(0);
    cout << maxNum;
    return 0;
}