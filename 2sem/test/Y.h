//
// Created by pavel on 14.04.2017.
//

#ifndef MIPT_CPP_Y_H
#define MIPT_CPP_Y_H

#define COIN_Y 100

#include "X.cpp"

template <typename T>
class Y : public X{
private:
    double weight;
    T a;
    T b;
public:
    void refactor(int, int);
    double get_weight();
    float price();

    void test_f (T);
};

template <typename T>
void Y<T>::test_f(T a) {
    std::cout << "unknown";
}

template <typename T>
double Y<T>::get_weight() {
    return this->weight;
}

template <typename T>
void Y<T>::refactor(int p, int q) {
    this->a += p;
    this->b += q;
    this->weight *= (p / q);
}

template <typename T>
float Y<T>::price() {
    return (float) this->weight * COIN_Y;
}

template <>
void Y<int>::refactor(int p, int q) {
    this->a = p;
    this->b = q;
}

template<>
void Y<int>::test_f(int a) {
    std::cout << "int";
}

template<>
void Y<double>::test_f(double a) {
    std::cout << "double";
}

#endif //MIPT_CPP_Y_H
