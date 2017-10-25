//
// Created by pavel on 20.09.2017.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "FenwickTree.h"

int main(){
    std::vector<int> t(10);
    for (std::vector<int>::iterator i = t.begin(); i < t.end(); ++i) {
        std::cout << *i << '\n';
    }
}
