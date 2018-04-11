#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>


using namespace std;

char* input (char *s, char *d) // גגמה טח פאיכא Input.txt
{
    fstream f;
    f.open("Input.txt", ios::in);
    while (!f.eof()) { // eof = end of file
        f.getline(s, 100);
        if (strstr(s, d) != 0) {
            cout << s << endl;
        }
    }
    f.close();
    return s;
}

int main()
{
    int n = 100;
    char *s = new char[n];
    char *d = new char[4];
    cin.getline(d, 4);
    s = input(s, d);
    delete []s;
    delete []d;
    return 0;
}
