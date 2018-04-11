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

void print_number(int **c, int **a, int n, int m)
{
    if (c[n][m] == 0){
        return;
    }
    else if (c[n - 1][m] == c[n][m]){
        print_number(c, a, n - 1, m);
    }
    else{
        print_number(c, a, n - 1, m - a[0][n]);
        cout << n << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[2];
    for(int i = 0; i < 2; ++i){
        a[i] = new int [n + 1];
    }
    for(int i = 0; i < 2; ++i){
        for(int j = 1; j < n + 1; ++j){
            cin >> a[i][j];
        }
    }
    int **c = new int *[n + 1];
    for(int i = 0; i <= n; ++i){
        c[i] = new int[m + 1];
    }
    for(int i = 0; i <= n; ++i){
        c[i][0] = 0;
    }
    for(int j = 0; j <= m; ++j){
        c[0][j] = 0;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if (j >= a[0][i]) c[i][j] = max(c[i - 1][j], a[1][i] + c[i - 1][j - a[0][i]]);
            else c[i][j] = c[i - 1][j];
        }
    }
    //print_array2(c, n + 1, m + 1);
    print_number(c, a, n, m);
    for(int i = 0; i < 2; ++i){
        delete []a[i];
    }
    delete []a;
    for(int i = 0; i <= n; ++i){
        delete []c[i];
    }
    delete []c;
    return 0;
}
/*
5 16
4 5 3 7 6
5 7 4 9 8
*/
