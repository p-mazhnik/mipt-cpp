#include <iostream>

int main()
{
    int a, d, i = 0;
    std::cin >> a >> d;
    do {
        std::cout << a << std::endl;
        a += d;
        i += 1;
    }
    while (i != 10);
    return 0;
}
