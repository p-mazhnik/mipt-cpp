//
// Created by pavel on 08.11.2017.
//

#include <vector>
#include <iostream>

template <typename T>
class sparse_table {
private:
    std::vector<T> data;
    std::vector <std::vector<int> > table;
    void build_table();
    long long log_2(long long n);
public:

    sparse_table(const std::vector<T> &data) : data(data) {
        build_table();
    }

    T get_min(long long L, long long R);
};

template <typename T>
void sparse_table<T>::build_table() {
    if (!data.size()) {
        return;
    }
    table.resize(1);
    table[0].resize(data.size());
    for (int i = 0; i < data.size(); ++i) {
        table[0][i] = data[i];
    }
    long long pow = 1;
    long long max_pow = log_2(data.size());
    table.resize(max_pow + 1);
    for (; pow <= max_pow; ++pow) {
        int current_pow_two = (1 << pow), prev_pow_two = (1 << (pow - 1));
        table[pow].resize(data.size() - current_pow_two + 1);
        for (int i = 0; i <= data.size() - current_pow_two; ++i) {
            table[pow][i] = std::min(table[pow - 1][i], table[pow - 1][i + prev_pow_two]);
        }
    }
}

template <typename T>
long long sparse_table<T>::log_2(long long n) {
    int k = 0;
    while ((1 << k) <= n) {
        ++k;
    }
    return k - 1;
}

template <typename T>
T sparse_table<T>::get_min(long long L, long long R) {
    if(R == L) {
        return data[R];
    }
    if(L > R) {
        long long l = L;
        L = R;
        R = l;
    }
    if (L >= data.size() || R > data.size()) {
        return T(-1);
    }
    long long pow = log_2(R - L + 1);
    return std::min(table[pow][L], table[pow][R - (1 << pow) + 1]);
}

int main(){
    long long N, M, a1, u1, v1;
    std::cin >> N >> M >> a1 >> u1 >> v1;
    std::vector<long long> input(N);
    std::vector<long long> min(M);
    std::vector<long long> u(M);
    std::vector<long long> v(M);
    input[0] = a1;
    u[0] = u1;
    v[0] = v1;
    for (int i = 1; i < N; ++i) {
        input[i] = (23 * input[i - 1] + 21563) % 16714589;
    }
    sparse_table<long long> table(input);
    min[0] = table.get_min(u1 - 1, v1 - 1);
    for (int j = 1; j < M; ++j) {
        u[j] = (17 * u[j - 1] + 751 + min[j - 1] + 2 * (j)) % N + 1;
        v[j] = (13 * v[j - 1] + 593 + min[j - 1] + 5 * (j)) % N + 1;
        min[j] = table.get_min(u[j] - 1, v[j] - 1);
    }
    /*for (int k = 0; k < M; ++k) {
        std::cout << u[k] << ' ' << v[k] << ' ' << min[k] << '\n';
    }*/
    std::cout << u[M - 1] << ' ' << v[M - 1] << ' ' << min[M - 1];
    return 0;
}