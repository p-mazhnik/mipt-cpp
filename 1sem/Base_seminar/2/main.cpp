#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, x, x1, x2, d;
    std::cin >> a >> b >> c;
    d = b*b - 4 * a * c;
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    if (a == 0 && b != 0) {
        x=( -c / b );
        printf("%0.2f", x); //линейное уравнение
    }
    else {
        if (d > 0)
            {
            if (x1 > x2) printf("%0.2f %0.2f", x2, x1);
            else printf("%0.2f %0.2f", x1, x2);
            }
        else if (d == 0)
            {
            if (a == 0)
                {
                if (c == 0) printf("БЕСКОНЕЧНО МНОГО РЕШЕНИЙ");
                else printf("НЕТ КОРНЕЙ");
                }
            else printf("%0.2f", x1); //квадратное ур-ние с кратным корнем
            }
        else {printf("НЕТ КОРНЕЙ");};
    };
    return 0;
}
