#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int puz(int a[], int n) {
        int k;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; j--) {
                if (a[j-1] > a[j]) {
                    k = a[j-1];
                    a[j-1] = a[j];
                    a[j] = k;
                };
            };
        };
    return 0;
}

int main()
{
    srand(time(NULL));
    int a[1000];
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i] = rand();
        sum += a[i];
    };
    puz(a, n);
    cout << "MAX: " << a[n-1] << endl << "MIN: " << a[0] << endl << "SUM: " << sum << endl << "MEDIANA: " << a[n/2] << endl;
    return 0;
}
