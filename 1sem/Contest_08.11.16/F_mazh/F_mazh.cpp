#include <iostream>

using namespace std;

void filling_array(int *a, int *k, int n) // заполнение массива длины n
{
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k[i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *k = new int[n]; ///создаем массив k, в котором на месте k[j] будем писать количества повторений элемента a[j] в массиве а;
    int l = 0;
    filling_array(a, k, n);
    for (int j = 0; j < n; ++j){
        while (j < n && k[j] != 0) {
            ++j;
        }
        if(j < n) {
            for (int i = j + 1; i < n; ++i){
                while (i < n && k[i] != 0) {
                    ++i;
                }
                if(i < n){
                    if (a[j] == a[i]) {
                        k[j]++;
                        k[i]++;
                    }
                }
            }
            if ((k[j] > k[l]) || (k[j] == k[l] && a[j] < a[l])) {
                l = j;
            }
        }
    }
    cout << a[l];
    delete []a;
    delete []k;
    return 0;
}
//mazhnik
