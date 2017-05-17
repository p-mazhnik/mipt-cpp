//
// Created by pavel on 13.05.2017.
//

#include <iostream>
#include <cstdio>
#include <queue>

int main(){
    unsigned long long n;
    std::cin >> n;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long> > q;
    long long x, sum = 0;
    for (long long i = 0; i < n; ++i) {
        std::cin >> x;
        q.push(x);
    }
    while (q.size() != 1) {
        long long j1 = q.top();
        //std::cout << "j1 = " << j1 << '\n';
        q.pop();
        long long j2 = q.top();
        //std::cout << "j2 = " << j2 << '\n';
        q.pop();
        long long j_sum = j1 + j2;
        sum += j_sum;
        q.push(j_sum);
    }
    printf("%.2f", sum * 0.05);
    return 0;
}