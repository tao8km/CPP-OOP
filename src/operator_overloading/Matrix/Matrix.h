#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <initializer_list>


class Matrix
{
    int nrows = 0;
    int ncols = 0;
    double** elements = nullptr;
public:
    Matrix(int nrows, int ncols);
    Matrix(std::initializer_list<std::initializer_list<double>> list);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    ~Matrix() {
        if (elements)
            delete[] elements[0];
        delete[] elements;
    }

    Matrix& operator= (Matrix other);
    Matrix& operator= (Matrix&& other);

    double* operator[](int row) { return elements[row]; }
    const double* operator[](int row) const { return elements[row]; }

    int rows() const { return nrows; }
    int cols() const { return ncols; }

    friend void swap(Matrix& a, Matrix& b);
};

Matrix operator+ (Matrix lhs, const Matrix& rhs); // lhs - left hand size, rhs - right hand side
Matrix operator- (Matrix lhs, const Matrix& rhs);
Matrix operator* (const Matrix& lhs, const Matrix& rhs);

std::ostream& operator<< (std::ostream& os, const Matrix& matrix);


#endif /* MATRIX_H_ */
