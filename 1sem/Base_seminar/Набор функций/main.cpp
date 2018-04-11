#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>

#define longer 10

using namespace std;

void rand_array(int *a, int n) // заполнение массива длины n случайными числами от 1 до longer
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % (longer + 1);
    };
}

void rand_array2(int **a, int n, int m) // заполнение двумерного массива с n строками и m столбцами случайными числами от 1 до long
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
             a[i][j] = rand() % (longer + 1);
        };
    };
}

void print_array(int *a, int n) // вывод массива длины n на экран
{
    for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
    };
    cout << endl << endl;
}

void print_array2(int **a, int n, int m) // вывод двумерного массива c n строками и m столбцами на экран
{
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
               printf("%5d ", a[i][j]);
        }
        cout << endl;
    };
    cout << endl << endl;
}

int *copy_array(int *old, int old_n, int new_n) // копирование массива длины old_n в массив длины new_n
{
    int *b = new int[new_n];
    for (int i = 0; i < old_n; ++i){
        b[i] = old[i];
    };
    return b;
}

void bubble_sort(int *a, int n) // сортировка пузырьком
{
    for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < n - 1 - i; ++j) {
           if (a[j] > a[j + 1]) {
               int k = a[j];
               a[j] = a[j + 1];
               a[j + 1] = k;
           };
       };
    };
}

void selection_sort(int *a, int n) // сортировка выбора
{
    for (int i = 0; i < n - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[imin]) {
                imin = j;
            };
        };
        int k = a[i];
        a[i] = a[imin];
        a[imin] = k;
    }
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

int input () // ввод числа n из файла Input.txt
{
    int n;
    fstream f;
    f.open("Input.txt", ios::in);
    while (!f.eof()) { // eof = end of file
        f >> n;
    }
    f.close();
    return n;
}

void max_sort_array(int *a, int n) // сорировка, основанная на передвижении max числа по массиву.
{
    for(int i = 0, j = 0; j < n - 1; ++i){ // j - кол-во проходов по массиву
        if ((a[i] > a[i + 1]) && (i != n - 1)) {
            int k = a[i];
            a[i] = a[i + 1];
            a[i + 1] = k;
        }
        else if (i == n - 1) {
            i = -1;
            ++j;
        }
        else continue;
    };
}

bool cmp(int *a, int *b, int n) // сравнение двух массивов длины n
{
    int i = 0;
    while(a[i] == b[i] && i < n) i++ ;
    return (a[i] > b[i]);
}

void bb2_sort(int **a, int n, int m) // сортировка двумерного массива (пузырьком, ...)
{
    for (int i = 0; i < n; i++){
        max_sort_array(a[i], m);
    }; // отсортировал строки.
    for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < n - 1 - i; ++j) {
           if (cmp(a[j], a[j+1], m)) {
                swap(a[j], a[j+1]);
           };
       };
    };
}

/**void merge_sort_array (int *a, int n) // сортировка слиянием
{
    int ia = ib = 0; // a[] и b[] уже отсортированы! la и lb их длины
    while ((ia < la) && (ib < lb)) {
        if (a[ia] <= b[ib]) {
            c[ia + ib] = a[ia];
            ia++;
        }
        else {
            c[ia + ib] = b[ib];
            ib++;
        };
    };
    if ((ia >= la) && ())

}*/

/**typedef void (*mysort) (int) //объявление нового типа
void app(mysort f) {...*/

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[m];
    };
    rand_array(a, n, m);
    print_array(a, n, m);
    bb2_sort(a, n, m);
    print_array(a, n, m);
    for (int i = 0; i < n; ++i){
        delete []a[i];
    }
    delete []a;
    return 0;
}
