//
// Created by pavel on 07.05.2017.
// Look the task in file "C.txt"
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v1;
    std::vector<int> v2;
    int n, a;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        std::vector<int>::iterator it = std::find(v1.begin(), v1.end(), a);
        if(i == 0 || it == v1.end()) { //считаем кол-во повторений каждого цвета
            v1.push_back(a);
            v2.push_back(1);
        }
        else{
            ++v2[it - v1.begin()];
        }
    }
    int b, result = 0;
    std::cin >> b;
    std::vector<int>::iterator it = std::find(v1.begin(), v1.end(), b);
    if (it != v1.end()) {
        result = v2[it - v1.begin()];
    }
    std::cout << result << '\n';
    return 0;
}