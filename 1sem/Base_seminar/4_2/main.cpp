#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i] = rand();
    };
    for (int i = 1; i < n; ++i) {
        if ((a[i] > a[i-1]) && (a[i] > a[i+1])) {
            cout << a[i] << endl;
        };
    };
    return 0;
}
