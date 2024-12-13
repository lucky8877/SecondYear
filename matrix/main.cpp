#include "matrix.h"

int main() {
    Matrix<int> m(3);
    Matrix<int> l(3);
    m[0][0] = 2;
    m[0][1] = 3;
    m[0][2] = 5;
    m[1][0] = 4;
    m[1][1] = 6;
    m[1][2] = 8;
    m[2][0] = 9;
    m[2][1] = 8;
    m[2][2] = 7;
    m.Pow(2);
}