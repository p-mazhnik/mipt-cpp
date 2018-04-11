#include <iostream>
#include <fstream>

using namespace std;

void input (char **s, int i) // גגמה טח פאיכא Input1.txt
{
    fstream f;
    if(i == 0) {
        f.open("1.txt", ios::in);
    }
    if(i == 1) {
        f.open("2.txt", ios::in);
    }
    if(i == 2) {
        f.open("3.txt", ios::in);
    }
    if(i == 3) {
        f.open("4.txt", ios::in);
    }
    if(i == 4) {
        f.open("5.txt", ios::in);
    }
    if(i == 5) {
        f.open("6.txt", ios::in);
    }
    f.getline(s[i], 1000);
    f.close();
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
