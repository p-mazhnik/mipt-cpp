#include <iostream>

using namespace std;

int kolnul(int n, int i, int j)
{
 //i -счётчик 2
 //j -счётчик 5
    int k, p;
    for(p = n; p!=1; --p) {
        for(k = p; k%2==0 || k%5==0;) {
            if (k%2==0){
                ++i;
                k = k/2;
            };
            if (k%5==0 && k%2!=0) {
                ++j;
                k = k/5;
            };
        };
    };
    if ( i > j ) return j;
    else return i;
}

int main()
{
    int n;
    cin >> n;
    cout << kolnul(n,0,0) << endl;
    return 0;
}
/*
1_1. Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * … * n.
n ≤ 1000.
in 25
out 6
*/
