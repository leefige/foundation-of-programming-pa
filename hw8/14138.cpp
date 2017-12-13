#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    char buf[256];

    scanf("%s", &buf);
    int len = strlen(buf);
    int end = len / 2;
    int s_len = len % 2 == 0 ? len : len - 1;
    for (int i = 1; i < end; i = i + 2) {
        char tp = buf[i];
        buf[i] = buf[s_len - i];
        buf[s_len - i] = tp;
    }
    cout << buf;
    return 0;
}