#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    int x;
    int y;
};

int idistance(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << idistance(a, b) << endl;
    return 0;
}
