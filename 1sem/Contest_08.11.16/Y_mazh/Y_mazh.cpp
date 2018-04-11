#include <iostream>

using namespace std;

void filling_array(int **a, int n, int m) // заполнение двумерного массива
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
             cin >> a[i][j];
        };
    };
}

int multiplication(int **a, int **b, int i, int j, int m)
{
    int s = 0;
    for(int k = 0; k < m; ++k){
        s += a[i][k] * b[k][j];
    }
    return s;
}

void matrix_multiplication(int **a, int **b, int **s, int n, int k, int m) // перемножение
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
             s[i][j] = multiplication(a, b, i, j, m);
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
    int n, m, k;
    cin >> n >> m >> k;
    int **a = new int *[n];
    int **b = new int *[m];
    int **s = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[m];
        s[i] = new int[k];
    };
    for (int i = 0; i < m; ++i){
        b[i] = new int[k];
    };
    filling_array(a, n, m);
    filling_array(b, m, k);
    matrix_multiplication(a, b, s, n, k, m);
    print_array(s, n, k);
    for (int i = 0; i < n; ++i){
        delete []a[i];
        delete []s[i];
    }
    for (int i = 0; i < m; ++i){
        delete []b[i];
    }
    delete []b;
    delete []a;
    delete []s;
    return 0;
}
//mazhnik
