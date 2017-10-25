//
// Created by pavel on 28.02.2017. && 28.03.2017.
//

#ifndef INC_28_02_MATRIX_H
#define INC_28_02_MATRIX_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "Rational.h"

template <typename T>

class Matrix {
private:
    int row_count;
    int col_count;
    T** array;
protected:
    void assign(const Matrix<T> &);
    void set_matrix(const int, const int);
    void clear();
public:
    Matrix(const Matrix<T> &);
    Matrix(int row_count = 0, int col_count = 0);
    virtual ~Matrix();

    int getRowsNumber() const;
    int getColumnsNumber() const;
    T operator()(const int, const int) const;
    T &get(const int, const int);

    template <typename C>
    friend std::ostream &operator<<(std::ostream &, const Matrix<C> &);
    template <typename C>
    friend std::istream &operator>>(std::istream &, Matrix<C> &);

    Matrix<T> &operator=(const Matrix<T> &);

    Matrix<T> operator+(const Matrix<T> &) const;
    Matrix<T> operator-(const Matrix<T> &) const;
    Matrix<T> operator*(const Matrix<T> &) const;
    Matrix<T> operator*(const T &) const;
    template <typename C>
    friend Matrix<C> operator*(C,  const Matrix<C> &);
    Matrix<T> operator/(const T &) const;

    Matrix<T> &operator+=(const Matrix<T> &);
    Matrix<T> &operator-=(const Matrix<T> &);
    Matrix<T> &operator*=(const Matrix<T> &);
    Matrix<T> &operator*=(const T);
    Matrix<T> &operator/=(const T);

    Matrix<T> getTransposed() const;
    Matrix<T> &transpose();
};

template <typename T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix(const int);
    SquareMatrix(const Matrix<T> &);
    int getSize() const;

    SquareMatrix<T> &operator=(const SquareMatrix<T> &);

    SquareMatrix<T> operator+(const SquareMatrix<T> &) const;
    SquareMatrix<T> operator-(const SquareMatrix<T> &) const;
    SquareMatrix<T> operator*(const SquareMatrix<T> &) const;
    SquareMatrix<T> operator*(const T &) const;
    template <typename C>
    friend SquareMatrix<C> operator*(C,  const SquareMatrix<C> &);
    SquareMatrix<T> operator/(const T &) const;

    SquareMatrix<T> &operator+=(const SquareMatrix<T> &);
    SquareMatrix<T> &operator-=(const SquareMatrix<T> &);
    SquareMatrix<T> &operator*=(const SquareMatrix<T> &);
    SquareMatrix<T> &operator*=(const T &);
    SquareMatrix<T> &operator/=(const T &);

    SquareMatrix<T> getTransposed() const;
    SquareMatrix<T> &transpose();
    SquareMatrix<T> getInverse() const;
    SquareMatrix<T>& invert();

    SquareMatrix<T> minor(const int, const int) const;

    T getDeterminant() const;
    T getTrace() const;
};

class MatrixAllocationError : std::logic_error{
public:
    MatrixAllocationError() : std::logic_error("AllocationError") {};
};
class MatrixWrongSizeError : std::logic_error{
public:
    MatrixWrongSizeError() : std::logic_error("WrongSizeError") {};
};
class MatrixIndexError : std::logic_error{
public:
    MatrixIndexError() : std::logic_error("IndexError") {};
};
class MatrixIsDegenerateError : std::logic_error{
public:
    MatrixIsDegenerateError() : std::logic_error("IsDegenerateError") {};
};

//
template <typename T>
Matrix<T>::Matrix(const Matrix &m){
    this->assign(m);
}

template <typename T>
Matrix<T>::Matrix(int row, int col) {
    this->set_matrix(row, col);
}

