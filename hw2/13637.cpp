#include <iostream>
#include <string.h>
#include <memory.h>
using namespace std;

const int MAX = 100;
int a[MAX], b[MAX];
char tmp[MAX];

void input(int a[], int& size) {
    cin >> tmp;
    size = strlen(tmp);
    for (int i = size - 1; i >= 0; i--) {
        a[size - i - 1] = tmp[i] - '0';
    }
    return;
}

int main() {
    memset(a, 0, MAX * sizeof(int));
    memset(b, 0, MAX * sizeof(int));
    int size_a, size_b;
    input(a, size_a);
    input(b, size_b);

    int carry = 0;
    int max_size = size_a > size_b ? size_a : size_b;

    for (int i = 0; i < max_size; i++) {
        int sum = a[i] + b[i] + carry;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        a[i] = sum;
    }

    if(carry == 1) {
        a[max_size++] = 1;
    }

    for (int i = max_size - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}