#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int k[10] = {0};
    cin >> a >> b;
    for (int i = a; i <= b; ++i){
        for(int j = i; j != 0; j /= 10){
            ++k[j % 10];
        }
    }
    for(int i = 0; i < 10; ++i){
        cout << k[i] << ' ';
    }
    return 0;
}
