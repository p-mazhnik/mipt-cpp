#include <stdio.h>
#include <iostream>

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

int main()
{
    int k, n;
    cin >> n >> k;
        int **c = new int *[k];
        for(int i = 0; i < k; ++i){
            c[i] = new int[n + 1];
        }
        for(int j = 0; j < n + 1; ++j){
            c[0][j] = 0;
        }
        c[0][0] = 1;
        c[0][1] = 1;
        c[0][3] = 1;
        for(int i = 1; i < k; ++i){
            for(int j = 0; j < n + 1; ++j){
                if(j >= 3) {
                    c[i][j] = c[i - 1][j - 3] + c[i - 1][j - 1] + c[i - 1][j];
                }
                else if (j < 3 && j >= 1) {
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                }
                else {
                    c[i][j] = c[i - 1][j];
                }
            }
        }
        cout << c[k - 1][n];
        for(int i = 0; i < k; ++i){
            delete []c[i];
        }
        delete []c;
    return 0;
}
