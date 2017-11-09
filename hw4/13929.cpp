#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define RESULT 6174

void hole(int num, int& cnt);

int main() {
    int num;
    cin >> num;
    int cnt = 0;
    hole(num, cnt);
    cout << cnt;
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

void hole(int num, int& cnt) {
    if (num == RESULT) {
        return;
    }
    int arr[4];
    arr[0] = num % 10; num /= 10;
    arr[1] = num % 10; num /= 10;
    arr[2] = num % 10; num /= 10;
    arr[3] = num % 10;
    qsort(arr, 0, 3);
    // for (int i = 0; i < 4; i ++) {
    //     cout << arr[i] << "\t";
    // }
    // cout <<endl;
    int max = arr[0] + 10*arr[1] + 100*arr[2] + 1000*arr[3];
    int min = arr[3] + 10*arr[2] + 100*arr[1] + 1000*arr[0];
    // cout << max << " " << min << endl;
    hole(max - min, ++cnt);
}