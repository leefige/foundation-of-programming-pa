#include <iostream>
#include <cstdio>
using namespace std;

struct Complex {
    double x;
    double y;

    Complex(double a, double b) {
        this->x = a;
        this->y = b;
    }

    void print() {
        printf("%.2f+%.2fi", x, y);
    }
};

Complex add(Complex a, Complex b) {
    return Complex(a.x + b.x, a.y + b.y);
}

Complex sub(Complex a, Complex b) {
    return Complex(a.x - b.x, a.y - b.y);
}

Complex mul(Complex a, Complex b) {
    double resx = a.x * b.x - a.y * b.y;
    double resy = a.y * b.x + a.x * b.y;
    return Complex(resx, resy);
}

Complex div(Complex a, Complex b) {
    double resx = (a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y);
    double resy = (a.y * b.x - a.x * b.y) / (b.x * b.x + b.y * b.y);
    return Complex(resx, resy);
}

int main() {
    char op;
    double a, b, c, d;  // a+bj, c+dj
    cin >> op >> a >> b >> c >> d;
    Complex x(a, b);
    Complex y(c, d);
    Complex res(0, 0);

    switch(op) {
    case '+': 
        res = add(x, y);
        break;
    case '-': 
        res = sub(x, y);
        break;
    case '*': 
        res = mul(x, y);
        break;
    case '/':
        res = div(x, y);
        break;
    default:
        break;
    }
    res.print();
    return 0;
}