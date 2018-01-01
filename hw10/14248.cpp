#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Milk {
    int p;
    int a;

    Milk(int _p, int _a) {
        p = _p;
        a = _a;
    }
};

bool comp(const Milk& a, const Milk& b) {
    return a.p < b.p;
}

vector<Milk> arr;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int p, a;
        cin >> p >> a;
        arr.push_back(Milk(p, a));
    }
    sort(arr.begin(), arr.end(), comp);

    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (N < arr[i].a) {
            sum += N * arr[i].p;
            break;
        }
        sum += arr[i].p * arr[i].a;
        N -= arr[i].a;
    }
    cout << sum;
    return 0;
}