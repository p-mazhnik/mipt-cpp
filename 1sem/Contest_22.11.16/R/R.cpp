#include <iostream>

using namespace std;

void print_array(int *a, int n) // вывод массива длины n на экран
{
    for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
    };
    cout << endl << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    int b[1000];
    b[0] = 1;
    int c[1000];
    int max = 1;
    int index = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
        b[i] = 1;
        for(int j = i - 1; j >= 0; --j){
            if(a[i] > a[j] && b[j] >= b[i]){
                b[i] = b[j] + 1;
            }
        }
        if(b[i] > max){
            max = b[i];
            index = i;
        }
    }
    c[max - 1] = a[index];
    for(int i = index - 1, j = max - 2; i >= 0; --i){
        if(a[i] < a[index] && b[i] == b[index] - 1){
            c[j] = a[i];
            index = i;
            --j;
        }
    }
    //print_array(a, n);
    //print_array(b, n);
    print_array(c, max);
    return 0;
}
/*
8
2 0 -1 3 2 4 0 3
*/
