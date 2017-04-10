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
    long long x;
    long long y;
public:
    Vector(const Point &p1, const Point &p2);
    Vector(const long long x = 0, const long long y = 0);
    Vector(const Vector &);

    long long get_x() const;
    long long get_y() const;

    Vector &operator=(const Vector &);
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;

    long long operator*(const Vector &) const; //скалярное произведение
    friend long long vector_mult(const Vector &, const Vector &); //векторное произведение
    friend long long triangle_square(const Vector &, const Vector &);

    friend long long abs(const Vector &);

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
    long long x;
    long long y;
public:
    Point(const long long x = 0, const long long y = 0);
    Point(const Point &);

    Point &operator=(const Point &);

    long long get_x() const;
    long long get_y() const;

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
    Polygon jarvis ();
    bool polygon_convex();
    void shift(const Vector &);
    bool point_contains(const Point &) const;
    bool segment_cross(const Segment &) const;
};
#endif //MIPT_CPP_VECTOR_H

using namespace std;

void C();
void B();
void D();
void E();
void F();
void G();
void H();
void I();
void J();
void K();

int main(){
    K();
}

void C(){
    Line l1, l2;
    cin >> l1 >> l2;
    cout << fixed << setprecision(6) << l1.get_vector() << '\n' << l2.get_vector() << '\n';
    if(line_parallel(l1, l2)){
        cout << line_distance(l1, l2);
    } else{
        cout << point_cross(l1, l2);
    }
}

void B(){
    Vector v1, v2;
    cin >> v1 >> v2;
    cout << fixed << setprecision(6) << abs(v1) << ' ' << abs(v2) << '\n';
    cout << v1 + v2 << '\n';
    cout << (v1 * v2) << ' ' << vector_mult(v1, v2) << '\n';
    cout << triangle_square(v1, v2);
}

void D(){
    Point A, B, C;
    cin >> C >> A >> B;
    Line l(A, B);
    Segment s(A, B);
    Ray r(A, B);
    l.point_contains(C) ? cout << "YES" << '\n' : cout << "NO" << '\n';
    r.point_contains(C) ? cout << "YES" << '\n' : cout << "NO" << '\n';
    s.point_contains(C) ? cout << "YES" : cout << "NO";

}

void E(){
    Point A, B, C;
    cin >> C >> A >> B;
    Line l(A, B);
    Segment s(A, B);
    Ray r(A, B);
    cout << fixed << setprecision(6) << l.point_distance(C) << '\n';
    cout << r.point_distance(C) << '\n';
    cout << s.point_distance(C);

}

void F(){
    Segment s1, s2;
    cin >> s1 >> s2;
    s1.segment_cross(s2) ? cout << "YES" << '\n' : cout << "NO" << '\n';
}

void G(){
    Segment s1, s2;
    cin >> s1 >> s2;
    cout << fixed << setprecision(6) << segment_distance(s1, s2);
}

void H(){
    Polygon pol;
    cin >> pol;
    pol.polygon_convex() ? cout << "YES" << '\n' : cout << "NO" << '\n';
}

void I(){
    int n;
    cin >> n;
    Polygon pol(n);
    Point p;
    cin >> p;
    cin >> pol;
    pol.point_contains(p) ? cout << "YES" : cout << "NO";
}

void J(){
    Polygon pol;
    cin >> pol;
    cout << pol.square();
}

void K(){
    Polygon p1;
    cin >> p1;
    Polygon p2(p1.jarvis());
    cout << p2 << endl;
    cout << fixed << setprecision(10) << p2.square();
}

//
// Created by pavel on 26.03.2017.
//

//--------VECTOR--------\\

Vector::Vector(const Point &p1, const Point &p2) : x(p2.get_x() - p1.get_x()), y(p2.get_y() - p1.get_y()) {}

Vector::Vector(const long long x, const long long y) : x(x), y(y) {}

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

