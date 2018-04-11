#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int *copy_array(int *old, int old_n, int new_n)
{
    int *b = new int[new_n];
    if (new_n == old_n + 1){
        for (int i = 0; i < old_n; ++i){
            b[i] = old[i];
        };
    }
    if (new_n == old_n - 1){
        for (int i = 0; i < old_n - 1; ++i){
            b[i] = old[i + 1];
        };
    }
    delete []old;
    return b;
}

void print_array(int *a, int n) // вывод массива длины n на экран
{
    for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
    };
    cout << endl << endl;
}

void rand_array(int *a, int n) // заполнение массива длины n случайными числами от 1 до longer
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % (10 + 1);
    };
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    rand_array(a, n);
    print_array(a, n);
    char *s = new char[5];
    char s1[] = "push";
    char s2[] = "pull";
    char exit[] = "exit";
    while (strcmp(s, exit) != 0) {
        cin >> s;
        if (strcmp(s, s1) == 0){
            a = copy_array(a, n, n + 1);
            cin >> a[n];
            n = n + 1;
            print_array(a, n);
        }
        if (strcmp(s, s2) == 0){
            a = copy_array(a, n, n - 1);
            n = n - 1;
            print_array(a, n);
        }
    }
    delete []s;
    delete []a;
    return 0;
}
