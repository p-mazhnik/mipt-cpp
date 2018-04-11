#include <iostream>

using namespace std;

void filling_array(int **a, int **s, int n, int m) // заполнение двумерного массива
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
             cin >> a[i][j];
             if (i > 0 && j > 0) {
                s[i][j] = a[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
             }
             if (i == 0 && j == 0){
                s[i][j] = a[i][j];
             }
             if (i == 0 && j > 0){
                s[i][j] = a[i][j] + s[i][j - 1];
             }
             if (i > 0 && j == 0) {
                s[i][j] = a[i][j] + s[i - 1][j];
             }
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
    int **s = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[m];
        s[i] = new int[m];
    };
    filling_array(a, s, n, m);
    ///s[0][1] = {a[0][0]} + a[0][1]; s[1][1] = {{a[0][0]} + a[0][1]} + a[1][0] + a[1][1] = a[1][1] + s[1][0] + s[0][1] - s[0][0];
    ///s[i][j] = a[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
    print_array(s, n, m);
    for (int i = 0; i < n; ++i){
        delete []a[i];
        delete []s[i];
    }
    delete []a;
    delete []s;
    return 0;
}
//mazhnik
