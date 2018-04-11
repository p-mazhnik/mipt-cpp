#include <iostream>

using namespace std;

int sumdel (int n)
{
    if (n == 1) {
        return 0;
    }
    int sum = 1;
    for(int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            if (i == n / i) {
                sum += i;
            }
            else {
                sum += i + n / i;
            }
        }
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if ((sumdel(n) == m) && (sumdel(m) == n)){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
/**
Два различных натуральных числа называются дружественными, если первое из них равно сумме делителей второго числа,
а второе равно сумме делителей первого числа. При подсчете делителей числа учитываются все делители, кроме самого числа.
Проверьте на дружественность числа N и M.

Формат входных данных

Во входном файле содержатся два натуральных числа N и M (N, M ≤ 10^6).

Формат результата

В выходной файл выведите «YES», если числа N и M дружественные, и «NO» в противном случае.

Примеры

Входные данные	Результат работы
220 284
YES
2 3
NO
*/