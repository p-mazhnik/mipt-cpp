//
// Created by pavel on 07.05.2017.
// Look the task in file "C.txt"
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(2001);
    int n, a;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        ++v[a + 1000];
    }
    int b;
    std::cin >> b;
    std::cout << v[b + 1000] << '\n';
    return 0;
}