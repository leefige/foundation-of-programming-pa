#include <iostream>
using namespace std;

#define MAX 1000
int seq[MAX];
int stack[MAX];

// bin search
int search(int arr[], int len, int key) {
    int l = 0, r = len, mid;    // [l, r)
    while(l < r) {
        mid = (l + r) / 2;
        if (key < arr[mid]) {
            r = mid;            // [l, mid)
        } else {
            l = mid + 1;        // (mid, r)
        }
    }
    return l--;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    stack[0] = seq[0];
    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (seq[i] > stack[cur - 1]) {
            stack[cur++] = seq[i];
        } else {
            int pos = search(stack, cur, seq[i]);
            stack[pos] = seq[i];
        }
    }
    cout << cur;
    return 0;
}