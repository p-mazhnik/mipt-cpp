#include <iostream>
#include <string.h>

#define SIZE 1000

using namespace std;

void insert_sort (char *a) // сортировка вставками
{
    for (int i = 1; a[i] != '\0'; ++i) {
        char k = a[i];
        int j = i - 1;
        while (j >= 0 && k > a[j]) {
            a[j + 1] = a[j];
            j--;
        };
        a[j + 1] = k;
    }
}

int main()
{
    char *s = new char[SIZE];
    cin.getline(s, SIZE);
    insert_sort(s);
    cout << s;
    delete []s;
    return 0;
}
