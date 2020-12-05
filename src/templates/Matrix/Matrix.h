#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <initializer_list>


template<typename T, int Rows, int Cols>
class Matrix
{
    T** elements = nullptr;
public:
    Matrix();
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    ~Matrix() {
        if (elements) {
            delete[] elements[0];
            delete[] elements;
        }
    }

    Matrix& operator= (Matrix other);
    Matrix& operator= (Matrix&& other);

    T* operator[](int row) { return elements[row]; }
    const T* operator[](int row) const { return elements[row]; }

    int rows() const { return Rows; }
    int cols() const { return Cols; }

    template<typename K, int KRows, int KCols>
    friend void swap(Matrix<K, KRows, KCols>& a, Matrix<K, KRows, KCols>& b);
};

#include "Matrix_impl.h"

#endif /* MATRIX_H_ */
