#include <iostream>
#include <stdio.h>

using namespace std;

void filling_array(int **a, int *line, int *column, int n, int m) // заполнение массивов
{
    for (int j = 0; j < m; ++j) {
        column[j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        line[i] = 0;
        for (int j = 0; j < m; ++j) {
             cin >> a[i][j];
             line[i] += a[i][j];
             column[j] += a[i][j];
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

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[m];
    };
    int *line = new int[n];
    int *column = new int[m];
    filling_array(a, line, column, n, m);
    int s0 = line[0] + column[0] - a[0][0];
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for(int ri = i; ri < n; ++ri){
            s += line[ri];
            for(int j = 0; j < m; ++j ){
                for (int rj = j, s2 = s; rj < m; ++rj){
                    s2 += column[rj];
                    for(int rri = i; rri <= ri; ++rri){
                        s2 -= a[rri][rj];
                    }
                    if(s2 > s0) {
                        s0 = s2;
                    }
                }
            }
        }
    }
    cout << s0;
    for (int i = 0; i < n; ++i){
        delete []a[i];
    }
    delete []a;
    delete []line;
    delete []column;
    return 0;
}
//mazhnik
/*
5 4
 2  -6  -7  -4
-5  -5   8   1
 5  -5   5   7
 4   2  -1   7
-2  -7   6  -6
31
*/
