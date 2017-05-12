//
// Created by pavel on 09.05.2017.
//

#include <iostream>
#include <set>

int main() {
    std::string s = "0";
    std::set<std::string> set;
    for(int i = 0; s != "#"; ++i){
        std::cin >> s;
        char str[100];
        std::string str2;
        if(s == "+"){
            std::cin.getline(str, 100);
            str2 = str;
            set.insert(str2);
        }
        if(s == "-"){
            std::cin.getline(str, 100);
            str2 = str;
            set.erase(str2);
        }
        if(s == "?"){
            std::cin.getline(str, 100);
            str2 = str;
            std::set<std::string>::iterator it = set.find(str2);
            std::cout << (it == set.end() ? "NO" : "YES") << std::endl;
        }
    }
}