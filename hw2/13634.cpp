#include <iostream>
using namespace std;

#define MAXLEN 10000

int main() {
    char input[MAXLEN];
    cin >> input;
    const char start = 'A';
    const char end = 'z';
    int i = 0;
    while (input[i] != 0) {
        if (input[i] >= 'A' && input[i] < 'Z') {
            input[i] += 1;
        }
        else if (input[i] == 'Z') {
            input[i] = 'a';
        }
        else if (input[i] >= 'a' && input[i] < 'z') {
            input[i] += 1;
        }
        else if (input[i] == 'z') {
            input[i] = 'A';
        }
        i++;
    }
    cout << input;
    return 0;
}