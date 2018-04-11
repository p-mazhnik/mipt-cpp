#include <iostream>

using namespace std;

int NOD(int x, int y){
  if (y == 0) return x;
  return NOD(y, x % y);
}

int main()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d;
    k = NOD((a * d + b * c), b * d);
    cout << (a * d + b * c) / k << ' ' << b * d / k << endl;
    return 0;
}
/*
Даны четыре неотрицательных числа a, b, c и d.
Сложить две рациональные дроби a/b и c/d,
а их результат представить в виде несократимой дроби m/n. Вывести числа m и n. a, b, c, d ≤ 1000.
Пример

Ввод	Вывод
3 10 5 18
26 45
*/
