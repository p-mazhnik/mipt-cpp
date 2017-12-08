//
// Created by pavel on 06.12.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<long long> Z_function(std::vector<long long> str) {
    std::vector<long long> z (str.size());
    z[0] = str.size();
    for (long long i = 1, l = 0, r = 0; i < str.size(); ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long N, M;
    std::cin >> N >> M;
    std::vector<long long> input(N);
    for (int a, i = 0; i < N; ++i) {
        std::cin >> a;
        input[i] = a;
    }

    std::vector<long long> new_str(2 * input.size() + 1);
    for (int k = 0; k < input.size(); ++k) {
        new_str[k] = input[k];
    }
    std::reverse(input.begin(), input.end());
    new_str[input.size()] = -1;
    for (int k = 1; k < input.size() + 1; ++k) {
        new_str[k + input.size()] = input[k - 1];
    }

    std::vector<long long> z = Z_function(new_str);

    std::set<long long, std::greater<long long> > set = {0};
    for (long long j = input.size(); j < new_str.size(); ++j) {
        if(z[j] % 2 == 0 && z[j] + j == new_str.size()) {
            set.insert(z[j] / 2);
        }
    }
    for (auto it = set.begin(); it != set.end(); ++it){
        std::cout << N - *it << ' ';
    }
    return 0;
}
/*
 *
16 2
1 2 2 1 2 1 1 2 2 1 1 2 1 2 2 1
 */