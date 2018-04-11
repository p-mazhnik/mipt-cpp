#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    a[1] = a[2] = 1;
    for (int i = 3; i <= n; ++i){
        a[i] = (a[i - 2] + a[i - 1]) % 1000;
    }
    if (n > 16 && a[n] / 100 == 0 && a[n] / 10 == 0){
        cout << 0 << 0 << a[n];
    }
    else if (n > 16 && a[n] / 100 == 0){
        cout << 0 << a[n];
    }
    else {
        cout << a[n];
    }
    delete []a;
    return 0;
}
//mazhnik
