#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

int main()
{
    int N, sum, p;
    std::cin >> N;
    for (int j = 1, k = 1; j <= N; ++j) {
        k *= j;
        p = 1/k;
        sum+=p;
    };
    std::cout << sum << ' ';
    return 0;
}
