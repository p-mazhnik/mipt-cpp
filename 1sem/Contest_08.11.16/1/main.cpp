#include <iostream>
#include <string.h>

using namespace std;

char *strstr2(char *s, char *s2)
{
    char *s3;
    for (int i = 0, j = 0; s[i] != '\0'; ++i){
        if (s[i] == s2[0]){
            int i0 = i;
            while(s[i] == s2[j] && s2[j] != 0){
                if(s2[j + 1] == '\0'){
                    s3 = s + i0;
                }
                ++i;
                ++j;

            }
        }
        if(s[i + 1] == '\0' && s2[j] != '\0'){
            *s3 = '0';
        }
    }
    return s3;
}

int main()
{
    char *s = new char[101];
    cin.getline(s, 100);
    char *s2 = new char[101];
    cin.getline(s2, 100);
    cout << strstr2(s, s2) << endl;
    cout << strstr(s, s2);
    delete []s;
    delete []s2;
    return 0;
}
