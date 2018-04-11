#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int info;
    int num;
};

void print_array2(int **a, int n, int m) // вывод двумерного массива c n строками и m столбцами на экран
{
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
               printf("%5d ", a[i][j]);
        }
        cout << endl;
    };
    cout << endl << endl;
}

void print_array(Node *a, int n)
{
    for(int i = 0; i < n; ++i){
        cout << a[i].info << ' ';
    }
    //cout << endl;
}

void bubble_sort(Node *a, int n) // сортировка пузырьком
{
    for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < n - 1 - i; ++j) {
           if (a[j].info > a[j + 1].info) {
               int k = a[j].info;
               a[j].info = a[j + 1].info;
               a[j + 1].info = k;
           };
       };
    };
}

void print_number(int **c, Node *a1, Node *a, Node *b, int i, int j, int q)
{
    if (i == 0 || j == 0){
        return;
    }
    if (a[i - 1].info == b[j - 1].info){
        a1[q].info = a[i - 1].info;
        a1[q].num = a[i - 1].num;
        --q;
        print_number(c, a1, a, b, i - 1, j - 1, q);
    }
    else{
        if (c[i][j] == c[i - 1][j]){
            print_number(c, a1, a, b, i - 1, j, q);
        }
        else{
            print_number(c, a1, a, b, i, j - 1, q);
        }
    }
}

int filling(Node *a1, Node *a, Node *b, int n, int m)
{
    int **c = new int *[n + 1];
    for(int i = 0; i <= n; ++i){
        c[i] = new int[m + 1];
    }
    for(int i = 0; i < n + 1; ++i){
        c[i][0] = 0;
    }
    for(int j = 0; j < m + 1; ++j){
        c[0][j] = 0;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i - 1].info == b[j - 1].info){
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else{
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    int k = c[n][m];
    //print_array2(c, n + 1, m + 1);
    print_number(c, a1, a, b, n, m, k - 1);
    for(int i = 0; i < n; ++i){
        delete []c[i];
    }
    delete []c;
    return k;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Node *a = new Node[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i].info;
        a[i].num = i;
    }
   // bubble_sort(a, n);
    Node *b = new Node[m];
    for(int i = 0; i < m; ++i){
        cin >> b[i].info;
        b[i].num = i;
    }
   // bubble_sort(b, m);
    Node *d = new Node[k];
    for(int i = 0; i < k; ++i){
        cin >> d[i].info;
        d[i].num = i;
    }
   // bubble_sort(d, k);
    Node *I = new Node[min(m, n)];
    int I_size;
    I_size = filling(I, a, b, n, m);
    Node *II = new Node[min(I_size, k)];
    int II_size;
    II_size = filling(II, I, d, I_size, k);
    /*Node *III = new Node[min(I_size, II_size)];
    int III_size;
    III_size = filling(III, I, II, I_size, II_size);*/
    /*cout << I_size << endl;
    print_array(I, I_size);
    cout << II_size << endl;*/
    printf("%d\n", II_size);
    print_array(II, II_size);
    delete []a;
    delete []b;
    delete []d;
    delete []I;
    delete []II;
    //delete []III;
    return 0;
}
/*
8
2 0 -1 3 2 4 0 3
*/
