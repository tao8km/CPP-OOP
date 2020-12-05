#include <algorithm> // swap
#include <iostream>

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix()
{
    elements = new T* [Rows];
    elements[0] = new T[Rows * Cols] {};
    for (int i = 1; i < Rows; i++) {
        elements[i] = elements[i - 1] + Cols;
    }
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(std::initializer_list<std::initializer_list<T>> list)
    : Matrix()
{
    int i = 0, j = 0;

    for (const auto& row : list) {
        for (const auto& elem : row) {
            elements[i][j++] = elem;
        }
        i++;
        j = 0;
    }
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(const Matrix<T, Rows, Cols>& other)
    : Matrix()
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            elements[i][j] = other.elements[i][j];
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(Matrix<T, Rows, Cols>&& other)
    : elements {other.elements}
{
    std::cout << "Matrix(Matrix&&)\n";
    other.elements = nullptr;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator= (Matrix<T, Rows, Cols> other)
{
    if (this != &other) {
        swap(*this, other);
    }

    return *this;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator= (Matrix<T, Rows, Cols>&& other)
{
    std::cout << "operator= (Matrix&&)\n";
    if (this != &other) {
        elements = other.elements;
        other.elements = nullptr;
    }

    return *this;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> operator+ (Matrix<T, Rows, Cols> a, const Matrix<T, Rows, Cols>& b)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            a[i][j] += b[i][j];

    return a;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> operator- (Matrix<T, Rows, Cols> a, const Matrix<T, Rows, Cols>& b)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            a[i][j] -= b[i][j];

    return a;
}

template<typename T, int ARows, int AColsBRows, int BCols>
Matrix<T, ARows, BCols> operator* (const Matrix<T, ARows, AColsBRows>& a, const Matrix<T, AColsBRows, BCols>& b)
{
    Matrix<T, ARows, BCols> result;

    for (int i = 0; i < ARows; i++)
        for (int j = 0; j < BCols; j++)
            for (int k = 0; k < AColsBRows; k++)
                result[i][j] += a[i][k] * b[k][j];

    return result;
}

template<typename T, int Rows, int Cols>
std::ostream& operator<< (std::ostream& os, const Matrix<T, Rows, Cols>& matrix)
{
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            os << matrix[i][j] << ' ';
        }
        os << '\n';
    }

    return os;
}

template<typename T, int Rows, int Cols>
void swap(Matrix<T, Rows, Cols>& a, Matrix<T, Rows, Cols>& b)
{
    std::swap(a.elements, b.elements);
}
