//
// Created by pavel on 26.03.2017.
//

#include <cstring>
#include "Rational.h"

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

Rational &Rational::operator=(const char *string) {
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

/*bool operator>(const Rational &a, const int &b) {
    return a > Rational(b);
}

bool operator>(const int &a, const Rational &b) {
    return Rational(a) > b;
}*/

bool operator==(const Rational &a, const Rational &b) {
    return (a.p * b.q == a.q * b.p);
}

/*bool operator==(const Rational &a, const int &b) {
    return a == Rational(b);
}

bool operator==(const int &a, const Rational &b) {
    return Rational(a) == b;
}*/

bool operator!=(const Rational &a, const Rational &b) {
    return !(a == b);
}

/*bool operator!=(const Rational &a, const int &b) {
    return !(a == b);
}

bool operator!=(const int &a, const Rational &b) {
    return !(a == b);
}*/

bool operator>=(const Rational &a, const Rational &b) {
    return (a == b || a > b);
}

/*bool operator>=(const Rational &a, const int &b) {
    return (a == b || a > b);
}

bool operator>=(const int &a, const Rational &b) {
    return (a == b || a > b);
}*/

bool operator<=(const Rational &a, const Rational &b) {
    return !(a > b);
}

/*bool operator<=(const Rational &a, const int &b) {
    return !(a > b);
}

bool operator<=const int &a, const Rational &b) {
    return !(a > b);
}*/

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