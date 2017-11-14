#include <iostream>
using namespace std;

int mater[4];
int dish[5];

bool canDo(int no) {
    switch(no) {
    case 0:
        return mater[0] >= 2 && mater[1] >= 1 && mater[3] >= 2;
    case 1:
        return mater[0] >= 1 && mater[1] >= 1 && mater[2] >= 1 && mater[3] >= 1;
    case 2:
        return mater[2] >= 2 && mater[3] >= 1;
    case 3:
        return mater[1] >= 3;
    case 4:
        return mater[0] >= 1 && mater[3] >= 1;
    default:
        return false;
    }
}

void doDish(int no) {
    switch(no) {
    case 0:
        mater[0] -= 2;
        mater[1] -= 1;
        mater[3] -= 2;
        break;
    case 1:
        mater[0] -= 1;
        mater[1] -= 1;
        mater[2] -= 1;
        mater[3] -= 1;
        break;
    case 2:
        mater[2] -= 2;
        mater[3] -= 1;
        break;
    case 3:
        mater[1] -= 3;
        break;
    case 4:
        mater[0] -= 1;
        mater[3] -= 1;
        break;
    default:
        break;
    }
}

void plan() {
    for (int i = 0; i < 5; i++) {
        while (canDo(i)) {
            doDish(i);
            dish[i]++;
        }
    }
    return;
}

int main() {
    cin >> mater[0] >> mater[1] >> mater[2] >> mater[3];
    plan();
    for (int i = 0; i < 5; i++) {
        cout << dish[i] << endl;
    }
    return 0;
}