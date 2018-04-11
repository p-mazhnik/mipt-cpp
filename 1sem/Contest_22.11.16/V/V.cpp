#include <iostream>

using namespace std;

void print_array(int *a, int n) // вывод массива длины n на экран
{
    for (int i = 0; i < n; ++i) {
            cout << a[i];
    };
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n + 1];
    a[1] = 0;
    for(int i = 2; i < n + 1; ++i){
        if(i % 3 == 0 || i % 2 == 0){
            if(i % 3 == 0 && i % 2 == 0){
                a[i] = min(min(a[i / 3], a[i / 2]), a[i - 1]) + 1;
            }
            else if (i % 3 == 0){
                a[i] = min(a[i / 3], a[i - 1]) + 1;
            }
            else {
                a[i] = min(a[i / 2], a[i - 1]) + 1;
            }
        }
        else {
            a[i] = a[i - 1] + 1;
        }
    }
    int *b = new int[a[n]];
    for(int i = a[n] - 1, k = n; i >= 0; --i){
        if(k % 3 == 0 && a[k / 3] == a[k] - 1){
            b[i] = 3;
            k = k / 3;
        }
        else if(k % 2 == 0 && a[k / 2] == a[k] - 1){
            b[i] = 2;
            k = k / 2;
        }
        else{
            b[i] = 1;
            --k;
        }
    }
    print_array(b, a[n]);
    delete []b;
    delete []a;
    return 0;
}
