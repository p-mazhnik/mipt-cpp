#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    int n;
    cin >> A >> B >> C;
    if ((A == 0 && B == 0) || (B != 0)) {
        for(n = 0; B * n < A; ++n);
        cout << C*n;
    }
    else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}