long long Vector::operator*(const Vector &that) const {
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

long long abs(const Vector &that) {
    return sqrt(fabs(that.x * that.x + that.y * that.y));
}

long long vector_mult(const Vector &a, const Vector &b) {
    return (a.x * b.y - a.y * b.x);
}

long long triangle_square(const Vector &a, const Vector &b) {
    return fabsl(vector_mult(a, b) / 2);
}

long long Vector::get_x() const {
    return this->x;
}

long long Vector::get_y() const {
    return this->y;
}

//--------POINT--------\\

Point::Point(const long long x, const long long y) : x(x), y(y) {}

Point::Point(const Point &that) : x(that.x), y(that.y) {}

long long Point::get_x() const{
    return x;
}
long long Point::get_y() const{
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

void Point::shift(const Vector &that) {
    this->x += that.get_x();
    this->y += that.get_y();
}

bool Point::point_contains(const Point &that) const{
    return (this->x == that.x && this->y == that.y);
}

bool Point::segment_cross(const Segment &s) const{
    Vector v1(s.get_begin(), *this);
    Vector v2(*this, s.get_end());
    return (vector_mult(v1, v2) == 0 && (v1 * v2) >= 0);
}

//--------LINE--------\\

Line::Line(const double a, const double b, const double c) : a(a), b(b), c(c) {}

Vector Line::get_vector() const {
    Vector result(-b, a);
    return result;
}

bool line_parallel(const Line &l1, const Line &l2) {
    return (l1.a *l2.b == l1.b * l2.a);
}

Point point_cross(const Line &l1, const Line &l2) {
    double x = (-l1.c * l2.b + l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
    double y = (-l1.a * l2.c + l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
    return Point(x, y);
}

double line_distance(const Line &l1, const Line &l2) {
    //return (fabs(l2.c - l1.c) / sqrt(l1.a * l1.a + l2.b * l2.b));
    Line l(l1.b, -l1.a, 0);
    Vector v(point_cross(l1, l), point_cross(l, l2));
    return abs(v);
}

std::istream &operator>>(std::istream &in, Line &l) {
    in >> l.a >> l.b >> l.c;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Line &l) {
    out << l.a << ' ' << l.b << ' ' << l.c;
    return out;
}

Line::Line(const Point &p1, const Point &p2) : a(p2.get_y() - p1.get_y()), b(p1.get_x() - p2.get_x()),
                                               c(p1.get_y() * p2.get_x() - p1.get_x() * p2.get_y()) {}

double Line::point_distance(const Point &p) const {
    Line l2(this->a, this->b, -this->a * p.get_x() - this->b * p.get_y());
    return line_distance(*this, l2);
}

bool Line::point_contains(const Point &p) const {
    return (this->a * p.get_x() + this->b * p.get_y() + this->c == 0);
}

void Line::shift(const Vector &v) {
    this->c += this->a * v.get_x() + this->b * v.get_y();
}

bool Line::segment_cross(const Segment &s) const {
    double end = a * s.get_end().get_x() + b * s.get_end().get_y() + c;
    double begin = a * s.get_begin().get_x() + b * s.get_begin().get_y() + c;
    return (end * begin <= 0);

}

//--------SEGMENT--------\\

Segment::Segment(const Point &a, const Point &b) : a(a), b(b) {}

Point Segment::get_end() const {
    return this->b;
}

Point Segment::get_begin() const {
    return this->a;
}

void Segment::shift(const Vector &v) {
    this->a.shift(v);
    this->b.shift(v);
}

bool Segment::point_contains(const Point &p) const{
    return p.segment_cross(*this);
}

bool Segment::segment_cross(const Segment &s) const {
    Line l1(s.get_begin(), s.get_end());
    Line l2(this->get_begin(), this->get_end());
    if(l1.segment_cross(*this) && l2.segment_cross(s) && line_parallel(l1, l2) &&
       !(this->point_contains(s.get_begin()) || this->point_contains(s.get_end()) ||
         s.point_contains(this->get_begin()) || s.point_contains(this->get_end()))){
        return 0;
    }
    return (l1.segment_cross(*this) && l2.segment_cross(s));
}

double Segment::point_distance(const Point &p) const {
    if(this->point_contains(p)){
        return 0;
    }
    Ray r1(this->a, this->b);
    Ray r2(this->b, this->a);
    return std::max(r1.point_distance(p), r2.point_distance(p));
}

double segment_distance(const Segment &s1, const Segment &s2) {
    if(s1.segment_cross(s2)){
        return 0;
    }
    return std::min(std::min(s1.point_distance(s2.a), s1.point_distance(s2.b)),
                    std::min(s2.point_distance(s1.a), s2.point_distance(s1.b)));
}

std::istream &operator>>(std::istream &in, Segment &s) {
    in >> s.a >> s.b;
    return in;
}

Segment::Segment() : a(Point(0, 0)), b(Point(0, 0)) {}

Segment &Segment::operator=(const Segment &that) {
    this->a = that.a;
    this->b = that.b;
    return *this;
}

//--------RAY--------\\

Ray::Ray(const Point &a, const Point &b) : begin(a), point(b) {}

void Ray::shift(const Vector &v) {
    this->begin.shift(v);
    this->point.shift(v);
}

bool Ray::point_contains(const Point &p) const {
    Vector v1(this->begin, p); //вектор из начала луча в точку
    Vector v2(this->begin, this->point); //вектор вдоль луча
    return ((v1 * v2) >= 0 && vector_mult(v1, v2) == 0);
}

bool Ray::segment_cross(const Segment &s) const {
    Line l1(this->begin, this->point);
    Line l2(s.get_begin(), s.get_end());
    if(line_parallel(l1, l2)){
        return 0;
    }
    else{
        return this->point_contains(point_cross(l1, l2));
    }
}

double Ray::point_distance(const Point &p) const {
    if(this->point_contains(p)){
        return 0;
    }
    Line l(this->begin, this->point);
    Vector v1(this->begin, p); //вектор из начала луча в точку
    Vector v2(this->begin, this->point); //вектор вдоль луча
    if((v1 * v2) >= 0){
        return l.point_distance(p);
    }
    else{
        return abs(v1);
    }
}

//--------POLYGON--------\\

Polygon::Polygon(const int n) {
    this->n = n;
    this->vertices = new Point[this->n];
}

std::istream &operator>>(std::istream &in, Polygon &pol) {
    if(pol.n == 1){
        delete []pol.vertices;
        in >> pol.n;
        pol.vertices = new Point[pol.n];
    }
    for (int i = 0; i < pol.n; ++i) {
        in >> pol.vertices[i];
    }
    return in;
}

Polygon::~Polygon() {
    delete []this->vertices;
}

void Polygon::shift(const Vector &v) {
    for (int i = 0; i < n; ++i) {
        this->vertices[i].shift(v);
    }
}

bool Polygon::polygon_convex() {
    Vector v1(this->vertices[this->n - 1], this->vertices[0]);
    Vector v2(this->vertices[0], this->vertices[1]);
    double m = vector_mult(v1, v2);
    for (int i = 1; i <= n - 1; ++i) {
        v1 = Vector(this->vertices[i - 1], this->vertices[i]);
        if(i != n - 1) {
            v2 = Vector(this->vertices[i], this->vertices[i + 1]);
        }
        else {
            v2 = Vector(this->vertices[i], this->vertices[0]);
        }
        if (m == 0) {
            m = vector_mult(v1, v2);
        }
        if (vector_mult(v1, v2) * m < 0) {
            return false;
        }
    }
    return true;
}

bool Polygon::point_contains(const Point &point) const {
    Segment s(this->vertices[0], this->vertices[this->n - 1]);
    if(s.point_contains(point)) {
        return true;
    }
    for (int i = 0; i < n - 1; ++i) {
        Segment s(this->vertices[i], this->vertices[i + 1]);
        if(s.point_contains(point)) {
            return true;
        }
    }
    bool result = false;
    int j = this->n - 1;
    for (int i = 0; i < this->n; i++) {
        if ( (this->vertices[i].get_y() < point.get_y() && this->vertices[j].get_y() >= point.get_y() ||
              this->vertices[j].get_y() < point.get_y() && this->vertices[i].get_y() >= point.get_y()) &&
             (this->vertices[i].get_x() + (point.get_y() - this->vertices[i].get_y()) / (this->vertices[j].get_y() -
                                                                                         this->vertices[i].get_y()) * (this->vertices[j].get_x() - this->vertices[i].get_x()) < point.get_x()) )
            result = !result;
        j = i;
    }
    return result;
}

long double Polygon::square() {
    long long sum;
    Vector v1(this->vertices[0], this->vertices[this->n - 2]);
    Vector v2(this->vertices[0], this->vertices[this->n - 1]);
    bool flag1 = vector_mult(v1, v2) > 0;
    sum = vector_mult(v1, v2);
    for (int i = 1; i < n - 2; ++i) {
        long long k;
        v1 = Vector(this->vertices[0], this->vertices[i]);
        v2 = Vector(this->vertices[0], this->vertices[i + 1]);
        k = vector_mult(v1, v2);
        bool flag2 = vector_mult(v1, v2) > 0;
        if(flag1 != flag2) k *= -1;
        sum += k;
    }
    int sign;
    sign = sum >= 0 ? 1 : -1;
    return (long double)(sum * sign) / 2;
}

bool Polygon::segment_cross(const Segment &s) const {
    if(this->point_contains(s.get_begin()) || this->point_contains(s.get_end())){
        return true;
    }
    Segment s_i(this->vertices[0], this->vertices[this->n - 1]);
    if(s_i.segment_cross(s)) return true;
    for (int i = 0; i < n - 1; ++i) {
        s_i = Segment(this->vertices[i], this->vertices[i + 1]);
        if(s_i.segment_cross(s)) return true;
    }
    return false;
}

Polygon Polygon::jarvis() {
    int n = this->n;
    Polygon result(n);
    int first, q, next;
    // находим самую нижнюю из самых левых точек
    first = 0;
    for (int i = 1; i < n; ++i){
        if (this->vertices[i].get_x() < this->vertices[first].get_x() ||
            (this->vertices[i].get_x() == this->vertices[first].get_x() &&
             this->vertices[i].get_y() < this->vertices[first].get_y())){
            first = i;
        }
    }
    q = first;
    long long area;
    int j;
    for (j = 0; q != first || j == 0; ++j) {
        result.push(this->vertices[q], j);
        next = q;
        // ищем следующую точку
        for (int i = n - 1; i >= 0; --i)
            if (this->vertices[i].get_x() != this->vertices[q].get_x() || this->vertices[i].get_y() != this->vertices[q].get_y()){
                Vector v1(this->vertices[q], this->vertices[i]);
                Vector v2(this->vertices[i], this->vertices[next]);
                area = vector_mult(v1, v2);
                Polygon box(4);
                box.push(this->vertices[q], 0);
                Point p2(this->vertices[i].get_x(), this->vertices[q].get_y());
                box.push(p2, 1);
                box.push(this->vertices[i], 2);
                Point p4(this->vertices[q].get_x(), this->vertices[i].get_y());
                box.push(p4, 3);
                if (next == q || area > 0 || (area == 0 && box.point_contains(this->vertices[next])))
                    next = i;
            }
        q = next;
    }
    result.n = j;
    return result;
}

void Polygon::push(const Point &p, int index) {
    this->vertices[index] = p;
}

std::ostream &operator<<(std::ostream &out, const Polygon &p) {
    out << p.n << '\n';
    for (int i = 0; i < p.n - 1; ++i) {
        out << p.vertices[i] << '\n';
    }
    out << p.vertices[p.n - 1];
    return out;
}

Polygon::Polygon(const Polygon &that) {
    this->n = that.n;
    this->vertices = new Point[this->n];
    for (int i = 0; i < this->n; ++i) {
        this->vertices[i] = that.vertices[i];
    }
}