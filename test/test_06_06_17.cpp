//
// Created by pavel on 06.06.2017.
//

#include <iostream>
// библиотека манипулирования вводом/выводом
#include <iomanip>
// заголовочный файл математических функций
#include <cmath>
using namespace std;

void type()
{
    cout << "     data type      "   << "byte"                      << "      "    << "    max value  " << endl // заголовки столбцов
         << "bool               =  " << sizeof(bool)                << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных bool*/                           << (pow(2,sizeof(bool) * 8.0) - 1)               << endl
         << "char               =  " << sizeof(char)                << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных char*/                           << (pow(2,sizeof(char) * 8.0) - 1)               << endl
         << "short int          =  " << sizeof(short int)           << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных short int*/                      << (pow(2,sizeof(short int) * 8.0 - 1) - 1)      << endl
         << "unsigned short int =  " << sizeof(unsigned short int)  << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных unsigned short int*/             << (pow(2,sizeof(unsigned short int) * 8.0) - 1) << endl
         << "int                =  " << sizeof(int)                 << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных int*/                            << (pow(2,sizeof(int) * 8.0 - 1) - 1)            << endl
         << "unsigned int       =  " << sizeof(unsigned int)        << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных unsigned int*/                   << (pow(2,sizeof(unsigned int) * 8.0) - 1)       << endl
         << "long int           =  " << sizeof(long int)            << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных long int*/                       << (pow(2,sizeof(long int) * 8.0 - 1) - 1)       << endl
         << "long long int      =  " << sizeof(long long int)           << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных long long*/                      << (pow(2,sizeof(long long int) * 8.0 - 1) - 1)      << endl
         << "unsigned long int  =  " << sizeof(unsigned long int)   << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных undigned long int*/              << (pow(2,sizeof(unsigned long int) * 8.0) - 1)  << endl
         << "float              =  " << sizeof(float)               << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных float*/                          << (pow(2,sizeof(float) * 8.0 - 1) - 1)          << endl
         << "double             =  " << sizeof(double)              << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных double*/                         << (pow(2,sizeof(double) * 8.0 - 1) - 1)         << endl
         << "long double        =  " << sizeof(long double)         << "         " << fixed << setprecision(2)
         /*вычисляем максимальное значение для типа данных long double*/                    << (pow(2,sizeof(long double) * 8.0 - 1) - 1)    << endl;
}

class A{
public:
    static int i;
    int x;
    void f(){
        ++x;
        ++i;
        std::cout << x << ' ' << i;
    }
};

int A::i = 0;

int main(){
    A a;
    a.f();
    return 0;
}

void bubble_sort(int *a, int n) // сортировка пузырьком
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                int k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            };
        };
    };
}

void selection_sort(int *a, int n) // сортировка выбора
{
    for (int i = 0; i < n - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[imin]) {
                imin = j;
            };
        };
        int k = a[i];
        a[i] = a[imin];
        a[imin] = k;
    }
}

void insert_sort (int *a, int n) // сортировка вставками
{
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && k < a[j]) {
            a[j + 1] = a[j];
            j--;
        };
        a[j + 1] = k;
    }
}