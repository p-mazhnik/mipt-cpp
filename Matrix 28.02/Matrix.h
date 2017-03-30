//
// Created by pavel on 28.02.2017. && 28.03.2017.
//

#ifndef INC_28_02_MATRIX_H
#define INC_28_02_MATRIX_H

#include <cstdlib>
#include <cstring>
#include <iostream>

template <typename T>

class Matrix {
private:
    int row_count;
    int col_count;
    T** array;
protected:

public:
    Matrix(const Matrix<T> &);
    Matrix(int, int);
    ~Matrix();

    T get(int, int);
    void set(int, int, T);

    template <typename C>
    friend std::ostream &operator<<(std::ostream &, const Matrix<C> &);
    template <typename C>
    friend std::istream &operator>>(std::istream &, Matrix<C> &);

    Matrix<T> &operator=(Matrix<T> &);

    template <typename C>
    friend Matrix<C> operator+(Matrix<C> &, Matrix<C> &);
    template <typename C>
    friend Matrix<C> operator+=(Matrix<C> &, Matrix<C> &);

    template <typename C>
    friend Matrix<C> operator-(Matrix<C> &, Matrix<C> &);
    template <typename C>
    friend Matrix<C> operator-=(Matrix<C> &, Matrix<C> &);

    Matrix<T> operator*(T) const;
    template <typename C>
    friend Matrix<C> operator*(C,  Matrix<C> &);
    template <typename C>
    friend Matrix<C> operator*(Matrix<C> &, Matrix<C> &);

    //Matrix<T> eye(int);
};

class MatrixAllocationError {};
class MatrixWrongSizeError {};
class MatrixIndexError {};
class MatrixIsDegenerateError {};

//
template <typename T>
Matrix<T>::Matrix(const Matrix &m) : row_count(m.row_count), col_count(m.col_count) {
    this->array = new T*[this->row_count];
    for (int i = 0; i < this->row_count; ++i) {
        this->array[i] = new T[this->col_count];
        std::memcpy(this->array[i], m.array[i], (size_t)col_count);
    }
}

template <typename T>
Matrix<T>::Matrix(int row_count, int col_count): row_count(row_count), col_count(col_count) {
    this->array = new T*[this->row_count];
    for (int i = 0; i < this->row_count; ++i) {
        this->array[i] = new T[this->col_count];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < row_count; ++i) {
        delete []this->array[i];
    }
    delete []this->array;
}

template <typename T>
T Matrix<T>::get(int row, int col) {
    return this->array[row][col];
}

template <typename T>
void Matrix<T>::set(int row, int col, T value) {
    this->array[row][col] = value;
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

/*template <typename T>
Matrix<T> Matrix::eye(int count) {
    Matrix<T> result(count, count);
        for (int row = 0; row < count; ++row) {
            for (int col = 0; col < count; ++col) {
                result.array[row][col] = (col == row);
            }
        }
    return result;
}*/

template <typename T>
Matrix<T> operator+(Matrix<T> &m1, Matrix<T> &m2) {
    if(m1.row_count != m2.row_count || m1.col_count != m2.col_count){
        throw MatrixWrongSizeError();
    }
    Matrix<T> result(m1.row_count, m1.col_count);
    for (int row = 0; row < m1.row_count; ++row) {
        for (int col = 0; col < m1.col_count; ++col) {
            result.array[row][col] = m1.array[row][col] + m2.array[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T> operator+=(Matrix<T> &m1, Matrix<T> &m2) {
    (m1 = m1 + m2);
    return m1;
}

template <typename T>
Matrix<T> operator*(Matrix<T> &m1, Matrix<T> &m2) {
    Matrix<T> result(m1.row_count, m1.col_count);
    for (int row = 0; row < m1.row_count; ++row) {
        for (int col = 0; col < m1.col_count; ++col) {
            result.array[row][col] = m1.array[row][col] + m2.array[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T a) const{
    Matrix<T> result(this->row_count, this->col_count);
    for (int row = 0; row < this->row_count; ++row) {
        for (int col = 0; col < this->col_count; ++col) {
            result.array[row][col] = this->array[row][col] * a;
        }
    }
    return result;
}

template<typename T>
Matrix<T> operator*(T a, Matrix<T> &m1) {
    Matrix<T> result(m1.row_count, m1.col_count);
    for (int row = 0; row < m1.row_count; ++row) {
        for (int col = 0; col < m1.col_count; ++col) {
            result.array[row][col] = m1.array[row][col] * a;
        }
    }
    return result;
}

template <typename T>
Matrix<T> operator-(Matrix<T> &m1, Matrix<T> &m2) {
    if(m1.row_count != m2.row_count || m1.col_count != m2.col_count){
        throw MatrixWrongSizeError();
    }
    Matrix<T> result(m1.row_count, m1.col_count);
    for (int row = 0; row < m1.row_count; ++row) {
        for (int col = 0; col < m1.col_count; ++col) {
            result.array[row][col] = m1.array[row][col] - m2.array[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T> operator-=(Matrix<T> &m1, Matrix<T> &m2) {
    (m1 = m1 - m2);
    return m1;
}

template <typename T>
Matrix<T> &Matrix::operator=(Matrix<T> &that) {

    return *this;
}

#endif //INC_28_02_MATRIX_H