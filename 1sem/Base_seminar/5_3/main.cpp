#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    };
    int max, min;
    max = min = a[0];
    for (int j = 0; j < n; ++j) {
        if (a[j] >= max) {
            max = a[j];
        };
        if (a[j] <= min) {
            min = a[j];
        };
    };
    cout << max << ' ' << min;
    delete []a;
    return 0;
}
