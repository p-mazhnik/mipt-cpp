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
}
*/

void print_number(int **c, int *a, int *b, int i, int j)
{
    if (i == 0 || j == 0){
        return;
    }
    if (a[i - 1] == b[j - 1]){
        print_number(c, a, b, i - 1, j - 1);
        cout << a[i - 1] << ' ';
    }
    else{
        if (c[i][j] == c[i - 1][j]){
            print_number(c, a, b, i - 1, j);
        }
        else{
            print_number(c, a, b, i, j - 1);
        }
    }
}

int main()
{
    int n, m;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> m;
    int *b = new int[m];
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    int **c = new int *[n + 1];
    for(int i = 0; i <= n; ++i){
        c[i] = new int[m + 1];
    }
    for(int i = 0; i < n + 1; ++i){
        c[i][0] = 0;
    }
    for(int j = 0; j < m + 1; ++j){
        c[0][j] = 0;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i - 1] == b[j - 1]){
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else{
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    // print_array2(c, n + 1, m + 1);
    //cout << c[n][m] << endl;
    print_number(c, a, b, n, m);
    delete []a;
    delete []b;
    for(int i = 0; i < n; ++i){
        delete []c[i];
    }
    delete []c;
    return 0;
}
/*
8
2 0 -1 3 2 4 0 3
*/
