#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

void lchar(int i, char **s, int **l);

void input (char **s, int i) // ввод из файла Input1.txt
{
    char istring[6];
    char string2[] = ".txt";
    itoa(i + 1, istring, 10);
    fstream f;
    f.open(strcat(istring, string2), ios::in);
    //cout << strcat(istring, string2) << ' ';
    //cout << istring << ' ';
    f.getline(s[i], 1000);
    f.close();
}

void print_array2(char **a, int n) // вывод двумерного массива c n строками и m столбцами на экран
{
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
}

int main()
{
    char **s = new char *[6];
    for(int i = 0; i < 6; i++){
        s[i] = new char[1000];
        input(s, i);
    }
    int **l = new int *[6];  ///в этом массиве будем хранить кол-во повторений букв латинского алфавита в строке (Прописные и строчные буквы различаются).
    ///(на j-м месте строки стоит кол-во повторений j-го символа)
    for(int i = 0; i < 6; i++){
        l[i] = new int[58];
    }
    int h[5] = {0};
    int hmax = 0;
    int i0 = 0;
    print_array2(s, 6);
    for(int i = 0; i < 6; ++i){ ///заполняем l;
        lchar(i, s, l);
    }
    for(int i = 0; i < 5; ++i){
        int j = 0;
        while(l[5][j] != 0 && l[i][j] == 0 && j < 58) {
            --h[i];
            ++j;
        }
        while((l[i][j] >= l[5][j] - 5) && (l[i][j] <= l[5][j] + 5) && j < 58) { ///засчитываем символ, если кол-во его повторений в i-ой строке лежит в диапазоне +- 5 от кол-ва повторений в 6-ой строке
            ++j;
            if (l[5][j] != 0 && l[i][j] != 0) { ///пропускаем отсутствующие символы
                ++h[i];
            }
        }
        if (h[i] > hmax){
            hmax = h[i];
            i0 = i + 1;
        }
    }
    cout << i0;
    for(int i = 1; i < 7; i++){
        delete []l[i];
    }
    for(int i = 1; i < 7; i++){
        delete []s[i];
    }
    delete []s;
    delete []l;
    char s5[] = ".xt.ghflk";
    char *p = strtok (s5, "t");
    while (p != NULL)
  {
      cout << p << endl;
      p = strtok (NULL, "t");
  }
    return 0;
}

void lchar(int i, char **s, int **l)
{
    char a = 'A';
    for(int k = 0; k < 58; ++a, ++k){
        l[i][k] = 0;
        for(int j = 0; s[i][j] != 0; ++j){
            if(a == s[i][j]) {
                l[i][k]++;
            }
        }
    }
}
