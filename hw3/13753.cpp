#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int out[MAX];

void qsort(int* arr, int lo, int hi);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    qsort(arr, 0, n - 1);

    int cur = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != cur) {
            out[cnt++] = arr[i];
            cur = arr[i];
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << out[i] << " ";
    }
    
    return 0;
}

void qsort(int* arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int start = lo;
    int end = hi;
    int key = arr[lo];
    while (lo < hi) {
        while (lo < hi && arr[hi] >= key) {
            --hi;
        }
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] <= key) {
            ++lo;
        }
        arr[hi] = arr[lo];
    }
    arr[lo] = key;
    qsort(arr, start, lo - 1);
    qsort(arr, lo + 1, end);
}