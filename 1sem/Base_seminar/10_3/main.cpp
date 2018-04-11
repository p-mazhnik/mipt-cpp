#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    int x;
    int y;
};

struct broken_line
{
    int n = 3;
    point p[3];
};

int length(broken_line a)
{
    int l = 0;
    for (int i = 0; i < a.n - 1; ++i){
        l += sqrt((a.p[i].x - a.p[i + 1].x) * (a.p[i].x - a.p[i + 1].x) + (a.p[i].y - a.p[i + 1].y) * (a.p[i].y - a.p[i + 1].y));
    }
    return l;
}

int main()
{
    broken_line a;
    for(int i = 0; i < a.n; ++i){
        cin >> a.p[i].x >> a.p[i].y;
    }
    cout << length(a) << endl;
    return 0;
}
