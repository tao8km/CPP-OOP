#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <initializer_list>


template<typename T>
class Matrix
{
    int nrows = 0;
    int ncols = 0;
    T** elements = nullptr;
public:
    Matrix(int nrows, int ncols);
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    ~Matrix() {
        if (elements)
            delete[] elements[0];
        delete[] elements;
    }

    Matrix& operator= (Matrix other);
    Matrix& operator= (Matrix&& other);

    T* operator[](int row) { return elements[row]; }
    const T* operator[](int row) const { return elements[row]; }

    int rows() const { return nrows; }
    int cols() const { return ncols; }

    template<typename K>
    friend void swap(Matrix<K>& a, Matrix<K>& b);
};

#include "Matrix.impl"

#endif /* MATRIX_H_ */
