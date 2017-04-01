//
// Created by pavel on 30.03.2017.
//

#include "Vector.h"

int main(){
    Vector v1, v2;
    std::cin >> v1 >> v2;
    std::cout.precision(6);
    std::cout << abs(v1) << ' ' << abs(v2) << '\n';
    std::cout << v1 + v2 << '\n';
    std::cout << (v1 * v2) << ' ' << vector_mult(v1, v2) << '\n';
    std::cout << triangle_square(v1, v2);
}