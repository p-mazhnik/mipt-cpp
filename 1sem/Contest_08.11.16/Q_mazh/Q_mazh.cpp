#include <iostream>
#include <string.h>

#define SIZE 255

using namespace std;

int main()
{
    char *s = new char[SIZE];
    char *s2 = new char[SIZE];
    cin.getline(s, SIZE);
    for (int i = 0, j = 0, k = 0; s[i] != '\0'; ++i){ //k подсчитывает пробелы
        if (s[i] == ' ') {
            if (i == 0 || s[i + 1] == '\0') { // проверка условий 1 и 2
                k = 1;
            }
            if (k == 0) {
                s2[j] = s[i];
                ++j;
                k = 1;
            }
            s2[j] = '\0';
        }
        else {
            s2[j] = s[i];
            ++j;
            k = 0;
            s2[j] = '\0';
        }
    }
    cout << s2 << endl;
    delete []s2;
    delete []s;
    return 0;
}
