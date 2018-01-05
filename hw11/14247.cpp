#include <iostream>
#include <memory.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int right[7] = {0};
    for (int j = 0; j < 7; j++) {
        cin >> right[j];
    }
    int zhong[8] = {0};
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        // a piao
        for (int j = 0; j < 7; j++) {
            int tmp;
            cin >> tmp;
            for (int k = 0; k < 7; k++) {
                if (tmp == right[k]) {
                    cnt++;
                    break;
                }
            }
        }
        zhong[cnt]++;
    }
    for (int i = 7; i > 0; i--) {
        cout << zhong[i] << " ";
    }
    return 0;
}