#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix get() {
    return Matrix(3, 4);
}

int main()
{
    Matrix a = {
        {1, 2, 1},
        {0, 1, 2}
    };

    Matrix b = {
        {1, 0},
        {0, 1},
        {1, 1}
    };

    Matrix c = {
        {3, 4, 5},
        {6, 7, 8}
    };

    cout << "A\n" << a << endl;
    cout << "B\n" << b << endl;
    cout << "C\n" << c << endl;
    cout << "A + C\n" << a + c << endl;
    cout << "A * B\n" << a * b << endl;

    // copy constructor in action
    Matrix d = b;
    cout << "D\n" << d << endl;

    // copy assignment in action
    d = a;
    cout << "D\n" << d << endl;

    // move constructor or RVO (copy elision) in action
    cout << get() << endl;
}
