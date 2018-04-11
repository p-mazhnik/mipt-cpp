#include <iostream>
#include <cmath>

using namespace std;

int diag(int a, int b, int c)
{
    return sqrt(a*a + b*b + c*c);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << diag(a, b, c) << endl;
    return 0;
}
