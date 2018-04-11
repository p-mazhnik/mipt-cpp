#include <iostream>

using namespace std;

void filling_array(int *a, int n) // заполнение массива длины n
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void print_array(int *a, int n) // вывод массива длины n на экран
{
    for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
    };
}

void insert_sort (int *a, int n) // сортировка вставками
{
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && k < a[j]) {
            a[j + 1] = a[j];
            j--;
        };
        a[j + 1] = k;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    filling_array(a, n);
    insert_sort(a, n);
    print_array(a, n);
    return 0;
}