template <typename T>
Matrix<T>::~Matrix() {
    this->clear();
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            out << matrix.array[row][col] << ' ';
        }
        out << '\n';
    }
    return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, Matrix<T> &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            in >> matrix.array[row][col];
        }
    }
    return in;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &that) {
    if(this == &that){
        return *this;
    }
    this->clear();
    this->assign(that);
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m2) const{
    if(this->row_count != m2.row_count || this->col_count != m2.col_count){
        throw MatrixWrongSizeError();
    }
    Matrix<T> result(this->row_count, this->col_count);
    for (int row = 0; row < this->row_count; ++row) {
        for (int col = 0; col < this->col_count; ++col) {
            result.array[row][col] = this->array[row][col] + m2.array[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &m2) {
    *this = *this + m2;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m2) const {
    if(this->col_count != m2.row_count){
        throw MatrixWrongSizeError();
    }
    Matrix<T> result(this->row_count, m2.col_count);
    for (int row = 0; row < this->row_count; ++row) {
        for (int col = 0; col < m2.col_count; ++col) {
            result.array[row][col] = T(0);
            for (int i = 0; i < this->col_count; i++) {
                result.array[row][col] += this->array[row][i] * m2.array[i][col];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &a) const{
    Matrix<T> result(this->row_count, this->col_count);
    for (int row = 0; row < this->row_count; ++row) {
        for (int col = 0; col < this->col_count; ++col) {
            result.array[row][col] = this->array[row][col] * a;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &a) const {
    Matrix<T> result(this->row_count, this->col_count);
    for (int row = 0; row < this->row_count; ++row) {
        for (int col = 0; col < this->col_count; ++col) {
            result.array[row][col] = this->array[row][col] / a;
        }
    }
    return result;
}

template<typename T>
Matrix<T> operator*(T a, const Matrix<T> &m1) {
    return (m1 * a);
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &m2) const {
    if(this->row_count != m2.row_count || this->col_count != m2.col_count){
        throw MatrixWrongSizeError();
    }
    Matrix<T> result(this->row_count, this->col_count);
    for (int row = 0; row < this->row_count; ++row) {
        for (int col = 0; col < this->col_count; ++col) {
            result.array[row][col] = this->array[row][col] - m2.array[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &m2) {
    (*this = *this - m2);
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &m2) {
    *this = *this * m2;
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T a) {
    *this = (*this * a);
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T a) {
    *this = (*this / a);
    return *this;
}



template <typename T>
int Matrix<T>::getRowsNumber() const {
    return this->row_count;
}

template <typename T>
int Matrix<T>::getColumnsNumber() const {
    return this->col_count;
}

template <typename T>
Matrix<T> Matrix<T>::getTransposed() const {
    Matrix<T> result(this->col_count, this->row_count);
    for(int row = 0; row < this->row_count; ++row){
        for(int col = 0; col < this->col_count; ++col){
            result.array[col][row] = this->array[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::transpose() {
    *this = this->getTransposed();
    return *this;
}

template <typename T>
void Matrix<T>::assign(const Matrix<T> &that) {
    this->row_count = that.row_count;
    this->col_count = that.col_count;
    this->array = new T*[this->row_count];
    for (int i = 0; i < this->row_count; ++i) {
        this->array[i] = new T[this->col_count];
        for (int j = 0; j < this->col_count; ++j)
            this->array[i][j] = that.array[i][j];
    }
}

template <typename T>
T Matrix<T>::operator()(const int row, const int col) const {
    if(row >= this->row_count || col >= this->col_count){
        throw MatrixIndexError();
    }
    return this->array[row][col];
}

template <typename T>
void Matrix<T>::set_matrix(const int row, const int col) {
    this->row_count = row;
    this->col_count = col;
    this->array = new T*[this->row_count];
    for (int i = 0; i < this->row_count; ++i) {
        this->array[i] = new T[this->col_count];
    }
}

template <typename T>
void Matrix<T>::clear() {
    for (int i = 0; i < this->row_count; ++i) {
        delete []this->array[i];
    }
    delete []this->array;
}

template <typename T>
T &Matrix<T>::get(const int row, const int col) {
    if(row >= this->row_count || col >= this->col_count){
        throw MatrixIndexError();
    }
    return this->array[row][col];
}

//--------SquareMatrix--------\\

template <typename T>
SquareMatrix<T>::SquareMatrix(const int n) {
    this->set_matrix(n, n);
}

template <typename T>
int SquareMatrix<T>::getSize() const {
    return this->getRowsNumber();
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator/(const T &a) const {
    return Matrix<T>::operator/(a);
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix<T> &that) const{
    return Matrix<T>::operator+(that);
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator-(const SquareMatrix<T> &that) const{
    return Matrix<T>::operator-(that);
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const SquareMatrix<T> &that) const{
    return Matrix<T>::operator*(that);
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const T &a) const{
    return Matrix<T>::operator*(a);
}

template <typename T>
SquareMatrix<T> operator*(T a, const SquareMatrix<T> &that){
    return that * a;
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::operator-=(const SquareMatrix<T> &that) {
    *this = *this - that;
    return *this;
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::operator+=(const SquareMatrix<T> &that) {
    *this = *this + that;
    return *this;
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::operator*=(const T &a) {
    *this = *this * a;
    return *this;
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::operator*=(const SquareMatrix<T> &that) {
    *this = *this * that;
    return *this;
}

template <typename T>
SquareMatrix<T>::SquareMatrix(const Matrix<T> &that){
    this->assign(that);
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::operator/=(const T &a) {
    *this = *this / a;
    return *this;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::getTransposed() const {
    return Matrix<T>::getTransposed();
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::transpose() {
    *this = this->getTransposed();
    return *this;
}

template <typename T>
SquareMatrix<T> &SquareMatrix<T>::operator=(const SquareMatrix<T> &that) {
    if(this == &that){
        return *this;
    }
    this->clear();
    this->assign(that);
    return *this;
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::invert(){
    *this = this->getInverse();
    return *this;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::getInverse() const {
    T det = this->getDeterminant();
    if (det == T(0)){
        throw MatrixIsDegenerateError();
    }
    SquareMatrix<T> result(this->getSize());
    for(int row = 0; row < this->getSize(); ++row){
        for(int col = 0; col < this->getSize(); ++col){
            result.get(row, col) = this->minor(row, col).getDeterminant() / det;
            if((row + col) % 2){
                result.get(row, col) *= -1;
            }
        }
    }
    result.transpose();
    return result;
}

template <typename T>
T SquareMatrix<T>::getDeterminant() const {
    T det = 1;
    SquareMatrix<T> temp = *this;
    for(int col = 0; col < this->getSize(); ++col){
        int row = col;
        for(; row < this->getSize() && temp(row, col) == 0; ++row){}
        if(row == this->getSize()){
            return 0;
        }
        if(row != col){
            for (int i = 0; i < this->getSize(); ++i){
                std::swap(temp.get(row, i), temp.get(col, i));
            }
            det *= -1;
        }
        det *= temp(col, col);
        for(int j = col + 1; j < this->getSize(); ++j){
            T k = temp(j, col) / temp(col, col);
            for(int i = col; i < this->getSize(); ++i){
                temp.get(j, i) -= temp(col, i) * k;
            }
        }
    }
    return det;
}

template <typename T>
T SquareMatrix<T>::getTrace() const {
    T sum = T(0);
    for(int i = 0; i < this->getRowsNumber(); ++i){
        sum += this->operator()(i, i);
    }
    return sum;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::minor(const int p, const int q) const {
    SquareMatrix<T> result(getSize() - 1);
    for (int row = 0; row < this->getSize(); ++row) {
        for (int col = 0; col < this->getSize(); ++col) {
            if (row != p && col != q) {
                int i = row;
                int j = col;
                if (row > p) {
                    i = row - 1;
                }
                if (col > q) {
                    j = col - 1;
                }
                result.get(i, j) = this->operator()(row, col);
            }
        }
    }
    return result;
}

#endif //INC_28_02_MATRIX_H