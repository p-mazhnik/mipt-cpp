//
// Created by pavel on 28.02.2017.
//

#ifndef INC_28_02_MATRIX_H
#define INC_28_02_MATRIX_H

#include <cstdlib>
#include <cstring>
#include <iostream>

typedef int matrix_cell;

class Matrix {
private:
    size_t row_count;
    size_t col_count;
    matrix_cell** values;
public:
    Matrix(const Matrix &);
    Matrix(size_t, size_t);
    ~Matrix();

    matrix_cell get(size_t, size_t);
    void set(size_t, size_t, matrix_cell);

    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    friend std::istream &operator>>(std::istream &, const Matrix &);
    friend Matrix operator+(Matrix &, Matrix &);
    friend Matrix operator*(Matrix &, Matrix &);

    Matrix eye(size_t);
};


#endif //INC_28_02_MATRIX_H
