#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s1[10000];
    char s2[10000];
    cin.getline(s1, sizeof(s1));
    cin.getline(s2, sizeof(s2));
    if (strstr(s2, s1) != 0){
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
