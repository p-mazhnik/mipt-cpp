//
// Created by pavel on 26.03.2017.
//

#ifndef MIPT_CPP_RATIONAL_H
#define MIPT_CPP_RATIONAL_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <cstring>

class Rational {
private:
    int p;
    int q;
    void reduce();
    friend int nod(const Rational &);
public:
    Rational(int p = 1, int q = 1);
    Rational(const Rational &);

    int getNumerator() const;
    int getDenominator() const;

    Rational operator+(const Rational &) const;
    Rational operator+(const int) const;
    Rational operator+();
    friend Rational operator+(const int, const Rational &);

    Rational operator-(const Rational &) const;
    Rational operator-() const;
    Rational operator-(const int) const;
    friend Rational operator-(const int, const Rational &);

    Rational &operator++();
    Rational operator++(int);
    Rational &operator--();
    Rational operator--(int);

    Rational operator*(const Rational &) const;
    Rational operator*(const int) const;
    friend Rational operator*(const int, const Rational &);

    Rational operator/(const Rational &) const;
    Rational operator/(const int) const;
    friend Rational operator/(const int, const Rational &);
    
    Rational &operator=(const char *);
    Rational &operator=(const Rational &);

    friend std::ostream &operator<<(std::ostream &, const Rational &);
    friend std::istream &operator>>(std::istream &, Rational &);

    Rational &operator+=(const Rational &);
    Rational &operator-=(const Rational &);
    Rational &operator*=(const Rational &);
    Rational &operator/=(const Rational &);

    friend bool operator>(const Rational &, const Rational &);
    friend bool operator>=(const Rational &, const Rational &);
    friend bool operator<(const Rational &, const Rational &);
    friend bool operator<=(const Rational &, const Rational &);
    friend bool operator==(const Rational &, const Rational &);
    friend bool operator!=(const Rational &, const Rational &);
};

class RationalDivisionByZero : std::logic_error {
public:
    RationalDivisionByZero() : std::logic_error("Division by zero") {};
};

#endif //MIPT_CPP_RATIONAL_H
