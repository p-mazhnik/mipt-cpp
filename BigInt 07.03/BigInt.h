//
// Created by pavel on 12.03.2017.
//

#ifndef MIPT_CPP_BIGINT_H
#define MIPT_CPP_BIGINT_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define DEFAULT_CAPACITY 10

class BigInt {
private:
    int *values;
    size_t length;
public:
    BigInt(size_t length = DEFAULT_CAPACITY);
    BigInt(const char *);
    BigInt(const BigInt &);
    ~BigInt();

    BigInt operator+(const BigInt &) const;
    friend BigInt operator+(const char[], const BigInt &);
    BigInt operator-(const BigInt &) const;
    friend BigInt operator-(const char[], const BigInt &);
    BigInt& operator=(const char *);
    BigInt operator*(const BigInt &) const;
    friend BigInt operator*(int, const BigInt &);

    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, const BigInt &);
};

#endif //MIPT_CPP_BIGINT_H
