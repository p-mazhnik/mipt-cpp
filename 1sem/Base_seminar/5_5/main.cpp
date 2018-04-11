#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void rand_array(int *a, int n, int max_r, int min_r)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = min_r + rand() % (max_r + 1);
    };
}

void sort_array(int *a, int n)
{
    int k;
    for (int i = 0; i < n; ++i) {
       for (int j = n - 1; j > i; j--) {
           if (a[j-1] > a[j]) {
               k = a[j-1];
               a[j-1] = a[j];
               a[j] = k;
           };
       };
    };
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
    };
    cout << endl;
}

float avg(int n, int *a)
{
    float sum;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    };
    return sum/n;
}

int *expand(int *old, int old_n, int new_n)
{
    int *b = new int[new_n];
    for (int i = 0; i < old_n; ++i){
        b[i] = old[i];
    };
    delete []old;
    return b;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    rand_array(a, n, 10, 0);
    print_array(a, n);
    sort_array(a, n/2);
    sort_array(a + n/2, n/2);
    print_array(a, n);
    delete []a;
    return 0;
}
