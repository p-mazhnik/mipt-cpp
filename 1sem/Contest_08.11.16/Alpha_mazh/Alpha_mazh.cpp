#include <iostream>


using namespace std;

void filling_array(char **b, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    };
}

int main()
{
    int n, m;
    cin >> n >> m;
    int line = 0;
    int column = 0;
    int l = 0;
    int h = 0;
    char **b = new char *[n];
    for (int i = 0; i < n; ++i){
        b[i] = new char[m + 1];
    }
    filling_array(b, n, m);
    for(int i = 0, j, i0; i < n; ++i){
        for(j = 0; j < m && b[i][j] == '1'; ++j);
        if (j == m) {
            ++line;
            if (line == 1) {
                i0 = i;
            }
        }
        if (line == 2){
            l = i - i0;
        }
    }
    for(int j = 0, i, j0; j < m; ++j){
        for(i = 0; i < n && b[i][j] == '1'; ++i);
        if (i == n) {
            ++column;
            if (column == 1) {
                j0 = j;
            }
        }
        if (column == 2){
            h = j - j0;
        }
    }
    ///посчитали кол-во непустых строк и столбцов
    /// и расстояния между ними
    if (n == 1 || m == 1){
        cout << '?';
    }
    else {
        if((line < 2 && column == 0) || (line == 0 && column < 2)) {
            cout << '?';
        }
        if(line >= 2 && column == 0){
            if(m > l) {
                cout << "Line";
            }
            else {
                cout << '?';
            }
        }
        if(line == 0 && column >= 2){
            if(n > h) {
                cout << "Vertical line";
            }
            else {
                cout << '?';
            }
        }
        if(line != 0 && column != 0){
            cout << "Square";
        }
    };
    for (int i = 0; i < n; ++i){
        delete []b[i];
    }
    delete []b;
    return 0;
}
