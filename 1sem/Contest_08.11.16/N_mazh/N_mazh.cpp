#include <iostream>

using namespace std;

void filling_array(int **a, int n, int m) // заполнение двумерного массива
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
             cin >> a[i][j];
        };
    };
}

void print_array(int **a, int n, int m) // вывод двумерного массива c n строками и m столбцами на экран
{
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
               cout << a[i][j] << ' ';
        }
        cout << endl;
    };
}

bool cmp(int *a, int *b, int n) // сравнение двух массивов длины n
{
    int i = 0;
    while(a[i] == b[i] && i < n) {
        i++ ;
    }
    return (a[i] > b[i]);
}

void bb2_sort(int **a, int n, int m) // сортировка двумерного массива
{
    for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < n - 1 - i; ++j) {
           if (cmp(a[j], a[j + 1], m)) {
                swap(a[j], a[j + 1]);
           };
       };
    };
}

int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[3];
    };
    filling_array(a, n, 3);
    bb2_sort(a, n, 3);
    print_array(a, n, 3);
    for (int i = 0; i < n; ++i){
        delete []a[i];
    }
    delete []a;
    return 0;
}
//mazhnik
