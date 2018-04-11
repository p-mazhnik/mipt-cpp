#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 0;
    for (int i1 = 0; i1 < 10; ++i1) {
        for(int i4 = 0; i4 < 10; ++i4){
            while(i4 < 10 && (n - i1 - i4 > 9 || n - i1 - i4 < 0)) {
                ++i4;
            }
            if(i4 < 10){
                for(int i2 = 0; i2 < 10; ++i2){
                    while(i2 < 10 && (n - i1 - i2 > 9 || n - i1 - i2 < 0)) {
                        ++i2;
                    }
                    if(i2 < 10){
                        for (int i3 = 0; i3 < 10; ++i3){
                            while(i3 < 10 && (n - i4 - i3 > 9 || n - i4 - i3 < 0 || n - i2 - i3 > 9 || n - i2 - i3 < 0 || i1 + i2 + i3 + i4 - n > 9 || i1 + i2 + i3 + i4 - n < 0)) {
                                ++i3;
                            }
                            if (i3 < 10 && !(n - i4 - i3 > 9 || n - i4 - i3 < 0 || n - i2 - i3 > 9 || n - i2 - i3 < 0 || i1 + i2 + i3 + i4 - n > 9 || i1 + i2 + i3 + i4 - n < 0)) {
                                ++k;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << k;
    return 0;
}
//mazhnik
