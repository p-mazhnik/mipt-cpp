//
// Created by pavel on 26.03.2017.
//

#include "Vector.h"

Point::Point(const double x, const double y) : x(x), y(y) {}

Point::Point(const Point &that) : x(that.x), y(that.y) {}

double Point::get_x() const{
    return x;
}
double Point::get_y() const{
    return y;
}

std::ostream &operator<<(std::ostream &out, const Point &that) {
    out << that.x << ' ' << that.y;
    return out;
}

std::istream &operator>>(std::istream &in, Point &that) {
    in >> that.x >> that.y;
    return in;
}

Point &Point::operator=(const Point &that){
    this->x = that.x;
    this->y = that.y;
    return *this;
}

Vector::Vector(const Point &p1, const Point &p2) : x(p2.get_x() - p1.get_x()), y(p2.get_y() - p1.get_y()) {}

Vector::Vector(const double x, const double y) : x(x), y(y) {}

Vector::Vector(const Vector &that) : x(that.x), y(that.y) {}

Vector &Vector::operator=(const Vector &that) {
    this->x = that.x;
    this->y = that.y;
    return *this;
}

Vector Vector::operator+(const Vector &that) const {
    Vector result(this->x + that.x, this->y + that.y);
    return result;
}

Vector Vector::operator-(const Vector &that) const {
    Vector result(this->x - that.x, this->y - that.y);
    return result;
}

double Vector::operator*(const Vector &that) const {
    return (this->x * that.x + this->y * that.y);
}

std::ostream &operator<<(std::ostream &out, const Vector &that) {
    out << that.x << ' ' << that.y;
    return out;
}

std::istream &operator>>(std::istream &in, Vector &that) {
    Point p1, p2;
    in >> p1 >> p2;
    that = Vector(p1, p2);
    return in;
}

double abs(const Vector &that) {
    return sqrt(fabs(that.x * that.x + that.y * that.y));
}

double vector_mult(const Vector &a, const Vector &b) {
    return (a.x * b.y - a.y * b.x);
}

double triangle_square(const Vector &a, const Vector &b) {
    return fabs(vector_mult(a, b) / 2);
}
