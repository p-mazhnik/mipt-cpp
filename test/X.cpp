//
// Created by pavel on 04.04.2017.
//

#ifndef MIPT_CPP_X_H
#define MIPT_CPP_X_H

#include <iostream>

class X{
protected:
    void empty(){};
public:
    virtual void refactor(int a, int b) = 0;
    virtual double get_weight() = 0;
    virtual float price() = 0;
};

#endif //MIPT_CPP_X_H