#include <iostream>

using namespace std;

void swap1(int *a, int *b)
{
    int k;
    k = *a;
    *a = *b;
    *b = k;
}

void swap2(int &a, int &b)
{
    int k;
    k = a;
    a = b;
    b = k;
}

int main()
{
    int a1, b1;
    int &a = a1;
    int &b = b1;
    cin >> a1 >> b1;
    swap2(a, b);
    cout << a1 << ' ' << b1;
    return 0;
}
