//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

int main() {
    BigInt b1; //("1037812047196842163142241");
    BigInt b0;
    std::cin >> b1;
    std::cin >> b0;
    BigInt b2("333");
//    b2 = 111999;
   // std::cout << b2 << std::endl;
    std::cout << b1 << std::endl;
    std::cout << b0 << std::endl;
    std::cout << "b1 + b0 = " << b1 + b0 << std::endl;
    std::cout << "b0 + b1 = " << b0 + b1 << std::endl;
    std::cout << "b1 - b0 = " << b1 - b0 << std::endl;
    std::cout << "b0 - b1 = " << b0 - b1 << std::endl;
    //std::cout << "b1 - b2 = " << b1 - b2 << std::endl;
    //std::cout << "b1 * b2 = " << b1 * b2 << std::endl;
    //std::cout << "b1 / b2 = " << b1 / b2 << std::endl;
    //std::cout << "2 * b1 = " << 2 * b1 << std::endl;
}