#include <iostream>

using namespace std;

struct p
{
    int a = 5;
    int b = 7;
    rep (int, int);
};

p::rep (int a, int b)
{
    this -> a = b;
    cout << a;
}

int main()
{

    return 0;
}
