#include <iostream>
#include <string.h>

using namespace std;

void foo(int a, float b, float g)
{
    cout << "a, b=0";
}

void foo(char c1, int c2)
{
    cout << "c1 c2" << c2;
}


int main()
{
    cout << 2 << endl;
    foo('a' + 1, false);
    int m = 5;
    int n = 5;

    for(int i = 0; i < n; ++i){
        cout << a[i];
    }
   /* char s5[] = ".xt.ghflk";
    char *p = strtok (s5, "t");
    while (p != NULL)
  {
      cout << p << endl;
      p = strtok (NULL, "t");
  }

  char line[1000];
  cin.getline(line, 1000);*/
    /*char k[] = "123\0asfjdfl";
    char *pl;
    for(int i = 0; k[i] != 0; ++i){

    }
    if (k == 0) pl = k[i];
    cout << pl;*/
    return 0;
}
