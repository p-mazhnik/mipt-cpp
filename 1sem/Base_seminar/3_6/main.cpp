#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x % 2 != 0) {
        cout << "YES";
    }
    else if (x % 4 == 0 ) {
        cout << "YES";
    }
    else {
        cout << "NO";
    };


}
