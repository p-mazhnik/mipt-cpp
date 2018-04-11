#include <stdio.h>
#include <iostream>
#include <cmath>

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
        int q, n;
        cin >> n >> q;
        float **c = new float *[n];
        for(int i = 0; i < n; ++i){
            c[i] = new float[q];
        }
        for(int j = 0; j < 6; ++j){
            c[0][j] = 1.0 / 6;
        }
        for(int j = 6; j < q; ++j){
            c[0][j] = 0;
        }
        for(int i = 1; i < n; ++i){
            c[i][0] = 0;
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < q; ++j){
                    c[i][j] = c[i - 1][j - 1];
                    for(int k = 2; j >= k && k <= 6; ++k){
                        c[i][j] += c[i - 1][j - k];
                    }
                    c[i][j] /= 6.0;
            }
        }
        cout << c[n - 1][q - 1];
        for(int i = 0; i < n; ++i){
            delete []c[i];
        }
        delete []c;
        return 0;
}
