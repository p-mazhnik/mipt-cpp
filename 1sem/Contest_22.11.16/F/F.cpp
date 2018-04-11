#include <iostream>

using namespace std;

int main()
{
    char s[100000];
    cin.getline(s, 100001);
    int b = 0;
    int a = 0;
    for(int i = 0; s[i] != 0; ++i){
        if(s[i] == '('){
            ++a;
        }
        else{
            if(a == 0){
                ++b;
            }
            else {
                --a;
            }
        }
    }
    cout << b + a << endl;
    return 0;
}
