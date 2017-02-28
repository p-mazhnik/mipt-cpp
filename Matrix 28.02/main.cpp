#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix m1(2, 3), m2(2, 3);
    std::cout << "First matrix: " << std::endl;
    std::cin >> m1;
    std::cout << "Second matrix: " << std::endl;
    std::cin >> m2;
    std::cout << m1 + m2 << std::endl;
    return 0;
}