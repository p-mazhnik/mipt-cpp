#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    int x;
    int y;
};

struct point_array
{
    int n = 3;
    point p[3];
    float l[3];
};

void scan_point(point_array &a)
{
    for(int i = 0; i < 3; ++i){
        cin >> a.p[i].x >> a.p[i].y;
    }
}

void length(point_array &a)
{
    for (int i = 0; i < a.n; ++i){
        a.l[i] = sqrt(a.p[i].x * a.p[i].x + a.p[i].y * a.p[i].y);
    }
}

bool cmp(int, int)
{

}

void selection_sort(point_array &a, bool (cmp)()) // сортировка выбора
{
    for (int i = 0; i < a.n - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < a.n; ++j) {
            if (a.l[j] < a.l[imin]) {
                imin = j;
            };
        };
        int k = a[i];
        a.l[i] = a[imin];
        a[imin] = k;
    }
}

void print_point (point_array a)
{
    for (int i = 0; i < a.n; ++i){
        cout << a.p[i].x << ' ' << a.p[i].y << endl;
    }
}

int main()
{
    point_array a;
    scan_point(a);
    sort_point(a);
    print_point(a);
    return 0;
}
