#include <iostream>

using namespace std;

int main()
{
    float x, y;
    bool in_okr1, in_okr2, down_line1, right_line2, up_line3, down_line4, left_line5, up_line6;
    cin >> x >> y;
    in_okr1 = (x * x + y * y <= 1) && (x >= 0);
    down_line1 = (y <= 1) && (x <= 0);
    up_line3 = (y >= -1) && (x <= 0);
    right_line2 = x >= -2;
    in_okr2 = (y*y + (x + 1) * (x + 1) <= 4) && (x <= -1);
    down_line4 = (y <= 2) && (x >= -1);
    left_line5 = x <= 2;
    up_line6 = (y >= -2) && (x >= -1);
    if (in_okr1 || (down_line1 && up_line3 && right_line2)) {
            cout << 20;
    }
    else if (in_okr2 || (down_line4 && left_line5 && up_line6)) {
            cout << 10;
    }
    else {
            cout << 0;
    };
    return 0;
}
