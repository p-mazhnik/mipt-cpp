#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 2; i * i <= n;) {
        if (n % i != 0) {
                ++i;
        }
        else {
                n /= i;
                std::cout << i << std::endl;
        };
    };
    std::cout << n;
    return 0;
}
