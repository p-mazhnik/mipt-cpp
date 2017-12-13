//
// Created by pavel on 13.12.2017.
//

#include <iostream>
#include <vector>

std::vector<int> Z_function(std::string str) {
    std::vector<int> z (str.length());
    z[0] = str.length();
    for (int i = 1, l = 0, r = 0; i < str.length(); ++i) {
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
    std::string first_word;
    std::string last_word;
    std::string str;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> first_word;
    std::cin >> last_word;
    str = first_word + "#" + last_word;
    std::vector<std::string> answer_str;
    std::vector<int> z = Z_function(str);
    int current_size = z.size();
    int answer_size = 0;
    for (int i = z.size() - 1; i > first_word.size(); --i) {
        if(z[i] + i >= current_size){
            int delta = z[i] + i - current_size;
            std::string current_prefix;
            for (int j = i; j < current_size; ++j) {
                current_prefix += str[j];
                answer_size += 1;
            }
            answer_str.push_back(current_prefix);
            current_size -= (z[i] - delta);
        }
        //std::cout << z[i] << ' ';
    }
    if(answer_size == last_word.size()){
        std::cout << "No\n";
        for (int i = answer_str.size() - 1; i >= 0; --i) {
            std::cout << answer_str[i] << ' ';
        }
    } else{
        std::cout << "Yes";
    }
    return 0;
}

/*
 * Джек недавно прочитал на заборе занимательное и новое для него слово. Оно настолько понравилось Джеку,
 * что он захотел сам придумать ещё какое-нибудь занимательное слово. Но только ничего у него не вышло —
 * все придуманные им слова состояли из префиксов исходного слова и поэтому не приносили радости.
 * Он стал придумывать всё более и более длинные слова, но ни одно из них не было оригинальным…

И вот настало время Джеку сказать своё последнее слово.
Формат входных данных
Первая строка содержит занимательное слово, которое было написано на заборе.
 Вторая строка содержит последнее слово Джека. Длины слов не превосходят 75000,
 слова непустые и состоят из строчных латинских букв.
Формат результата
Если Джек так ничего и не придумал своего, выведите первой строкой «No». В этом случае покажите Джеку,
 как разбить его последнее слово на несколько частей, каждая из которых является исходным словом или
 его непустым префиксом — выведите все эти части во второй строке, разделяя их пробелом.
 Если же такого разбиения нет, и последнее слово было за Джеком, выведите единственной строкой «Yes».

Примеры
Входные данные	Результат работы
abracadabra
abrabracada
No
abr abracad a

abracadabra
arbadacarba
Yes

 */