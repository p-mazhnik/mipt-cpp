#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= x; ++j) {
                printf("%5d", i * j);
            };
            cout << endl;
    };
    return 0;
}
