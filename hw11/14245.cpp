#include <iostream>
using namespace std;

int mat[3][3];

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }
    int sum = mat[0][0] + mat[0][1] + mat[0][2];
    bool right = true;
    // line
    if (mat[1][0] + mat[1][1] + mat[1][2] != sum || 
        mat[2][0] + mat[2][1] + mat[2][2] != sum) {
        cout << 0;
        return 0;
    }
    // vert
    if (mat[0][0] + mat[1][0] + mat[2][0] != sum || 
        mat[0][1] + mat[1][1] + mat[2][1] != sum ||
        mat[0][2] + mat[1][2] + mat[2][2] != sum) {
        cout << 0;
        return 0;
    }
    // xx
    if (mat[0][0] + mat[1][1] + mat[2][2] != sum || 
        mat[0][2] + mat[1][1] + mat[2][0] != sum) {
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}