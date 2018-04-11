#include <iostream>
#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    if (n == 1 || (n % 2 == 0 && n != 2)) {
            puts("NO");
    }
    else if (n == 2) {
            puts("YES");
    }
    else {
        i = 3;
        for (i = 3; (i * i <= n) && (n % i != 0); i += 2) {};
        if (n % i != 0) {
                puts("YES");
        }
        else {
                puts("NO");
        };
    };
    return 0;
}
