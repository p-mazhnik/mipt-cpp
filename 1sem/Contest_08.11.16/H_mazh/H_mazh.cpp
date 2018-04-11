#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int[n + 1];
    for(int i = 1; i <= n; ++i){
        a[i] = i;
    }
    for(int i = 1, j = 1; j / k <= n; ){
        while (a[i] != 0){
            if(j % k == 0){
                if (j / k == n){
                    cout << a[i];
                }
                else {
                    a[i] = 0;
                }
            }
            ++j;
            ++i;
            if (i == n + 1) {
                i = 1;
            }
        }
        while (a[i] == 0){
            ++i;
            if (i == n + 1) {
                i = 1;
            }
        }
    }
    delete []a;
    return 0;
}
