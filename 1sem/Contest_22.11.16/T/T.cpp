#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    a[0] = 2;
    a[1] = 4;
    a[2] = 7;
    for(int i = 3; i < n; ++i){
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    cout << a[n - 1];
    delete []a;
    return 0;
}
