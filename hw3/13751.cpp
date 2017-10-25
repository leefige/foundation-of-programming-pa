#include <iostream>
#include <vector>
using namespace std;

struct Rect {
    int lx, ly, rx, ry;
    
    Rect(int _lx, int _ly, int lenx, int leny) {
        lx = _lx;
        ly = _ly;
        rx = lx + lenx;
        ry = ly + leny;
    }

    bool contains(int x, int y) {
        return (x <= rx) && (x >= lx) && (y <= ry) && (y >= ly);
    }
};

vector<Rect> rects;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int lx, ly, lenx, leny;
        cin >> lx >> ly >> lenx >> leny;
        rects.push_back(Rect(lx, ly, lenx, leny));
    }

    int x, y;
    cin >> x >> y;
    int atRect = -1;
    for (int i = 0; i < rects.size(); i++) {
        if (rects[i].contains(x, y)) {
            atRect = i + 1;
        }
    }

    cout << atRect;
    return 0;
}