#include <iostream>
#include <string.h>

#define SIZE 255

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
    char *s1 = new char[SIZE];
    cin.getline(s1, SIZE);
    char *s2 = new char[SIZE];
    cin.getline(s2, SIZE);
    insert_sort(s1);
    insert_sort(s2);
    if(strcmp(s1, s2) == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    delete []s1;
    delete []s2;
    return 0;
}
