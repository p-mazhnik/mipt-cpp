//
// Created by pavel on 07.05.2017.
// Look the task in file "B.txt"
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v1;
    std::vector<int> v2;
    int n, a;
    std::cin >> n;
    for (int i = 0, k = -1; i < n; ++i) {
        std::cin >> a;
        if(i == 0 || a != v1[k]) { //считаем кол-во повторений каждого цвета
            ++k;
            v1.push_back(a);
            v2.push_back(1);
        }
        else{
            ++v2[k];
        }
    }
    unsigned long long m;
    int b;
    std::cin >> m;
    std::vector<int> t(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b;
        t[i] = 0;
        if(v1.size() != 0 && v1[0] <= b && b <= v1[v1.size() - 1]) {
            std::vector<int>::iterator result = std::lower_bound(v1.begin(), v1.end(), b);
            if (result != v1.end() && *result == b) {
                t[i] = v2[result - v1.begin()];
            }
        }
        std::cout << t[i] << '\n';
    }
}