#include <iostream>
using namespace std;

#define MAX 100

struct Student {
    int id;
    int math;
    int english;
    int chinese;

    void set(int n, int m, int e, int c) {
        id = n;
        math = m;
        english = e;
        chinese = c;
    }

    void print() {
        cout << math << " " << english << " " << chinese << " " << id << endl;
    }
};

void studentSort(Student[], int, int);

Student arr[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, e, c;
        cin >> m >> e >> c;
        arr[i].set(i + 1, m, e, c);
    }
    studentSort(arr, 0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        arr[i].print();
    }
    return 0;
}

bool lt(Student a, Student b) {
    if (a.math != b.math) {
        return a.math < b.math;
    }
    else {
        if (a.english != b.english) {
            return a.english < b.english;
        }
        else {
            if (a.chinese != b.chinese) {
                return a.chinese < b.chinese;
            }
            else {
                return a.id < b.id;
            }
        }
    }
}

void studentSort(Student arr[], int lo, int hi) {
    if(hi <= lo)
    {
        return;     //递归基
    }
    int first = lo, last = hi;
    Student key = arr[first];

    while(first < last)
    {
        while(first < last && lt(key, arr[last]))
        {
            --last;
        }
        arr[first] = arr[last];
        while(first < last && lt(arr[first], key))
        {
            ++first;
        }
        arr[last] = arr[first];
    }   // assert: first == last
    arr[first] = key;
    studentSort(arr, lo, first - 1);
    studentSort(arr, first + 1, hi);
}
