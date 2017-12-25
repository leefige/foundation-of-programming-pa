#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct SF {
    char str[105];
    int len;
    int idx;
};

bool comp (const SF& a, const SF& b) {
    int len = a.len < b.len ? a.len : b.len;
    for (int i = 0; i < len; i++) {
        if (a.str[i] < b.str[i]) {
            return true;
        } else if (a.str[i] > b.str[i]) {
            return false;
        }
    }
    return a.len < b.len;
}

int main() {
    char buf[105];
    cin >> buf;
    int len = strlen(buf);

    SF* arr = new SF[len];
    for (int i = 0; i < len; i++) {
        strcpy(arr[i].str, buf + i);
        arr[i].idx = i + 1;
        arr[i].len = len - i;
    }

    sort(arr, arr + len, comp);
    for (int i = 0; i < len; i++) {
        cout << arr[i].idx << " ";
    }
    return 0;
}