//
// Created by pavel on 08.11.2017.
//

#include <iostream>
#include <vector>

unsigned int a, b; // даны во входных данных
unsigned int cur = 0; // беззнаковое 32-битное число
unsigned int nextRand() {
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8; // число от 0 до 224-1.
}

const int pow_2_24 = (1 << 24);

int main(){
    unsigned int m, q;
    unsigned int l, r, add;
    std::cin >> m >> q;
    std::cin >> a >> b;
    std::vector<unsigned int> input(pow_2_24);
    std::vector<unsigned int> prefix(pow_2_24);
    for (unsigned int i = 0; i < m; i++) {
        add = nextRand(); // число, которое нужно прибавить
        l = nextRand();
        r = nextRand();
        if (l > r) std::swap(l, r); // получили отрезок [l..r]

        input[l] += add;
        input[r + 1] -= add;
    }
    unsigned int value = 0;
    for (unsigned int i = 0; i < pow_2_24; i++) {
        value += input[i];
        if(i > 0) prefix[i] = value + prefix[i - 1];
        else prefix[i] = input[0];
    }
    unsigned int result = 0;
    for (unsigned int i = 0; i < q; i++) {
        l = nextRand();
        r = nextRand();
        if (l > r) std::swap(l, r); // получили отрезок [l..r]
        if (l != 0) {
            result += prefix[r] - prefix[l - 1];
        }
        else {
            result += prefix[r];
        }
    }
    std::cout << result << '\n';
    return 0;
}