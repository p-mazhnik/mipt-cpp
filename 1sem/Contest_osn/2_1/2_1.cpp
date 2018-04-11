#include <iostream>

int main()
{
    int n, x;
    int a[100000];
    int b[100000];
    std::cin >> n;
    for(int i = 0; i < n; ++i){
            std::cin >> a[i];
    };
    for(int i = 0; i < n; ++i){
            std::cin >> b[i];
    };


    return 0;
}
/*
2_1. Даны два массива целых чисел одинаковой длины A[0..n-1] и B[0..n-1].
Необходимо найти первую пару индексов i0 и j0, i0 ≤ j0, такую что A[i0] + B[j0] = max {A[i] + B[j],
где 0 <= i < n, 0 <= j < n, i <= j}. Время работы - O(n).
n ≤ 100000.
in
out
4
4 -8 6 0
-10 3 1 1
0 1
*/
