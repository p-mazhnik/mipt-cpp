#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void printArray(int a[100][100], int n, int m)
{
    int max_n_m = a[0][0];
    for (int i = 0; i < n; i++) {
            int max_m = a[i][0];
            for (int j = 0; j < m; ++j) {
                printf("%5d ", a[i][j]);
                if (a[i][j] >= max_m) {
                    max_m = a[i][j];
                    a[i][n] = max_m;
                };
            };
            printf("%10d\n", a[i][n]);
    };
    printf("\n\n");
    for (int j = 0; j < m; j++) {
            int max_n = a[0][j];
            for (int i = 0; i < n; ++i) {
                if (a[i][j] >= max_n) {
                    max_n = a[i][j];
                };
            };
            printf("%5d ", max_n);
    };
    for (int i = 0, j = 0; (i < n) && (j < m); ++i, ++j) {
        if (a[i][j] >= max_n_m) {
            max_n_m = a[i][j];
        };
    };
    printf("%10d\n", max_n_m);
    return;
}

void randArray(int a[100][100], int n, int m)
{
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = rand();
            };
    };
    printArray(a, n, m);
    return;
}

int main()
{
    int a[100][100];
    int n, m;
    std::cin >> n >> m;
    randArray(a, n, m);
    return 0;
}
