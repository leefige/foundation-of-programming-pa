#include <iostream>
using namespace std;

char** pattern;
char** rev;
char** neo;

bool turn90 (char** ptn, char** neo, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[j][N - 1 -i]) {
                return false;
            }
        }
    }
    return true;
}

bool turn180 (char** ptn, char** neo,  int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[N - 1 - i][N - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

bool turn270 (char** ptn, char** neo,  int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[N - 1 - j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool reverse (char** ptn, char** neo,  int N) {
    int end = N / 2 - 1;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i <= end; i++) {
            if (ptn[i][j] != neo[N - 1 - i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool combine (char** ptn, char** neo,  int N) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            rev[i][j] = ptn[N - 1 - i][j];
        }
    }
    if (turn90(rev, neo, N) || turn180(rev, neo, N) || turn270(rev, neo, N)) {
        return true;
    } else {
        return false;
    }
}

bool nothing (char** ptn, char** neo,  int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char** pattern = new char*[10];
    char** rev = new char*[10];
    char** neo = new char*[10];
    for (int i = 0; i < 10; i++) {
        pattern[i] = new char[10];
        rev[i] = new char[10];
        neo[i] = new char[10];
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pattern[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> neo[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << pattern[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << neo[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (turn90(pattern, neo, N)) {
        cout << 1;
    } 
    else if (turn180(pattern, neo, N)) {
        cout << 2;
    } 
    else if (turn270(pattern, neo, N)) {
        cout << 3;
    } 
    else if (reverse(pattern, neo, N)) {
        cout << 4;
    } 
    else if (combine(pattern, neo, N)) {
        cout << 5;
    } 
    else if (nothing(pattern, neo, N)) {
        cout << 6;
    } 
    else {
        cout << 7;
    }

    for (int i = 0; i < 10; i++) {
        delete[] pattern[i];
        delete[] rev[i];
        delete[] neo[i];
    }

    delete[] pattern;
    delete[] rev;
    delete[] neo;
    return 0;
}