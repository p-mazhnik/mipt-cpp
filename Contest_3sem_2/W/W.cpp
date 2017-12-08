//
// Created by pavel on 06.12.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<long long> Z_function(std::string str) {
    std::vector<long long> z (str.length());
    z[0] = str.length();
    for (long long i = 1, l = 0, r = 0; i < str.length(); ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < str.length() && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long N;
    std::cin >> N;
    std::string input;
    std::cin >> input;

    std::string new_str = input + "#";
    std::reverse(input.begin(), input.end());
    new_str += input;
    std::vector<long long> z = Z_function(new_str);
    //std::cout << new_str << '\n';
	for (int i = z.size() - 1 ; i != input.size(); --i) {
		std::cout << z[i] << ' ';
	}
    return 0;
}
/*
 *
Дана строка S, состоящая из N символов. Определим функцию A(i) от первых i символов этой сроки следующим образом:

A(i) = максимально возможному k, что равны следующие строки:

S[1]+S[2]+S[3]+…+S[k]

S[i]+S[i–1]+S[i–2]+…+S[i–k+1]

где S[i] – i-ый символ строки S, а знак + означает, что символы записываются в строчку непосредственно друг за другом.

Напишите программу, которая вычислит значения функции A для заданной строчки для всех возможных значений i от 1 до N.
Формат входных данных
В первой строке входного файла записано одно число N. 1 ≤ N ≤ 200000. Во второй строке записана строка длиной N символов,
 состоящая только из больших и/или маленьких латинских букв.
Формат результата
В выходной файл выведите N чисел — значения функции A(1), A(2), … A(N).
Примеры
Входные данные	Результат работы
5
aabaa
1 2 0 1 5

 */