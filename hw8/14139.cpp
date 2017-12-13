#include <iostream>
#include <algorithm>
using namespace std;

struct obj {
    int cnt;
    int pre;
    int after;
    int delta;

    obj() {}

    obj (int _cnt, int _pre, bool _half) {
        cnt = _cnt;
        pre = 2 * _pre;
        after = _half ? _pre : 2 * _pre;
        delta = _half ? _pre : 0;
    }
};

int comp(const void* _a, const void* _b) {
    obj* a = (obj*) _a;
    obj* b = (obj*) _b;
    if (a->delta != b->delta) {
        return b->delta - a->delta;
    } else if (a->after != b->after) {
        return a->after - b->after;
    } else {
        return a->cnt - b->cnt;
    }
}

int compInt(const void* _a, const void* _b) {
    int* a = (int*) _a;
    int* b = (int*) _b;
    return *a - *b;
}

int main() {

    int N;
    int S;
    cin >> S >> N;
    S = S * 2;
    obj list[2000];
    int bought[2000];
    for (int i = 0; i < N; i++) {
        int pre;
        int half;
        cin >> pre >> half;
        list[i] = obj(i + 1, pre, half == 1);
    }

    qsort(list, N, sizeof(obj), comp);
    bool buy = false;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S >= list[i].after) {
            bought[cnt++] = list[i].cnt;
            S -= list[i].after;
            buy = true;
        }
        if (S <= 0) {
            break;
        }
    }
    if (!buy) {
        cout << 0;
    } else {
        qsort(bought, cnt, sizeof(int), compInt);
        for (int i = 0; i < cnt; i++) {
            cout << bought[i] << " ";
        }
    }
    return 0;
}