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
    size_t row_count;
    size_t col_count;
    T** values;
public:
    Matrix(const Matrix<T> &);
    Matrix(size_t, size_t);
    ~Matrix();

    T get(size_t, size_t);
    void set(size_t, size_t, T);

    template <typename C>
    friend std::ostream &operator<<(std::ostream &, const Matrix<C> &);
    template <typename C>
    friend std::istream &operator>>(std::istream &, Matrix<C> &);
    template <typename C>
    friend Matrix<C> operator+(Matrix<C> &, Matrix<C> &);
    template <typename C>
    friend Matrix<C> operator*(Matrix<C> &, Matrix<C> &);

    //Matrix<T> eye(size_t);
};

template <typename T>
Matrix<T>::Matrix(const Matrix &m) : row_count(m.row_count), col_count(m.col_count) {
    this->values = new T*[this->col_count];
    for (int i = 0; i < this->row_count; ++i) {
        this->values[i] = new T[this->col_count];
        std::memcpy(this->values[i], m.values[i], col_count);
    }
}

template <typename T>
Matrix<T>::Matrix(size_t row_count, size_t col_count): row_count(row_count), col_count(col_count) {
    this->values = new T*[this->col_count];
    for (int i = 0; i < this->row_count; ++i) {
        this->values[i] = new T[this->col_count];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < row_count; ++i) {
        delete []this->values[i];
    }
    delete []this->values;
}

template <typename T>
T Matrix<T>::get(size_t row, size_t col) {
    return this->values[row][col];
}

template <typename T>
void Matrix<T>::set(size_t row, size_t col, T value) {
    this->values[row][col] = value;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            out << matrix.values[row][col] << ' ';
        }
        out << '\n';
    }
    return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, Matrix<T> &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            in >> matrix.values[row][col];
        }
    }
    return in;
}

/*template <typename T>
Matrix<T> Matrix::eye(size_t count) {
    Matrix<T> result(count, count);
        for (int row = 0; row < count; ++row) {
            for (int col = 0; col < count; ++col) {
                result.values[row][col] = (col == row);
            }
        }
    return result;
}*/

template <typename T>
Matrix<T> operator+(Matrix<T> &m1, Matrix<T> &m2) {
    Matrix<T> result(m1.row_count, m1.col_count);
    for (int row = 0; row < m1.row_count; ++row) {
        for (int col = 0; col < m1.col_count; ++col) {
            result.values[row][col] = m1.values[row][col] + m2.values[row][col];
        }
    }
    return result;
}

template <typename T>
Matrix<T> operator*(Matrix<T> &m1, Matrix<T> &m2) {
    Matrix<T> result(m1.row_count, m1.col_count);
    for (int row = 0; row < m1.row_count; ++row) {
        for (int col = 0; col < m1.col_count; ++col) {
            result.values[row][col] = m1.values[row][col] + m2.values[row][col];
        }
    }
    return result;
}

#endif //INC_28_02_MATRIX_H