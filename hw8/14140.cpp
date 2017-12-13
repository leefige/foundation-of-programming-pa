#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;

// #define DEBUG
#define MAX 1000

const long long INF = INT_MAX;

int stones[MAX + 1];
long long sum[MAX + 1];    // sum[i] = [1, i]
long long cost[MAX + 1][MAX + 1];

long long getSum(int i, int j) {    // [i, j]
    if (i > j) {
        return 0;
    }
    return sum[j] - sum[i - 1];
}


int main() {
    memset(cost, 0, sizeof(long long) * (MAX + 1));
    int n; 
    cin >> n;
    stones[0] = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> stones[i];
        // calc sum
        sum[i] = sum[i - 1] + stones[i];
    }

    for (int delta = 1; delta < n; delta++) {   // distance to merge
        for (int i = 1; i < n; i++) {           // left
            int j = i + delta;                  // right
            if (j > n) {
                break;
            }
            cost[i][j] = INF;
            for (int k = i; k < j; k++) {       // [i, k] + [k+1, j]
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k+1][j] + getSum(i, j));
            }
        }
    }

#ifdef DEBUG
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
#endif

    cout << cost[1][n];

    return 0;
}