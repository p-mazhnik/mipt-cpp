#include <iostream>

using namespace std;
/*
1   2  9 10 25
4   3  8 11 24
5   6  7 12 23
16 15 14 13 22
17 18 19 20 21
*/
void filling_array(int **a, int n) // заполнение двумерного массива
{
    int j = 0;
    int i = 0;
    int x = 1;
    for (int k = 1, l = 1; k <= n;) {
        if (x == 1) {  ///вправо
            while (j < k){
                a[i][j] = l;
                ++l;
                ++j;
            }
            --l;
            --j;
            if (k % 2 == 0) {
                    x = 2;
            }
            else {
                x = 4;
            }
        }
        if (x == 2) {  ///вниз
            while (i < k){
                a[i][j] = l;
                ++l;
                ++i;
            }
            --l;
            --i;
            if (k % 2 == 0) {
                    x = 3;
            }
            else {
                x = 1;
            }
        }
        if (x == 3) { ///влево
            while (j >= 0) {
                a[i][j] = l;
                ++l;
                --j;
            }
            --l;
            ++j;
            x = 2;
        }
        if (x == 4) { ///вверх
            while (i >= 0) {
                a[i][j] = l;
                ++l;
                --i;
            }
            ++i;
            --l;
            x = 1;
        }
        if (a[i][j] == k * k) {
            k++;
        }
        else {
            continue;
        }
    }
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
    int n;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i){
        a[i] = new int[n];
    };
    filling_array(a, n);
    print_array(a, n, n);
    for (int i = 0; i < n; ++i){
        delete []a[i];
    }
    delete []a;
    return 0;
}
//mazhnik


