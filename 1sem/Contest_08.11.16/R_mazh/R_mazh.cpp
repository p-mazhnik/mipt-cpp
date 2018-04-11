#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char *s = new char[200];
    char *s2 = new char[200];
    cin.getline(s, 200);
    for (int i = 0, j = 0; s[i] != '\0'; ++i){
        if (s[i] == '@') {
            j = 0;
            s2[j] = '\0';
            continue;
        }
        if (s[i] == '#') {
            --j;
            if (j < 0) {
                j = 0;
            }
            s2[j] = '\0';
            continue;
        }
        else {
            s2[j] = s[i];
            ++j;
            s2[j] = '\0';
        }
    }
    cout << s2;
    delete []s2;
    delete []s;
    return 0;
}
