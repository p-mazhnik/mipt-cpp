#include <iostream>

using namespace std;

int main()
{
    int *a = new int;
    int *b = new int;
    cin >> *a >> *b;
    cout << *a + *b;
    return 0;
}
