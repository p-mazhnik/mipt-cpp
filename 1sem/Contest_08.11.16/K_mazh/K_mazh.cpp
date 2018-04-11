#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int *a = new long long int[n];
    cin >> a[0];
    int max1 = 0;
    int min1 = 0;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] > a[max1]){
            max1 = i;
        }
        if (a[i] < a[min1]){
            min1 = i;
        }
    } ///после этого цикла знаю max и min элементы
    int max2;
    int min2;
    if (max1 != 0) {
        max2 = 0;
    }
    else {
        max2 = 1;
    }
    if (min1 != 0) {
        min2 = 0;
    }
    else {
        min2 = 1;
    }
    for (int i = 0; i < n; ++i){
        if (i == max1 || i == min1) {
            continue;
        }
        if (a[i] > a[max2]){
            max2 = i;
        }
        if (a[i] < a[min2]){
            min2 = i;
        }
    }
    if (a[max1] * a[max2] > a[min1] * a[min2]){
        cout << a[max1] * a[max2];
    }
    else {
        cout << a[min1] * a[min2];
    }
    delete []a;
    return 0;
}
//mazhnik
/**
В этой задаче вам требуется максимизировать произведение двух чисел из массива a_i и a_j, таких, что i не равно j.

Формат входных данных

В первой строке записано число N — количество элементов в массиве (2 ≤ N ≤ 10^6).
В следующей строке дано N чисел, каждое из которых по модулю не превосходит 10^9.

Формат результата

Программа должна вывести одно число — максимальное произведение двух чисел из массива.

Примеры

Входные данные	Результат работы
5
-1 0 1 2 3
6
5
1 0 -1 -2 -3
6
*/
