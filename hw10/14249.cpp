#include <iostream>
using namespace std;

char ptn[10][10];
char rev[10][10];
char neo[10][10];

bool turn90 (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[j][N - 1 -i]) {
                return false;
            }
        }
    }
    return true;
}

bool turn180 ( int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[N - 1 - i][N - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

bool turn270 ( int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[N - 1 - j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool turn90_r (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rev[i][j] != neo[j][N - 1 -i]) {
                return false;
            }
        }
    }
    return true;
}

bool turn180_r ( int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rev[i][j] != neo[N - 1 - i][N - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

bool turn270_r ( int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rev[i][j] != neo[N - 1 - j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool reverse ( int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ptn[i][j] != neo[i][N - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

bool combine ( int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rev[i][j] = ptn[i][N - 1 - j];
        }
    }
    if (turn90_r(N) || turn180_r(N) || turn270_r(N)) {
        return true;
    } else {
        return false;
    }
}

bool nothing ( int N) {
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
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ptn[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> neo[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << ptn[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << neo[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (turn90(N)) {
        cout << 1;
    } 
    else if (turn180(N)) {
        cout << 2;
    } 
    else if (turn270(N)) {
        cout << 3;
    } 
    else if (reverse(N)) {
        cout << 4;
    } 
    else if (combine(N)) {
        cout << 5;
    } 
    else if (nothing(N)) {
        cout << 6;
    } 
    else {
        cout << 7;
    }

    return 0;
}