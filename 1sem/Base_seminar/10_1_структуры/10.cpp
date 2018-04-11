#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
enum colour
{
    RED, GREEN, BLUE, BLACK
};

struct int_array
{
    int * values;
    int length;
};

sort (int_array a);

struct person
{
    person *mother;
    person *father;
};

/*person p;
cout << p.mother -> name;
or
cout << (*p.mother).name;*/
