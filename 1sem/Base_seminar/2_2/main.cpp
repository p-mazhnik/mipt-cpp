#include <iostream>
#include <stdio.h>


int main()
{
    float a, b, c, i, y;
    std::cin >> a >> b >> c;
    if (a < 0 && c != 0){
        for(i = -1; i <= 1; i += 0.5){
            y = a* i*i + b* i + c;
            printf("%.1f %10.1f\n", i, y);
        };
    }
    else if (a > 0 && c == 0) {
        for(i = -1; i <= 1; i += 0.5){
            if (i == 0) {
                printf("%.1f %10s\n", i, "#!`###");
            }
            else {
            y = -a / i;
            printf("%.1f %10.1f\n", i, y);
            };
        };
    }
    else {
        for(i = -1; i <= 1; i += 0.5){
            y = a * (i + c);
            printf("%.1f %10.1f\n", i, y);
        };
    };
}
