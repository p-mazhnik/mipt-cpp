//
// Created by pavel on 09.05.2017.
//

#include <iostream>
#include <set>

int main() {
    std::set<std::string> set;
    char c;
    std::cin >> c;
    for(int i = 0; c != '#'; ++i){
        std::string str;
        std::cin >> str;
        if(c == '+'){
            set.insert(str);
        }
        if(c == '-'){
            set.erase(str);
        }
        if(c == '?'){
            std::cout << (set.find(str) != set.end() ? "YES" : "NO") << std::endl;
        }
        std::cin >> c;
    }
    return 0;
}