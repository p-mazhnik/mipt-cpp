#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, l, m, n;
    cin >> k >> l >> m >> n;
    if ( k==m || l==n || ((k+l)==(m+n)) || ((l-k)==(n-m)) )
    cout << "YES";
    else cout << "NO";
    return 0;
}
