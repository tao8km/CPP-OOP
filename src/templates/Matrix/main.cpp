#include <iostream>
#include "Matrix.h"
using namespace std;

template<typename T, int R, int C>
Matrix<T, R, C> get() {
    return Matrix<T, R, C>();
}

int main()
{
    Matrix<int, 2, 3> a = {
        {1, 2, 1},
        {0, 1, 2}
    };

    Matrix<int, 3, 2> b = {
        {1, 0},
        {0, 1},
        {1, 1}
    };

    Matrix<int, 2, 3> c = {
        {3, 4, 5},
        {6, 7, 8}
    };

    cout << "A\n" << a << endl;
    cout << "B\n" << b << endl;
    cout << "C\n" << c << endl;
    cout << "A + C\n" << a + c << endl;
    cout << "A * B\n" << a * b << endl;

    cout << "copy constructor in action:\n";
    Matrix d = c;
    cout << "D\n" << d << endl;

    cout <<  "copy assignment in action:\n";
    d = a;
    cout << "D\n" << d << endl;

    cout << "move constructor or RVO (copy elision) in action:\n";
    cout << get<int, 3, 4>() << endl;
}
