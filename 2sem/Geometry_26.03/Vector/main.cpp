//
// Created by pavel on 30.03.2017.
//

#include "Vector.h"

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