#include <iostream>

using namespace std;

void filling_array(int **b, int n, int m) // заполнение двумерного массива
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j){
            cin >> b[i][j];
        }

    };
}

int main()
{
    int n;
    cin >> n;
    int **b = new int *[n];
    for (int i = 0; i < n; ++i){
        b[i] = new int[2];
    }
    int a0 = 0, a1 = 0, a01 = 0, a10 = 0;
    filling_array(b, n, 2);
    for(int i = 0; i < n; ++i){
        if(b[i][0] == b[i][1]){
            if(!b[i][0]){
                a0++;
            }
            else {
                a1++;
            }
        }
        else {
            if(!b[i][0]){
                a01++;
            }
            else {
                a10++;
            }
        }
    }
   if ((a0 + a01) % 2 == 0 ){
        if (a01 == a10){
            if(a01) {
                cout << "YES";
            }
            else {
                if(!a0 || !a1){
                    cout << "YES";
                }
                else {
                    cout << "NO";
                }
            }
        }
        else {
            cout << "NO";
        };
    }
    else {
        cout << "NO";
    }
    for (int i = 0; i < n; ++i){
        delete []b[i];
    }
    delete []b;
    return 0;
}
