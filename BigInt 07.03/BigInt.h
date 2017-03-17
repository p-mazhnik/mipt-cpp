//
// Created by pavel on 12.03.2017.
//

#ifndef MIPT_CPP_BIGINT_H
#define MIPT_CPP_BIGINT_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define DEFAULT_CAPACITY 100

typedef int number_size;

class BigInt {
private:
    int *values;
    int length;
    int sign = 1;

    void set_length(const int);
    BigInt abs_sum(const BigInt &) const;
    BigInt abs_sub(const BigInt &) const;
public:
    BigInt(number_size value = 0);
    BigInt(const char *);
    BigInt(const BigInt &);
    ~BigInt();

    bool operator>(const BigInt &) const;
    bool operator==(const BigInt &) const;
    friend const BigInt &abs_max(const BigInt &, const BigInt &);
    friend const BigInt &abs_min(const BigInt &, const BigInt &);

    BigInt operator+(const BigInt &) const;
    BigInt operator-(const BigInt &) const;
    BigInt operator-(); //унарный минус

    BigInt &operator=(const number_size);
    BigInt &operator=(const char *);
    BigInt &operator=(const BigInt &);

    BigInt operator*(const BigInt &) const;
    friend BigInt operator*(number_size, const BigInt &);

    void print() const;
    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, BigInt &);
};

#endif //MIPT_CPP_BIGINT_H
