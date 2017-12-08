//
// Created by pavel on 06.12.2017.
//
#include <iostream>
#include <vector>
#include <algorithm>

int prefix_function (std::string &str) {
    int max_pi = 0;
    std::vector<int> pi (str.length());
    for (int i = 1; i < str.length(); ++i) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) {
            ++j;
        }
        pi[i] = j;
        if(j > max_pi){
            max_pi = j;
        }
    }
    return max_pi;
}

int main(){
    std::string text;
    std::string sub_str;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> text;
    std::string current;
    std::string reverse_current;
    long long count_substr = 0;

    for (int i = 0; i < text.size(); ++i) {
        current += text[i];
        reverse_current = current;
        std::reverse(reverse_current.begin(), reverse_current.end());
        count_substr += current.size() - prefix_function(reverse_current);
    }
    printf("%lli", count_substr);
    return 0;
}

/*
 * Формат входных данных
На входе дана непустая строка, полученная Васей. Строка состоит только из строчных латинских символов.
Ее длина не превосходит 5000 символов.
Формат результата
Выведите количество различных подстрок этой строки.
Примеры
Входные данные	Результат работы
aaba
8

 */