//
// Created by pavel on 07.05.2017.
// Look the task in file "A.txt"
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, std::pair<int, int> > type;

bool Comp(type p1, type p2){
    if(p1.second.first != p2.second.first){
        return p2.second.first < p1.second.first;
    }
    else{
        if(p1.second.second != p2.second.second){
            return p1.second.second < p2.second.second;
        }
        else{
            return p1.first < p2.first;
        }
    }
}

int main() {
    std::vector<type> v;
    int n, a, b;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a >> b;
        v.push_back(std::make_pair(i, std::make_pair(a, b)));
    }
    std::sort(v.begin(), v.end(), Comp);
    for(std::vector<type>::iterator it = v.begin(); it != v.end(); ++it){
        std::cout << it->first << ' ';
    }
}