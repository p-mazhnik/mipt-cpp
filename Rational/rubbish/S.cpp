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

    Rational &operator=(char *);
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

using namespace std;

int main(int argc, char** argv) {
    int a;
    cin >> a;

    int p, q;
    cin >> p >> q;
    const Rational rc(p, q); // q != 0 is guaranteed by author of tests
    cout << rc.getNumerator() << ' ' << rc.getDenominator() << endl;

    Rational r1, r2;
    cin >> r1 >> r2;

    cout << r1 << endl;
    cout << r2 << endl;

    try {
        cout << 1/r1 << endl;
    } catch (const RationalDivisionByZero& ex) {
        cout << "Cannot get reciprocal of r1." << endl;
    }

    try {
        cout << rc/r2 << endl;
    } catch (const RationalDivisionByZero& ex) {
        cout << "Cannot divide by r2." << endl;
    }

    cout << (r1 < r2) << endl;
    cout << (r1 <= r2) << endl;
    cout << (r1 > r2) << endl;
    cout << (r1 >= r2) << endl;
    cout << (r1 == r2) << endl;
    cout << (r1 != r2) << endl;

    cout << (r1 < a) << endl;
    cout << (r1 <= a) << endl;
    cout << (r1 > a) << endl;
    cout << (r1 >= a) << endl;
    cout << (r1 == a) << endl;
    cout << (r1 != a) << endl;

    cout << (a < r2) << endl;
    cout << (a <= r2) << endl;
    cout << (a > r2) << endl;
    cout << (a >= r2) << endl;
    cout << (a == r2) << endl;
    cout << (a != r2) << endl;

    cout << rc + a << endl
         << a + rc << endl
         << -rc * r1 << endl
         << (+r1 - r2 * rc) * a << endl;

    cout << ++r1 << endl;
    cout << r1 << endl;
    cout << r1++ << endl;
    cout << r1 << endl;
    cout << --r1 << endl;
    cout << r1 << endl;
    cout << r1-- << endl;
    cout << r1 << endl;
    cout << ++++r1 << endl;
    cout << r1 << endl;

    cout << ((((r1 += r2) /= Rational(-5,3)) -= rc) *= a) << endl;
    cout << (r1 += r2 /= 3) << endl;
    cout << r1 << endl;
    cout << r2 << endl;
    return 0;
}

//
// Created by pavel on 26.03.2017.
//

Rational::Rational(int p, int q) : p(p), q(q) {
    this->reduce();
}

Rational::Rational(const Rational &that) : p(that.p), q(that.q) {}

void Rational::reduce() {
    if(this->q < 0){
        this->p *= -1;
        this->q *= -1;
    }
    int n = nod(*this);
    this->p /= n;
    this->q /= n;
}

int nod(const Rational &that) {
    int a = std::max(that.p, that.q);
    int b = std::min(that.p, that.q);
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    if(a < 0){
        a *= -1;
    }
    return a;
}

int Rational::getNumerator() const {
    return this->p;
}

int Rational::getDenominator() const {
    return this->q;
}

std::ostream &operator<<(std::ostream &out, const Rational &a) {
    out << a.p;
    if(a.q != 1 && a.p != 0){
        out << '/' << a.q;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Rational &a) {
    char string [50];
    in >> string;
    a = string;
    return in;
}

Rational Rational::operator+(const Rational &that) const {
    int p = this->p * that.q + that.p * this->q;
    int q = this->q * that.q;
    Rational result(p, q);
    return result;
}

Rational Rational::operator+(const int that) const {
    return (*this + Rational(that));
}

Rational operator+(const int a, const Rational &b) {
    return (Rational(a) + b);
}

Rational Rational::operator+() {
    return Rational(*this);
}

Rational Rational::operator-(const Rational &that) const {
    int p = this->p * that.q - that.p * this->q;
    int q = this->q * that.q;
    Rational result(p, q);
    return result;
}

Rational Rational::operator-(const int that) const {
    return (*this - Rational(that));
}

Rational operator-(const int a, const Rational &b) {
    return (Rational(a) - b);
}

Rational Rational::operator-() const {
    return Rational(this->p * (-1), this->q);
}

Rational Rational::operator*(const Rational &that) const {
    int p = this->p * that.p;
    int q = this->q * that.q;
    Rational result(p, q);
    return result;
}

Rational Rational::operator*(const int that) const {
    return (*this * Rational(that));
}

Rational operator*(const int a, const Rational &b) {
    return (Rational(a) * b);
}

Rational Rational::operator/(const Rational &that) const {
    if(that.p == 0){
        throw RationalDivisionByZero();
    }
    int p = this->p * that.q;
    int q = this->q * that.p;
    Rational result(p, q);
    return result;
}

Rational Rational::operator/(const int that) const {
    return (*this / Rational(that));
}

Rational operator/(const int a, const Rational &b) {
    return (Rational(a) / b);
}

Rational &Rational::operator=(char *string) {
    this->p = atoi(string);
    char *s1 = strchr(string, '/');
    if(s1 != NULL) {
        this->q = atoi(s1 + 1);
    }
    this->reduce();
    return *this;
}

Rational &Rational::operator=(const Rational &that) {
    this->p = that.p;
    this->q = that.q;
    return *this;
}

bool operator>(const Rational &a, const Rational &b) {
    return a.p * b.q > a.q * b.p;
}

bool operator==(const Rational &a, const Rational &b) {
    return (a.p * b.q == a.q * b.p);
}

bool operator!=(const Rational &a, const Rational &b) {
    return !(a == b);
}

bool operator>=(const Rational &a, const Rational &b) {
    return (a == b || a > b);
}

bool operator<=(const Rational &a, const Rational &b) {
    return !(a > b);
}

bool operator<(const Rational &a, const Rational &b) {
    return !(a >= b);
}

Rational &Rational::operator+=(const Rational &that) {
    *this = that + *this;
    return *this;
}

Rational &Rational::operator-=(const Rational &that) {
    *this = *this - that;
    return *this;
}

Rational &Rational::operator*=(const Rational &that) {
    *this = *this * that;
    return *this;
}

Rational &Rational::operator/=(const Rational &that) {
    *this = *this / that;
    return *this;
}

Rational &Rational::operator++() {
    *this += 1;
    return *this;
}

Rational Rational::operator++(int) {
    Rational old(*this);
    *this += 1;
    return old;
}
Rational &Rational::operator--() {
    *this -= 1;
    return *this;
}

Rational Rational::operator--(int) {
    Rational old(*this);
    *this -= 1;
    return old;
}