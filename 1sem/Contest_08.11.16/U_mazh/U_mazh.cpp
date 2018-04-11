#include <iostream>
#include <string.h>

#define SIZE 100000

using namespace std;

int main()
{
    char *s = new char[SIZE];
    cin.getline(s, SIZE);
    if (s[0] == '\0') {
        cout << "YES";
    }
    else if (s[0] == ')') {
        cout << "NO";
    }
    else {
        int j1 = 0;
        int j2 = 0;
        for (int i = 0; s[i] != '\0' && j1 >= j2;){
            while (s[i] == '(') {
                ++i;
                ++j1;
            }
            while (s[i] == ')') {
                ++i;
                ++j2;
            }
        }
            if (j1 == j2) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
    }
    delete []s;
    return 0;
}
//mazhnik
