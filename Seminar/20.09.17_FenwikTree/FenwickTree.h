//
// Created by pavel on 20.09.2017.
//

#ifndef MIPT_CPP_FENWIKTREE_H
#define MIPT_CPP_FENWIKTREE_H

#include <vector>
#include <iostream>

template <class T>
class FenwickTree{
private:
    int N;
    std::vector<T> t;
public:
    void update(int index, const T &value);
    T sum(int k);
    T GetFuncResInSegment(int left, int right) const;
    explicit FenwickTree(int size) : t(size){}; ///explicit запрещает неявный вызов конструктора
    FenwickTree(const std::vector<T> &inputArray);
};


#endif //MIPT_CPP_FENWIKTREE_H
template <typename T>
void FenwickTree<T>::update(int index, const T &value) {
    while(index < N){
        t[index] += value;
        index = (index | (index + 1));
    }
}
template <typename T>
FenwickTree<T>::FenwickTree(const std::vector<T> &inputArray) {
    for(int i = 0; i < inputArray.size(); ++i){
        update(i, inputArray[i]);
    }
}
template <typename T>
T FenwickTree<T>::GetFuncResInSegment(int left, int right) const {
    T result = 0;
    while(right >= 0){
        result += t[right];
        right = right & (right + 1) - 1;
    }
    while(left >= 0){
        result -= t[right];
        left = left & (left + 1) - 1;
    }
    return result;
}

