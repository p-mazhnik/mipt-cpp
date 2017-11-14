//
// Created by pavel on 06.11.2017.
//

#include <vector>
#include <iostream>

template <class T>
class FenwickTree{
private:
    long long N;
    long long M;
    std::vector<std::vector<T> > t;
public:
    void update(long long i, long long j, const T &value);
    T sum(long long x, long long y);
    T sum(long long x1, long long y1, long long x2, long long y2);
    FenwickTree(const std::vector<std::vector<T> > &inputArray);
    FenwickTree(long long n, long long m) : t(n, std::vector<T>(m)), N(n), M(m) {};
};

template <typename T>
void FenwickTree<T>::update(long long i, long long y, const T &value) {
    while(i < N){
        long long j = y;
        while (j < M) {
            t[i][j] += value;
            j = (j | (j + 1));
        }
        i = (i | (i + 1));
    }
}
template <typename T>
FenwickTree<T>::FenwickTree(const std::vector<std::vector<T> > &inputArray) {
    N = inputArray.size();
    M = inputArray[0].size();
    t.resize(N, std::vector<T>(M));
    for(long long i = 0; i < N; ++i){
        for(long long j = 0; j < M; ++j) {
            update(i, j, inputArray[i][j]);
        }
    }
}

template <typename T>
T FenwickTree<T>::sum(long long x, long long y){
    T result = 0;
    for(; x >= 0; x = ((x & (x + 1)) - 1)) {
        for (long long j = y; j >= 0; j = ((j & (j + 1)) - 1)) {
            result += t[x][j];
        }
    }
    return result;
}

template <typename T>
T FenwickTree<T>::sum(long long x1, long long y1, long long x2, long long y2) {
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

int main() {
    long long N, x ,y;
    std::cin >> x >> y >> N;
    FenwickTree<long long> tree(x, y);
    int cmd, x1, y1, k, x2, y2;
    for (long long i = 0; i < N; ++i) {
        std::cin >> cmd;
        if(cmd == 1){
            std::cin >> x1 >> y1 >> k;
            tree.update(x1 - 1, y1 - 1, k);
        }
        if (cmd == 2) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << tree.sum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
        }
    }
    return 0;
}