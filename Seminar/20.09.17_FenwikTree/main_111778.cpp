#include <iostream>
#include <vector>

using namespace std;

void update(vector<vector<long long int> >& t, int x, int y, int delta){
    for(int i = x; i < t[0].size(); i = (i | (i + 1)))
        for(int j = y; j < t[0].size(); j = (j | (j + 1)))
            t[i][j] += delta;
}

long long int sum(vector<vector<long long int> >& t, int x, int y){
    long long int res = 0;
    for(int i = x; i >= 0; i = ((i & (i + 1)) - 1))
        for(int j = y; j >= 0; j = ((j & (j + 1)) - 1))
            res += t[i][j];
    return res;
}
int main()
{
    int S;
    char com;
    vector<vector<long long int> > t;
    cin >> com;
    while(com != '3'){
        if(com == '0'){
            cin >> S;
            for(int i = 0; i < S; ++i){
                t.push_back(vector<long long int>(S));
            }
        }
        if(com == '1'){
            int X, Y, A;
            cin >> X >> Y >> A;
            update(t, X, Y, A);
        }
        if(com == '2'){
            int L, B, R, T;
            cin >> L >> B >> R >> T;
            cout << (sum(t, R, T) - sum(t, R, B - 1) - sum(t, L - 1, T) + sum(t, L - 1, B - 1)) << endl;
        }
        cin >> com;
    }
    return 0;
}
