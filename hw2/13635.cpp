#include <iostream>
using namespace std;

#define MAXLEN 1984

int getMin(int[], int, int);

int main() {
    int n, Q;
    cin >> n >> Q;
    int arr[MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < Q; i++) {
        int lo, hi;
        cin >> lo >> hi;
        cout << getMin(arr, lo, hi) << endl;
    }
}

int getMin(int arr[], int lo, int hi) {
    int min = INT_MAX;
    for (; lo <= hi; lo++) {
        if (arr[lo] < min) {
            min = arr[lo];
        }
    }
    return min;
}