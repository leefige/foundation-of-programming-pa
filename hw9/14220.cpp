#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory.h>

using namespace std;

#define MAX 1001

int LCS[MAX][MAX];

char buf1[MAX];
char buf2[MAX];

int getLCS(int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (LCS[i][j] >= 0) {
        return LCS[i][j];
    }

    if (buf1[i - 1] == buf2[j - 1]) {
        LCS[i][j] = getLCS(i - 1, j - 1) + 1;
    } else {
        LCS[i][j] = max(getLCS(i, j - 1), getLCS(i - 1, j));
    }

    return LCS[i][j];
}

int main() {
    cin >> buf1 >> buf2;
    int len1 = strlen(buf1);
    int len2 = strlen(buf2);

    // init
    memset(LCS, -1, sizeof(int) * MAX * MAX);
    for (int i = 0; i <= len1; i++) {
        LCS[0][i] = 0;
    }
    for (int i = 0; i <= len2; i++) {
        LCS[i][0] = 0;
    }

    cout << getLCS(len1, len2);
}