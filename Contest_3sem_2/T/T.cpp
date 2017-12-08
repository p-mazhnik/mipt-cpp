//
// Created by pavel on 06.12.2017.
//
#include <iostream>
#include <vector>

std::vector<int> prefix_function (std::string str) {
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
    }
    return pi;
}

int main(){
    std::string text;
    std::string sub_str;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> text;
    std::cin >> sub_str;
    std::string new_str = sub_str + "#" + text;
    //std::cout << new_str << '\n';
    std::vector<int> pi = prefix_function(new_str);
    /*for (int i = 0; i < pi.size(); ++i) {
        std::cout << pi[i] << ' ';
    }
    std::cout << '\n';*/
    for (int i = 0; i < pi.size(); ++i) {
        if (pi[i] == sub_str.size()){
            std::cout << i - 2 * pi[i] << ' ';
        }
    }
    return 0;
}