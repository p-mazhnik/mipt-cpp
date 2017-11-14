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
    long long K;
    std::vector<std::vector<std::vector<T> > > t;
public:
    void update(long long i, long long j, long long k, const T &value);
    T sum(long long x, long long y, long long z);
    T sum(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2);
    FenwickTree(long long n, long long m, long long k) : t(n, std::vector<std::vector<T> >(m, std::vector<T>(k))), N(n), M(m), K(k) {};
};

template <typename T>
void FenwickTree<T>::update(long long i, long long j, long long k, const T &value) {
    while(i < N){
        long long y = j;
        while (y < M) {
            long long z = k;
            while (z < K) {
                t[i][y][z] += value;
                z = (z | (z + 1));
            }
            y = (y | (y + 1));
        }
        i = (i | (i + 1));
    }
}

template <typename T>
T FenwickTree<T>::sum(long long x, long long y, long long z){
    T result = 0;
    for(; x >= 0; x = ((x & (x + 1)) - 1)) {
        for (long long j = y; j >= 0; j = ((j & (j + 1)) - 1)) {
            for(long long k = z; k >= 0; k = ((k & (k + 1)) - 1)) {
                result += t[x][j][k];
            }
        }
    }
    return result;
}

template <typename T>
T FenwickTree<T>::sum(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
    return (sum(x2, y2, z2) - sum(x2, y1 - 1, z2) - sum(x1 - 1, y2, z2) + sum(x1 - 1, y1 - 1, z2)) -
           (sum(x2, y2, z1 - 1) - sum(x2, y1 - 1, z1 - 1) - sum(x1 - 1, y2, z1 - 1) + sum(x1 - 1, y1 - 1, z1 - 1));
}

int main() {
    long long n;
    std::cin >> n;
    FenwickTree<long long> tree(n, n, n);
    int cmd, x1, y1, z1, k, x2, y2, z2;
    std::cin >> cmd;
    for (long long i = 0; cmd != 3; ++i) {
        if(cmd == 1){
            std::cin >> x1 >> y1 >> z1 >> k;
            tree.update(x1, y1, z1, k);
        }
        if (cmd == 2) {
            std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            std::cout << tree.sum(x1, y1, z1, x2, y2, z2) << '\n';
        }
        std::cin >> cmd;
    }
    return 0;
}