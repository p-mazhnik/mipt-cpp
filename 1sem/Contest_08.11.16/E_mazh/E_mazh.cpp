#include <iostream>

using namespace std;

int count_divisors(int n)
{
    int div = 0;
    for(int i = 2; i*i <= n; ++i){
        if (n % i == 0) {
            if (i == n / i) {
                div += 1;
            }
            else {
                div += 2;
            }
        }
    }
    return div;
}

int main()
{
    int n;
    cin >> n;
    cout << count_divisors(n);
    return 0;
}
//mazhnik
