//
// Created by pavel on 14.04.2017.
//

#ifndef PROJECT_Z_H
#define PROJECT_Z_H

#include "X.cpp"

template <typename T>
class Z : public X{
private:
    double weight;
    float unique_price;
    double a, b, c;
public:
    void refactor(int, int);
    double get_weight();
    float price();

    double k();
};

float Z::price() {
    return this->unique_price * this->weight;
}

double Z::get_weight() {
    return this->weight;
}

void Z::refactor(int p, int q) {
    if(a * b * c >= p * q) {
        --a;
        --b;
        --c;
    }
    else{
        a *= 2;
        b *= 2;
    }
}

double Z::k() {
    return (double)unique_price * weight * a * b * c;
}


#endif //PROJECT_Z_H
