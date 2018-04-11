#include <iostream>
#include <stdio.h>

using namespace std;

/*void print_array2(int **a, int n, int m) // вывод двумерного массива c n строками и m столбцами на экран
{
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
               printf("%5d ", a[i][j]);
        }
        cout << endl;
    };
    cout << endl << endl;
}*/

void filling(int **c, int n, int m, int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m){
        return;
    }
    filling(c, n, m, i + 2, j - 1); filling(c, n, m, i + 2, j + 1); filling(c, n, m, i - 1, j + 2); filling(c, n, m, i + 1, j + 2);
    c[i][j]++;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **c = new int *[n];
    for(int i = 0; i < n; ++i){
        c[i] = new int[m];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            c[i][j] = 0;
        }
    }
    c[0][0] = 1;
    filling(c, n, m, 0, 0);
    cout << c[n - 1][m - 1] << endl;
    //print_array2(c, n, m);
    for(int i = 0; i < n; ++i){
        delete []c[i];
    }
    delete []c;
    return 0;
}
