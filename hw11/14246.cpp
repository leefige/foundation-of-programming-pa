#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 333; i++) {
        for (int j = i + 1; j < 1000; j++) {
            for (int k = j + 1; i + j + k <= 1000; k++) {
                if (i * i + j * j == k * k) {
                    cout << i << " " << j << " " << k << "\n";
                }
            }
        }
    }
    return 0;
}