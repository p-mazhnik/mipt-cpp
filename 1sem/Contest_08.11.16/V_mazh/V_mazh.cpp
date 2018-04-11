#include <iostream>

using namespace std;

int main()
{
    char *s = new char[256];
    cin.getline(s, 256);
    int i;
    if (s[1] == '\0'){
        cout << 0;
    }
    else {
        for (i = 0; s[i] != '\0' && s[i - 1] != s[i + 1] && s[i - 1] != s[i]; ++i);
        if (s[i] == '\0'){
            cout << 0;
        }
        else {
            if (s[i - 1] == s[i + 1]){
                cout << s[i - 1] << s[i] << s[i + 1];
            }
            else {
                cout << s[i - 1] << s[i];
            }
        }
    }
    delete []s;
    return 0;
}
//mazhnik
