#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int p = 9;
    int *q;
    q = &p;
    scanf("%i", q);
    printf("%d", p);
    return 0;
}
