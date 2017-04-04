//
// Created by pavel on 26.03.2017.
//

#ifndef MIPT_CPP_VECTOR_H
#define MIPT_CPP_VECTOR_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class Point;
class Segment;

class Vector {
private:
    double x;
    double y;
public:
    Vector(const Point &p1, const Point &p2);
    Vector(const double x = 0, const double y = 0);
    Vector(const Vector &);

    double get_x() const;
    double get_y() const;

    Vector &operator=(const Vector &);
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;

    double operator*(const Vector &) const; //скалярное произведение
    //Vector operator*(const double) const;
    friend double vector_mult(const Vector &, const Vector &); //векторное произведение
    friend double triangle_square(const Vector &, const Vector &);

    friend double abs(const Vector &);

    friend std::ostream &operator<<(std::ostream &, const Vector &);
    friend std::istream &operator>>(std::istream &, Vector &);
};

class Geometry{
public:
    virtual void shift(const Vector &) = 0;
    virtual bool point_contains(const Point &) const = 0;
    virtual bool segment_cross(const Segment &) const = 0;
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

    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};

class Line : public Geometry{
private:
    double a, b, c;
public:
    Line(const double a = 0, const double b = 0, const double c = 0);
    Line(const Point &, const Point &);

    Vector get_vector() const;

    friend bool line_parallel(const Line &, const Line &);
    friend double line_distance (const Line &, const Line &);
    double point_distance(const Point &) const;
    friend Point point_cross(const Line &, const Line &);

    friend std::ostream &operator<<(std::ostream &, const Line &);
    friend std::istream &operator>>(std::istream &, Line &);

    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};

class Segment : public Geometry{
private:
    Point a, b;
public:
    Segment();
    Segment(const Point &a, const Point &b);

    Point get_end() const;
    Point get_begin() const;

    friend double segment_distance (const Segment &, const Segment &);
    double point_distance (const Point &) const;
    friend std::istream &operator>>(std::istream &, Segment &);
    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};

class Ray : public Geometry{
private:
    Point begin, x;
public:
    Ray(const Point &, const Point &);
    double point_distance(const Point &) const;
    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};
#endif //MIPT_CPP_VECTOR_H
