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

int left_f(int i)
{
    return 2 * i + 1;
}

int right_f(int i)
{
    return 2 * i + 2;
}

void sift_down(int *a, int n, int index)
{
    int left = left_f(index);
    int right = right_f(index);
    int imax = index;
    if (left < n && a[left] > a[imax]) {
        imax = left;
    }
    if (right < n && a[right] > a[imax]){
        imax = right;
    }
    if (index != imax){
        swap(a[index], a[imax]);
        sift_down(a, n, imax);
    }
}

void build_heap(int *a, int n)
{
    for(int i = (n - 1) / 2; i >= 0; --i){
        sift_down (a, n ,i);
    }
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
            build_heap(a, n);
            //print_array(a, n);
        }
        if (strcmp(s, s2) == 0){
            cout << a[0] << endl;
            a = copy_array(a, n, n - 1);
            n = n - 1;
            //print_array(a, n);
        }
    }
    delete []s;
    delete []a;
    return 0;
}
