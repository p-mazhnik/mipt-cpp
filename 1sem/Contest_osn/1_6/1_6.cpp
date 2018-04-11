#include <iostream>

int main()
{
    int n, i, x;
    int a[10001];
    std::cin >> n;
    for(i = 1; i <= n; ++i){
            std::cin >> a[i];
    };
    for(i = 1; i <= n/2; ++i){
            x = a[i];
            a[i] = a[n + 1 - i];
            a[n + 1 - i] = x;
        };
    for(i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    return 0;
}
/*
1_6. Дан массив целых чисел A[0..n).
Не используя других массивов переставить элементы массива A  в обратном порядке за O(n).
n ≤ 10000.
in
out
4
3 9 -5 2
2 -5 9 3

*/
