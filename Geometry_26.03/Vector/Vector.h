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
    long double x;
    long double y;
public:
    Vector(const Point &p1, const Point &p2);
    Vector(const long double x = 0, const long double y = 0);
    Vector(const Vector &);

    long double get_x() const;
    long double get_y() const;

    Vector &operator=(const Vector &);
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;

    long double operator*(const Vector &) const; //скалярное произведение
    friend long double vector_mult(const Vector &, const Vector &); //векторное произведение
    friend long double triangle_square(const Vector &, const Vector &);

    friend long double abs(const Vector &);

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
    long double x;
    long double y;
public:
    Point(const long double x = 0, const long double y = 0);
    Point(const Point &);

    Point &operator=(const Point &);

    long double get_x() const;
    long double get_y() const;

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
    Segment &operator=(const Segment &);
    friend double segment_distance (const Segment &, const Segment &);
    double point_distance (const Point &) const;
    friend std::istream &operator>>(std::istream &, Segment &);
    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};

class Ray : public Geometry{
private:
    Point begin, point;
public:
    Ray(const Point &, const Point &);
    double point_distance(const Point &) const;
    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};

class Polygon : public Geometry{
private:
    Point* vertices;
    int n;
public:
    Polygon(const int n = 1);
    Polygon(const Polygon &);
    ~Polygon();
    void push(const Point &, int);
    long double square();
    friend std::istream &operator>>(std::istream &, Polygon &);
    friend std::ostream &operator<<(std::ostream &, const Polygon &);
    Polygon jarvis();
    //Polygon graham();
    bool polygon_convex();
    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};
#endif //MIPT_CPP_VECTOR_H
