#include <iostream>

using namespace std;

void filling_array(int *a, int n) // заполнение массива длины n
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void bubble_sort(int *a, int n, int &l) // сортировка пузырьком
{
    for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < n - 1 - i; ++j) {
           if (a[j] > a[j+1]) {
               int k = a[j];
               a[j] = a[j+1];
               a[j+1] = k;
               l++;
           };
       };
    };
}

int main()
{
    int n;
    int l = 0;
    cin >> n;
    int *a = new int[n];
    filling_array(a, n);
    bubble_sort(a, n, l);
    cout << l;
    return 0;
}
