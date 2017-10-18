//
// Created by pavel on 03.10.2017.
//

#include <iostream>
#include <vector>

using namespace std;

void update(vector<vector<long long int> > &t, int x, int y, int d){
    for(int i = x; i < t[0].size(); i = (i | (i + 1)))
        for(int j = y; j < t[0].size(); j = (j | (j + 1)))
            t[i][j] += d;
}

long long int sum(vector<vector<long long int> > &t, int x, int y){
    long long int res = 0;
    for(int i = x; i >= 0; i = ((i & (i + 1)) - 1))
        for(int j = y; j >= 0; j = ((j & (j + 1)) - 1))
            res += t[i][j];
    return res;
}
int main()
{
    long long int n, k;
    string cmd;
    string cmd1 = "ADD";
    string cmd2 = "GET";
    vector<vector<long long int> > t;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        t.push_back(vector<long long int>(n));
    }
    while(k != 0){
        cin >> cmd;
        if(cmd == cmd1){
            int x, y;
            cin >> x >> y;
            update(t, x - 1, y - 1, 1);
        }
        if(cmd == cmd2){
            int x_min, y_min, x_max, y_max;
            int x_1, y_1, x_2, y_2;
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            x_max = max(x_1, x_2);
            x_min = min(x_1, x_2);
            y_min = min(y_1, y_2);
            y_max = max(y_1, y_2);
            cout << (sum(t, x_max - 1, y_max - 1) - sum(t, x_max - 1, y_min - 2) - sum(t, x_min - 2, y_max - 1) + sum(t, x_min - 2, y_min - 2)) << endl;
        }
        --k;
    }
    return 0;
}
