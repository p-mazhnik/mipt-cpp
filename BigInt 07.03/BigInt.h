//
// Created by pavel on 12.03.2017.
//

#ifndef MIPT_CPP_BIGINT_H
#define MIPT_CPP_BIGINT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdexcept>

#define BASE 3
#define MAX_VALUE 1000
#define LIM_LENGTH ((20000 / BASE) + 1)

class BigInt {
private:
    int *values;
    int length;
    int sign;

    void set_length(const int);
    BigInt abs_sum(const BigInt &) const;
    BigInt abs_sub(const BigInt &) const;
    friend BigInt set_zero(int, int);
public:
    BigInt(const long long value = 0);
    BigInt(const char *);
    BigInt(const BigInt &);
    ~BigInt();

    bool operator>(const BigInt &) const;
    bool operator==(const BigInt &) const;
    friend bool operator!=(const BigInt &, const BigInt &);
    bool operator>=(const BigInt &) const;
    friend const BigInt &abs_max(const BigInt &, const BigInt &);
    friend const BigInt &abs_min(const BigInt &, const BigInt &);

    BigInt &operator=(const long long);
    BigInt &operator=(const char *);
    BigInt &operator=(const BigInt &);

    BigInt operator+(const BigInt &) const;
    BigInt operator+(const long long) const;
    friend BigInt operator+(const long long, const BigInt &);

    BigInt operator-(const BigInt &) const;
    BigInt operator-(); //унарный минус
    BigInt operator-(const long long) const;
    friend BigInt operator-(const long long, const BigInt &);

    BigInt operator*(const BigInt &) const;
    BigInt operator*(const long long) const;
    friend BigInt operator*(const long long, const BigInt &);

    BigInt operator/(const BigInt &) const;
    BigInt operator/(const long long) const;
    friend BigInt operator/(const long long, const BigInt &);

    BigInt operator%(const BigInt &) const;

    friend BigInt nod(const BigInt &, const BigInt &);
    friend BigInt sqrt(const BigInt &);

    BigInt &operator+=(const BigInt &);
    BigInt &operator+=(const long long);
    BigInt &operator-=(const BigInt &);
    BigInt &operator-=(const long long);
    BigInt &operator*=(const BigInt &);
    BigInt &operator*=(const long long);
    BigInt &operator/=(const BigInt &);
    BigInt &operator/=(const long long);

    BigInt &operator++();
    BigInt operator++(int);
    BigInt &operator--();
    BigInt operator--(int);

    void print() const;
    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, BigInt &);

};

class BigIntegerDivisionByZero : std::logic_error {
public:
    BigIntegerDivisionByZero() : std::logic_error("Division by zero") {};
};

class BigIntegerOverflow : std::length_error {
public:
    BigIntegerOverflow() : std::length_error("Overflow") {};
};

#endif //MIPT_CPP_BIGINT_H
