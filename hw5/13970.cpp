#include <iostream>
using namespace std;

#define MAX 100000

class ID {
public:
    static const int len = 18;
private:
    static const int birthStart = 6;
    static const int birthEnd = 13;
    char number[len];

public:
    void set(int idx, char num) {
        number[idx] = num;
    }

    char at(int idx) {
        return number[idx];
    }

    static bool lt(ID a, ID b) {
        for (int i = birthStart; i <= birthEnd; i++) {
            if (a.at(i) < b.at(i)) {
                return true;
            } 
            else if (a.at(i) > b.at(i)) {
                return false;
            }
        }
        for (int i = 0; i < len; i++) {
            if (a.at(i) < b.at(i)) {
                return true;
            }
            else if (a.at(i) > b.at(i)) {
                return false;
            }
        }
        return false;
    } 

    void print() {
        for (int i = 0; i < len; i++) {
            cout << at(i);
        }
        cout << endl;
    }
};

void mySort(ID[], int, int);

ID arr[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char tmp[ID::len + 1];
        cin >> tmp;
        for (int j = 0; j < ID::len; j++) {
            arr[i].set(j, tmp[j]);
        }
    }
    mySort(arr, 0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        arr[i].print();
    }
    return 0;
}

void mySort(ID arr[], int lo, int hi) {
    if (hi <= lo) {
        return;     // base
    }
    int first = lo, last = hi;
    ID key = arr[first];

    while (first < last) {
        while (first < last && ID::lt(key, arr[last])) {
            --last;
        }
        arr[first] = arr[last];
        while (first < last && ID::lt(arr[first], key)) {
            ++first;
        }
        arr[last] = arr[first];
    }   // assert: first == last
    arr[first] = key;
    mySort(arr, lo, first - 1);
    mySort(arr, first + 1, hi);
}
