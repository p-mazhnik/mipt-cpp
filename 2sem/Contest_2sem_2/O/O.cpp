//
// Created by pavel on 13.05.2017.
//

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

class T{
private:
    std::set<long long> S1;
    std::set<long long> S2;
    void normal();
public:
    void add(long long i);
    long long min();
    long long mid();
    long long max();
};

void T::add(long long i) {
    if(S2.size() != 0 && i > *S2.begin()){
        this->S2.insert(i);
    }
    else this->S1.insert(i);
    this->normal();
}

long long T::min() {
    long long min = *this->S1.begin();
    this->S1.erase(min);
    this->normal();
    return min;
}

long long T::max() {
    if(S2.size() == 0) return this->mid();
    long long max = *(this->S2.rbegin());
    this->S2.erase(max);
    this->normal();
    return max;
}

long long T::mid() {
    long long mid = *this->S1.rbegin();
    this->S1.erase(mid);
    this->normal();
    return mid;
}

void T::normal() {
    long long size = (S1.size() + S2.size());
    if(this->S1.size() > (size + 1) / 2){
        long long x = *this->S1.rbegin();
        this->S1.erase(x);
        this->S2.insert(x);
    }
    else if(this->S1.size() < (size + 1) / 2){
        long long x = *this->S2.begin();
        this->S2.erase(x);
        this->S1.insert(x);
    }
}

int main(){
    T S;
    std::string c;
    long long n, x;
    std::cin >> n;
    for (long long j = 0; j < n; ++j) {
        std::cin >> c;
        if(c == "add"){
            std::cin >> x;
            S.add(x);
        }
        if(c == "min"){
            std::cout << S.min() << std::endl;
        }
        if(c == "max"){
            std::cout << S.max() << std::endl;
        }
        if(c == "mid"){
            std::cout << S.mid() << std::endl;
        }
    }
    return 0;
}