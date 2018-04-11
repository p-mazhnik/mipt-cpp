#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    int i = 0;
    fstream k;
    k.open("Input.txt", ios::in);
    while (!k.eof()) { // eof = end of file
        k >> n;
    }
    k.close();
    cout << n;
    while (i <= n) {
        k.open ("Output.txt", ios::app);
        k << i << endl;
        k.close();
        ++i;
    };
    return 0;
}
