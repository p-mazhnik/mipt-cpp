#include <iostream>
#include "array.cpp"

using namespace std;

void method1 (const int_array a)
{
    a.print();
}

void method2 (int_array a)
{
    a.print();
}

void method3 (int_array &a)
{
    a.print();
}

void method4 (const int_array &a)
{
    a.print();
}

void method5 (const int_array *a)
{
    a->print();
}

void method6 (int_array *a)
{
    a->print();
}

int main()
{
    int_array a(5);
    int_array b(5);
    a.set(4, 91);
    //a.sub_array(3, 4).print();
    a.resize(8);
    a.print();
    cout << '\n';
    a.revert().print();
    cout << '\n';
    (a + b + 5).print();
    return 0;
}
