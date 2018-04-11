#include <iostream>

using namespace std;

int main()
{
    long long int a, b;
    long long int j = 0;
    long long int i = 0;
    cin >> a >> b;
    for (i = 0; i*i*i*i*i*i < a; ++i);
    for (j = 0; (j + i)*(j + i)*(j + i)*(j + i)*(j + i)*(j + i) <= b; ++j);
    cout << j;
    return 0;
}
//mazhnik
/*
1) A ≤ N ≤ B.
2) c^2 = N
3) d^3 = N c и d  - целые
*/

    /*for (int i = a; i <= b; ++i){
        for (int j = 0; pow(j, 6) <= i; ++j){
            if (pow(j, 6) == i) {
                n++;
                break;
            }
        }
    }*/
