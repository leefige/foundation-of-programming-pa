#include <iostream>
using namespace std;

class Mat {

    long long** mat;
    int n;

public:
     Mat(int n) {
        this->n = n;
        mat = new long long*[n * n];
    }

    Mat(long long arr[], int n) {
        this->n = n;
        mat = new long long*[n * n];
        for (int i = 0; i < n * n; i++) {
            mat[i] = &arr[i];
        }
    }

    ~Mat() {
        if (mat) {
            delete[] mat;
        }
    }

    int getSize() const {
        return n;
    }

    long long* get(int x, int y) const {
        return mat[n * x + y];
    }

    long long getNum(int x, int y) const {
        return *(mat[n * x + y]);
    }

    void set(int x, int y, long long* ptr) {
        mat[n * x + y] = ptr;
    }

    void genSub(const Mat& last, int x, int y) {
        int lastSize = last.getSize();
        int row = 0, col = 0;
        for (int i = 0; i < lastSize; i++) {
            if (i == x) {
                continue;
            }
            for (int j = 0; j < lastSize; j++) {
                if (j == y) {
                    continue;
                }
                set(row, col, last.get(i, j));
                col++;
            }
            row++;
            col = 0;
        }
    }

    void printMat() const {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << getNum(i, j) << " ";
            }
            cout <<endl;
        }
    }
};

long long powMinus(int n) {
    long long m = -1;
    for (int i = 0; i < n; i++) {
        m *= -1;
    }
    return m;
}

long long calc(const Mat& mat) {
    int n = mat.getSize();
    if (n == 1) {
        return mat.getNum(0, 0);
    }
    if (n == 2) {
        return mat.getNum(0, 0) * mat.getNum(1, 1) - mat.getNum(0, 1) * mat.getNum(1, 0);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        Mat sub(n - 1);
        sub.genSub(mat, 0, i);     // by row
        res += -1 * powMinus(i) * mat.getNum(0, i) * calc(sub);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    long long arr[n * n];
    for (int i = 0; i < n * n; i++) {
        cin >> arr[i];
    }
    Mat mat(arr, n);
    // mat.printMat();
    cout << calc(mat);
    return 0;
}