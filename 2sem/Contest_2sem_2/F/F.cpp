//
// Created by pavel on 09.05.2017.
//

#include <iostream>
#include <vector>

int main() {
    unsigned long long n;
    std::cin >> n;
    std::vector<std::vector<int> > v(n + 1);
    int m, a, b;
    std::cin >> m;
    int x;
    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        std::cin >> a;
        if(x == 1){
            std::cin >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        else{
            for(std::vector<int>::iterator it = v[a].begin(); it != v[a].end(); ++it){
                std::cout << *it << ' ';
            }
            std::cout << '\n';
        };
    }
}