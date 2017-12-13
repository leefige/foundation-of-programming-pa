#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct obj {
    int cnt;
    double after;
    double delta;

    obj (int _cnt, int _pre, bool _half) {
        cnt = _cnt;
        after = _half ? _pre : _pre * 2;
        delta = _half ? _pre : 0;
    }
};

bool comp(const obj& a, const obj& b) {
    if (a.delta != b.delta) {
        return a.delta > b.delta;
    } else if (a.after != b.after) {
        return a.after < b.after;
    } else {
        return a.cnt < b.cnt;
    }
}

int main() {

    int S, N;
    cin >> S >> N;
    S *= 2;
    vector<obj> list;
    vector<int> bought;
    for (int i = 0; i < N; i++) {
        int pre;
        bool half;
        cin >> pre >> half;
        list.push_back(obj(i + 1, pre, half));
    }

    sort(list.begin(), list.end(), comp);
    bool buy = false;
    for (vector<obj>::iterator i = list.begin(); i != list.end(); i++) {
        if (S >= i->after) {
            bought.push_back(i->cnt);
            S -= i->after;
            buy = true;
        }
        if (S <= 0) {
            break;
        }
    }
    if (!buy) {
        cout << 0;
    } else {
        sort(bought.begin(), bought.end());
        for (vector<int>::iterator i = bought.begin(); i != bought.end(); i++) {
            cout << *i << " ";
        }
    }
    return 0;
}