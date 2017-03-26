//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

int main() {
    BigInt a;
    BigInt b;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << a % b;
}