#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b;
    c = 1 / (1 + (a - b)*(a - b));
    cout << b * (1 / (1 + (a / b) )) + a * (1 / (1 + (b / a) )) + c * a  << endl;
    return 0;
}
