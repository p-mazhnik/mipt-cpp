//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

int main() {
    BigInt b1; //= "1037812047196842163142241";
    BigInt b0; // = -10009;
    std::cin >> b1;
    std::cin >> b0;
    b1.print();
    b0.print();
    std::cout << "sqrt(b1) = " << sqrt(b1) << std::endl;
    std::cout << "sqrt(b0) = " << sqrt(b0) << std::endl;
    std::cout << "NOD(b1, b0) = " << nod(b1, b0) << std::endl;
    std::cout << "b1 * b0 = " << b1 * b0<< std::endl;
    std::cout << "b1 / b0 = " << b1 / b0 << std::endl;
}