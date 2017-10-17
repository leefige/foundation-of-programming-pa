#include <iostream>
#include <memory.h>
using namespace std;

const int MAXLEN = 10000;
const int MAXMEM = 10000;
int mem[MAXMEM];
int input[MAXLEN];
int cap = MAXMEM;
int head = 0;
int size = 0;

void translate(const int& word, int& lookup);

int main() {
    int N;
    cin >> cap >> N;
    int lookup = 0;
    for (int i = 0; i < N; i++) {
        int word;
        cin >> word;
        translate(word, lookup);
    }
    cout << lookup;
    return 0;
}

void translate(const int& word, int& lookup) {
    bool find = false;
    for (int i = 0; i < size; i++) {
        if (mem[i] == word) {
            find = true;
            break;
        }
    }
    if (find) {
        return;
    }

    // not find
    
    lookup++;
    if (size < cap) {
        size++;
        mem[head++] = word;
    }
    else {
        if (head < size) {
            mem[head++] = word;
        }
        else {
            head = 0;
            mem[head++] = word;
        }
    }
    return;
}