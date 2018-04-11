#include <iostream>

using namespace std;

void print_number(int ***c, int *a, int *b, int *d, int i, int j, int q)
{
    if (i == 0 || j == 0 || q == 0){
        return;
    }
    if (a[i - 1] == b[j - 1] && b[j - 1] == d[q - 1]){
        print_number(c, a, b, d, i - 1, j - 1, q - 1);
        cout << a[i - 1] << ' ';
    }
    else{
        if (c[i][j][q] == c[i - 1][j][q]){
            print_number(c, a, b, d, i - 1, j, q);
        }
        else if (c[i][j][q] == c[i][j - 1][q]){
            print_number(c, a, b, d, i, j - 1, q);
        }
        else{
            print_number(c, a, b, d, i, j, q - 1);
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int *a = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int *b = new int[m];
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    int *d = new int[k];
    for(int i = 0; i < k; ++i){
        cin >> d[i];
    }
    int ***c = new int **[n + 1];
    for(int i = 0; i < n + 1; ++i){
        c[i] = new int *[m + 1];
        for(int j = 0; j < m + 1; ++j){
            c[i][j] = new int [k + 1];
        }
    }
    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < m + 1; ++j){
            for(int q = 0; q < k + 1; ++q){
                c[i][j][q] = 0;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            for(int q = 1; q <= k; ++q){
                if(a[i - 1] == b[j - 1] && b[j - 1] == d[q - 1]){
                    c[i][j][q] = c[i - 1][j - 1][q - 1] + 1;
                }
                else{
                    c[i][j][q] = max(max(c[i - 1][j][q], c[i][j - 1][q]),c[i][j][q - 1]);
                }
            }
        }
    }
    /*for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < m + 1; ++j){
            for(int q = 0; q < k + 1; ++q){
                cout << c[i][j][q] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }*/
    cout << c[n][m][k] << endl;
    print_number(c, a, b, d, n, m, k);
    delete []a;
    delete []b;
    delete []d;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            delete []c[i][j];
        }
        delete []c[i];
    }
    delete []c;

    return 0;
}
