//
// Created by pavel on 26.03.2017.
//

#ifndef MIPT_CPP_VECTOR_H
#define MIPT_CPP_VECTOR_H

#include <iostream>
#include <cstdlib>
#include <cmath>

class Geometry{
public:
    virtual Geometry &shift(const Vector &) = 0;
};

class Point : public Geometry{
private:
    double x;
    double y;
public:
    Point(const double x = 0, const double y = 0);
    Point(const Point &);

    Point &operator=(const Point &);

    double get_x() const;
    double get_y() const;

    friend std::ostream &operator<<(std::ostream &, const Point &);
    friend std::istream &operator>>(std::istream &, Point &);
};

class Vector {
private:
    double x;
    double y;
public:
    Vector(const Point &p1, const Point &p2);
    Vector(const double x = 0, const double y = 0);
    Vector(const Vector &);

    Vector &operator=(const Vector &);
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;

    double operator*(const Vector &) const; //скалярное произведение
    //Vector operator*(const double) const;
    friend double vector_mult(const Vector &, const Vector &);
    friend double triangle_square(const Vector &, const Vector &);

    friend double abs(const Vector &);

    friend std::ostream &operator<<(std::ostream &, const Vector &);
    friend std::istream &operator>>(std::istream &, Vector &);
};

class Line : public Geometry{
private:

};
#endif //MIPT_CPP_VECTOR_H
