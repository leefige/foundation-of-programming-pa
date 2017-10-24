#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    int st;
    int ed;
    Line(int s, int e) {
        st = s;
        ed = e;
    }
};

vector<Line> lines;

bool comp (const Line& a, const Line& b) {
    return a.st < b.st;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, ed;
        cin >> st >> ed;
        lines.push_back(Line(st, ed));
    }
    sort(lines.begin(), lines.end(), comp);

    int cur_st = lines[0].st;
    int cur_ed = lines[0].ed;
    int length = 0;
    for (int i = 1; i < lines.size(); i++) {
        if (lines[i].ed <= cur_ed) {
            continue;
        }
        if (lines[i].st <= cur_ed) {
            cur_ed = lines[i].ed;
        }
        else {
            length += cur_ed - cur_st;
            cur_st = lines[i].st;
            cur_ed = lines[i].ed;
        }
    }
    length += cur_ed - cur_st;
    cout << length;
    return 0;
}