#include <iostream>
#include <cstring>

using namespace std;

void toBig(char buf[]) {
    int len = strlen(buf);
    char diff = 'a' - 'A';
    for (int i = 0; i < len; i++) {
        if (buf[i] >= 'a' && buf[i] <= 'z') {
            buf[i] -= diff;
        }
    }
    cout << buf;
}

void toSmall(char buf[]) {
    int len = strlen(buf);
    char diff = 'a' - 'A';
    for (int i = 0; i < len; i++) {
        if (buf[i] >= 'A' && buf[i] <= 'Z') {
            buf[i] += diff;
        }
    }
    cout << buf;
}

void reverse(char buf[]) {
    int len = strlen(buf);
    char diff = 'a' - 'A';
    for (int i = len - 1; i >= 0; i--) {
        cout << buf[i];
    }
}

void exchange(char buf[]) {
    int len = strlen(buf);
    char diff = 'a' - 'A';
    for (int i = 0; i < len; i++) {
        if (buf[i] >= 'A' && buf[i] <= 'Z') {
            buf[i] += diff;
        } else if (buf[i] >= 'a' && buf[i] <= 'z') {
            buf[i] -= diff;
        }
    }
    cout << buf;
}

void attr(char buf[]) {
    int len = strlen(buf);
    char diff = 'a' - 'A';
    for (int i = 0; i < len; i++) {
        if (buf[i] >= 'A' && buf[i] <= 'Z') {
            buf[i] += diff;
        }
    }
    char out[205];
    bool link = false;  // whether continued letters
    int i = 0, ptr = 0;
    for (; i < len; i++) {
        if (link) {
            if (!(buf[i + 1] - buf[i] == 1)) {
                link = false;
            } else {
                continue;
            }
        }
        out[ptr++] = buf[i];
        if (buf[i + 2] - buf[i] == 2 && buf[i + 1] - buf[i] == 1) {
            link = true;
            out[ptr++] = '-';
        } else {
            link = false;
        }
    }
    out[ptr] = '\0';
    cout << out;
}

int main() {
    int i;
    char buf[205];
    cin >> i >> buf;

    switch (i) {
        case 1:
            toBig(buf);
            break;
        case 2:
            toSmall(buf);
            break;
        case 3:
            reverse(buf);
            break;
        case 4:
            exchange(buf);
            break;
        case 5:
            attr(buf);
            break;
        default:
            break;
    }
    return 0;
}