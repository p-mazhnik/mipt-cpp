//
// Created by pavel on 12.03.2017.
//

#ifndef MIPT_CPP_BIGINT_H
#define MIPT_CPP_BIGINT_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define DEFAULT_CAPACITY 100

class BigInt {
private:
    int *values;
    int length;

    void set_length(const int);
public:
   // BigInt(int length = DEFAULT_CAPACITY);
    BigInt(int value = 0);
    BigInt(const char *);
    BigInt(const BigInt &);
    ~BigInt();

    BigInt operator+(const BigInt &) const;
    //friend BigInt operator+(const char[], const BigInt &);
    BigInt operator-(const BigInt &) const;
    //friend BigInt operator-(const char[], const BigInt &);
    //BigInt &operator=(int);
    BigInt &operator=(const char *);
    BigInt &operator=(const BigInt &);
    BigInt operator*(const BigInt &) const;
    friend BigInt operator*(int, const BigInt &);

    void print() const;
    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, BigInt &);
};

#endif //MIPT_CPP_BIGINT_H
