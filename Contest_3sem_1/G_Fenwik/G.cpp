//
// Created by pavel on 20.09.2017.
//

#include <vector>
#include <iostream>

template <class T>
class FenwickTree{
private:
    int N;
    std::vector<T> t;
public:
    void update(long long index, const T &value);
    T sum(long long r);
    T sum(long long l , long long r);
    explicit FenwickTree(long long size) : t(size){}; ///explicit запрещает неявный вызов конструктора
    FenwickTree(const std::vector<T> &inputArray);
};

template <typename T>
void FenwickTree<T>::update(long long index, const T &value) {
    while(index < N){
        t[index] += value;
        index = (index | (index + 1));
    }
}
template <typename T>
FenwickTree<T>::FenwickTree(const std::vector<T> &inputArray) {
    N = (int) inputArray.size();
    t.resize(N);
    for(int i = 0; i < inputArray.size(); ++i){
        update(i, inputArray[i]);
    }
}

template <typename T>
T FenwickTree<T>::sum(long long r) {
    T result = 0;
    while (r >= 0) {
        result += t[r];
        r = (r & (r + 1)) - 1;
    }
    return result;
}

template <typename T>
T FenwickTree<T>::sum(long long l, long long r) {
    if(l != 0) {
        return sum(r) - sum(l - 1);
    }
    else {
        return sum(r);
    }
}

int main() {
    long long N;
    std::cin >> N;
    std::vector<long long> a(N);
    for (long long i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    FenwickTree<long long> tree(a);
    long long k, x, y;
    std::cin >> k;
    std::vector<long long> result;

    char cmd;
    for (long long i = 0; i < k; ++i) {
        std::cin >> cmd >> x >> y;
        if(cmd == 's'){
            result.push_back(tree.sum(x - 1, y - 1));
            //std::cout << tree.sum(x - 1, y - 1) << '\n';
        }
        if (cmd == 'u') {
            tree.update(x - 1, y - a[x - 1]);
            a[x - 1] = y;
        }
    }
    for (long long j = 0; j < result.size(); ++j) {
        std::cout << result[j] << ' ';
    }
    return 0;
}