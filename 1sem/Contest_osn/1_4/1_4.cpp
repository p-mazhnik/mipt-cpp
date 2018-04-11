#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i, j = 0;
    cin >> n;
    for(i = 2; i <= sqrt(n); ++i){
        if (n % i == 0) {
            j = 1;
            cout << n / i << ' ' << n - (n / i);
            break;
        };
    };
    if (j == 0) cout << 1 << ' ' << n - 1;
    return 0;
}
/*
1_4. Дано натуральное число N.
Представить N в виде A + B, так, что НОД(A, B) максимален, A ≤ B. Вывести A и B.
Если возможно несколько ответов - вывести ответ с минимальным A.
n ≤ 107.
in
out
35
7 28
*/
