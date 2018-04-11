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

void print_array(int *a, int n) // вывод массива длины n на экран
{
    for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
    };
    cout << endl << endl;
}

int left_f(int i)
{
    return 2 * i + 1;
}

int right_f(int i)
{
    return 2 * i + 2;
}

void sift_down(int *a, int n, int index)
{
    int left = left_f(index);
    int right = right_f(index);
    int imax = index;
    if (left < n && a[left] > a[imax]) {
        imax = left;
    }
    if (right < n && a[right] > a[imax]){
        imax = right;
    }
    if (index != imax){
        swap(a[index], a[imax]);
        sift_down(a, n, imax);
    }
}

void build_heap(int *a, int n)
{
    for(int i = (n - 1) / 2; i >= 0; --i){
        sift_down (a, n ,i);
    }
}

void heap_sort (int *a, int n)
{
    build_heap(a, n);
    for (int i = n - 1; i > 0; --i){
        swap(a[0], a[i]);
        //n = n - 1;
        sift_down (a, i, 0);
    }
}

int main()
{
    int n = 10;
    int *a = new int[n];
    rand_array(a, n);
    print_array(a, n);
    build_heap(a, n);
    print_array(a, n);
    heap_sort(a, n);
    print_array(a, n);
    delete []a;
    return 0;
}
