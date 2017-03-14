//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

void BigInt::set_length(const int length) {
    this->length = length;
    this->values = new int[this->length];
}

BigInt::BigInt(int value) { //конструктор от int
    this->values = new int[1];
    char *string = new char[DEFAULT_CAPACITY];
    itoa(value, string, 10);
    *this = string;
}

BigInt::BigInt(const char *string) { //конструктор от строки
    int l = (int)strlen(string);
    this->length = (l / 3);
    if (l % 3) {
        this->length = (l / 3) + 1;
    }
    this->values = new int[this->length];
    int j = 0;
    if (l % 3) {
        char *c = new char[3];
        std::memcpy(c, string, (size_t)(l % 3));
        this->values[0] = atoi(c);
        delete []c;
        ++j;
    }
    for (int i = l % 3; i < l; i += 3, ++j) {
        char *c = new char[3];
        std::memcpy(c, string + i, 3);
        this->values[j] = atoi(c);
        delete []c;
    }
}

BigInt::~BigInt() {
    delete []this->values;
}

BigInt::BigInt(const BigInt &that) { //конструктор копирования
    this->values = new int[1];
    *this = that;
}

BigInt BigInt::operator+(const BigInt &that) const {
    int l_max = std::max(this->length, that.length);
    int l_min = std::min(this->length, that.length);
    int d_l = l_max - l_min;
    BigInt result;
    bool flag;
    if(this->length > that.length) {
        result = *this;
        flag = 1;
    } else{
        result = that;
        flag = 0;
    }
    that.print();
    for (int i = l_max - 1; i >= 0; --i) {
        if(flag && i - d_l >= 0) result.values[i] += that.values[i - d_l];
        else if (i - d_l >= 0) result.values[i] += this->values[i - d_l];
        if (result.values[i] >= 1000 && i > 0){
            result.values[i - 1] += 1;
            result.values[i] %= 1000;
        }
    }
    if(result.values[0] >= 1000){
        BigInt temp;
        temp.set_length(l_max + 1);
        temp.values[0] = 0;
        std::memcpy(temp.values + 1, result.values, sizeof(int) * result.length);
        temp.values[0] += 1;
        temp.values[1] %= 1000;
        result = temp;
    }
    return result;
}

std::ostream &operator<<(std::ostream &out, const BigInt &t) {
    for (int i = 0; i < t.length; ++i) {
        if(t.values[i] < 100 && i != 0){
            if(t.values[i] < 10){
                out << 0;
            }
            out << 0;
        }
        out << t.values[i];
    }
    return out;
}

std::istream &operator>>(std::istream &in, BigInt &t) {
    char *string = new char[DEFAULT_CAPACITY];
    in >> string;
    t = string;
    delete []string;
    return in;
}

BigInt &BigInt::operator=(const char *string) {
    BigInt temp(string);
    *this = temp;
    return *this;
}

BigInt &BigInt::operator=(const BigInt &that) {
    delete []this->values;
    this->set_length(that.length);
    std::memcpy(this->values, that.values, sizeof(int) * that.length);
    return *this;
}

void BigInt::print() const {
    for (int i = 0; i < this->length; ++i) {
        std::cout << this->values[i] << ' ';
    }
    std::cout << std::endl;
}

BigInt BigInt::operator*(const BigInt &that) const {

    return BigInt();
}
