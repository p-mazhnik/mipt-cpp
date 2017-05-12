//
// Created by pavel on 12.05.2017.
//

#include <iostream>
#include <map>

int main() {
    std::string s;
    std::map<std::string, int> account;
    int n, x, j;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> j >> s;
        if(j == 1){
            std::cin >> x;
            account[s] += x;
        } else{
            try {
                std::map<std::string, int>::iterator it = account.find(s);
                if (it != account.end()) {
                    std::cout << account[s] << '\n';
                } else{
                    throw 1;
                }
            } catch (int){
                std::cout << "ERROR" << '\n';
            }
        }
    }
}
