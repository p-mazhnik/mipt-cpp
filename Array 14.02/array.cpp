#include <iostream>
#include <cstdio>
#include <math.h>
#include "array.h"

int_array::int_array(const int size): size(size)
{
    this->values = new int[size];
    for(int i = 0; i < this->size; ++i)
    {
        this->values[i] = i + 1;
    }
}

int_array::~int_array()
{
    delete [] this->values;
}

void int_array::print() const
{
    for(int i = 0; i < this->size; ++i)
    {
        std::cout << this->values[i] << ' ';
    }
}

int_array::int_array(const int_array &that)
{
    this->size = that.size;
    this->values = new int[this->size];
    for(int i = 0; i < this->size; ++i)
    {
        this->values[i] = that.values[i];
    }
}

void int_array::set(int index, int value)
{
    this->values[index] = value;
}

int int_array::get(int index)
{
    return this->values[index];
}

int_array int_array::sub_array(int start, int finish)
{
    int_array new_array(finish - start + 1);
    for(int i = 0; i < finish - start + 1; ++i)
    {
        new_array.values[i] = this->values[start + i];
    }
    return new_array;
}

void int_array::resize(int size)
{
    int *s = new int[size];
    for(int i = 0; i < size; ++i)
    {
        if(i >= this->size)
        {
            s[i] = 0;
        }
        else
        {
            s[i] = this->values[i];
        }
    }
    int *k = values;
    this->values = s;
    delete []k;
    this->size = size;
}

int_array int_array::revert()
{
    int_array s(this->size);
    for(int i = this->size - 1, j = 0; i >= 0; --i, ++j)
    {
        s.values[j] = this->values[i];
    }
    return s;
}

int int_array::max()
{
    int m = this->values[0];
    for(int i = 1; i < this->size; ++i)
    {
        if(this->values[i] > m)
        {
            m = this->values[i];
        }
    }
    return m;
}

int int_array::min()
{
    int m = this->values[0];
    for(int i = 1; i < this->size; ++i)
    {
        if(this->values[i] < m)
        {
            m = this->values[i];
        }
    }
    return m;
}

int_array int_array::operator+(const int_array &that)
{
    int_array sum(this->size + that.size);
    for(int i = 0; i < this->size; ++i)
    {
        sum.values[i] = this->values[i];
    }
    for(int j = 0; j < that.size; ++j)
    {
        sum.values[this->size + j] = that.values[j];
    }
    return sum;
}

int_array int_array::operator+(const int &value)
{
    int_array sum(this->size + 1);
    for(int i = 0; i < this->size; ++i)
    {
        sum.values[i] = this->values[i];
    }
    sum.values[this->size] = value;
    return sum;
}
