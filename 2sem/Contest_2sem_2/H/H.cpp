//
// Created by pavel on 09.05.2017.
//

#include <iostream>
#include <set>
#include <algorithm>

struct T{
    std::set<int> S;
    void add(int i);
    int next(int i);
};

void T::add(int i) {
    this->S.insert(i);
}

int T::next(int i) {
    std::set<int>::iterator result = S.upper_bound(i - 1);
    return result != S.end() ? *result : -1;
}

int main(){
    T S;
    char c;
    int n, i, y = -1;
    bool flag = 0;
    std::cin >> n;
    for (int j = 0; j < n; ++j) {
        std::cin >> c;
        if(c == '+'){
            std::cin >> i;
            if(flag){
                S.add((i + y) % 1000000000);
            }
            else {
                S.add(i);
            }
            flag = 0;
        }
        if(c == '*'){
            for(std::set<int, std::greater<int> >::iterator it = S.S.begin(); it != S.S.end(); ++it){
                std::cout << *it << ", ";
            }
            std::cout << std::endl;
        }
        if(c == '?'){
            std::cin >> i;
            y = S.next(i);
            std::cout << y << '\n';
            flag = 1;
        }
    }
    return 0;
}