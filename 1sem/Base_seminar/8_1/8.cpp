#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void print_array2(int **a, int n, int m) // вывод массива c n строками и m столбцами на экран
{
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
               printf("%5d ", a[i][j]);;
        }
        cout << endl;
    };
    cout << endl << endl;
}

void rand_array2(int **a, int n, int m) //
{
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = rand();
            };
    };
    print_array2(a, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[m];
    };
    rand_array2(a, n, m);
    for (int i = 0; i < n; ++i){
        delete []a[i];
    }
    delete []a;
    return 0;
}
