#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    float a0 = 5, A, a;
    cout << "vvedite A : ";
    cin >> A;
    for (int i = 0; ; ++i) {
        a = (a0 / 2) + A / (2 * a0);
        if (a - a0 <= 0.01) break;
        a0 = a;
    };
    printf("sqrt(A) = %.2f\n", sqrt(A));
    printf("lim(an) = %.2f\n", a);
    return 0;
}
