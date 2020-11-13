#include "Matrix.h"
#include <algorithm> // swap
#include <stdexcept> // domain_error

Matrix::Matrix(int nrows, int ncols)
    : nrows {nrows}, ncols {ncols}
{
    elements = new double* [nrows];
    elements[0] = new double[nrows * ncols] {};
    for (int i = 1; i < nrows; i++) {
        elements[i] = elements[i - 1] + ncols;
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list)
    : Matrix(list.size(), (*list.begin()).size())
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

Matrix::Matrix(const Matrix& other)
    : Matrix(other.nrows, other.ncols)
{
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            elements[i][j] = other.elements[i][j];
}

Matrix::Matrix(Matrix&& other)
    : nrows {other.nrows}, ncols {other.ncols}, elements {other.elements}
{
    other.nrows = other.ncols = 0;
    other.elements = nullptr;
}

Matrix& Matrix::operator= (Matrix other)
{
    if (this != &other) {
        swap(*this, other);
    }

    return *this;
}

Matrix& Matrix::operator= (Matrix&& other)
{
    if (this != &other) {
        nrows = other.nrows;
        ncols = other.ncols;
        elements = other.elements;
        other.nrows = other.ncols = 0;
        other.elements = nullptr;
    }

    return *this;
}

Matrix operator+ (Matrix lhs, const Matrix& rhs)
{
    if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols()) {
        throw std::domain_error("Matrices of different sizes");
    }

    for (int i = 0; i < lhs.rows(); i++)
        for (int j = 0; j < lhs.cols(); j++)
            lhs[i][j] += rhs[i][j];

    return lhs;
}

Matrix operator- (Matrix lhs, const Matrix& rhs)
{
    if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols()) {
        throw std::domain_error("Matrices of different sizes");
    }

    for (int i = 0; i < lhs.rows(); i++)
        for (int j = 0; j < lhs.cols(); j++)
            lhs[i][j] -= rhs[i][j];

    return lhs;
}

Matrix operator* (const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.cols() != rhs.rows()) {
        throw std::domain_error("Matrices can't be multiplied (A.columns != B.rows)");
    }

    Matrix result(lhs.rows(), rhs.cols());

    for (int i = 0; i < lhs.rows(); i++)
        for (int j = 0; j < rhs.cols(); j++)
            for (int k = 0; k < lhs.cols(); k++)
                result[i][j] += lhs[i][k] * rhs[k][j];

    return result;
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix)
{
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.cols(); j++) {
            os << matrix[i][j] << ' ';
        }
        os << '\n';
    }

    return os;
}

void swap(Matrix& a, Matrix& b)
{
    std::swap(a.nrows, b.nrows);
    std::swap(a.ncols, b.ncols);
    std::swap(a.elements, b.elements);
}
