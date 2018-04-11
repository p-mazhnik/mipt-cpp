#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k, i;
    cin >> n;
    k=1;
    cout << 1;
    for(i = 3; i < n + n + 1; i += 2){
        k = k + i;
        printf(" %d", k);
    };
    return 0;
}
/*
Вывести квадраты натуральных чисел от 1 до n,
используя только O(n) операций сложения и вычитания (умножением пользоваться нельзя). n ≤ 1000.
Пример

Ввод	Вывод
5
1 4 9 16 25
*/
