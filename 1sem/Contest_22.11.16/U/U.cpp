#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    int **b = new int *[n];
    char *c = new char [n + m - 2];
    for(int i = 0; i < n; ++i)
    {
        a[i] = new int[m];
        b[i] = new int[m];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    b[0][0] = a[0][0];
    for(int i = 1; i < n; ++i){
        b[i][0] = b[i - 1][0] + a[i][0];
    }
    for(int j = 1; j < m; ++j){
        b[0][j] = b[0][j - 1] + a[0][j];
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            b[i][j] = a[i][j] + max (b[i - 1][j], b[i][j - 1]);
        }
    }
    cout << b[n - 1][m - 1] << endl;
    for(int i = n - 1, j = m - 1; i != 0 || j != 0; ){
            if(i != 0 && (b[i - 1][j] > b[i][j - 1] || j == 0)){
                c[i + j - 1] = 'D';
                --i;
            }
            else {
                c[i + j - 1] = 'R';
                --j;
            }
    }
    for (int i = 0; i < n + m - 2; ++i)
    {
        cout << c[i] << ' ';
    }
    for(int i = 0; i < n; ++i)
    {
        delete []a[i];
        delete []b[i];
    }
    delete []a;
    delete []b;
    delete []c;
    return 0;
}
/*
3 4
1 1 2 1
2 2 1 1
2 1 2 1

9
*/
