#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>


using namespace std;

void input (char *s, char *d, int &k) // גגמה טח פאיכא Input.txt
{
    int i = 0;
    int j = 0;
    fstream f;
    f.open("Input.txt", ios::in);
    while (!f.eof()) { // eof = end of file
        f.getline(s, 100);
        for(j = 0; strstr(s, d) != 0 ; j++){
            s = strstr(s, d) + k-1;
        }
        i+=j;
    }
    f.close();
    cout << i;
}

int main()
{
    int k;
    cin >> k;
    int n = 100;
    char *s = new char[n];
    char *d = new char[k];
    cin.getline(d, k);
    input(s, d, k);
    delete []s;
    delete []d;
    return 0;
}
