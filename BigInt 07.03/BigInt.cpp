//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

BigInt::BigInt(size_t length) {
    this->length = length;
    this->values = new int[this->length];
}

BigInt::BigInt(const char *string) {
    size_t l = strlen(string);
    this->length = (l / 3);
    if (l % 3) {
        this->length = (l / 3) + 1;
    }
    this->values = new int[this->length];
    int j = 0;
    if (l % 3) {
        char *c = new char[3];
        std::memcpy(c, string, (l % 3));
        this->values[0] = atoi(c);
        //std::cout << this->values[0] << std::endl;
        delete []c;
        ++j;
    }
    for (size_t i = l % 3; i < l; i += 3, ++j) {
        char *c = new char[3];
        std::memcpy(c, string + i, 3);
        //::cout << c << std::endl;
        this->values[j] = atoi(c);
        delete []c;
    }
}

BigInt::~BigInt() {
    delete []this->values;
}

BigInt::BigInt(const BigInt &that) {
    this->length = that.length;
    this->values = new int[this->length];
    std::memcpy(this->values, that.values, sizeof(int) * that.length);
}

BigInt BigInt::operator+(const BigInt &that) const {
    size_t l_max = std::max(this->length, that.length);
    size_t l_min = std::min(this->length, that.length);
    size_t d_l = l_max - l_min;
    BigInt result;
    bool flag;
    if(this->length > that.length) {
        result = *this;
        flag = 1;
        std::cout << "that: ";
        that.print();

    } else{
        result = that;
        flag = 0;
        std::cout << "this: ";
        this->print();
    }
    std::cout << "temp_result: ";
    result.print();
    for (size_t i = l_max - 1; i >= 0 && i < l_max; --i) {
        if(flag && i - d_l >= 0) result.values[i] += that.values[i - d_l];
        else if (i - d_l >= 0) result.values[i] += this->values[i - d_l];
        if (result.values[i] >= 1000 && i > 0){
            result.values[i - 1] += 1;
            result.values[i] %= 1000;
        }
    }
    if(result.values[0] >= 1000){
        BigInt temp(l_max + 1);
        temp.values[0] = 0;
        std::memcpy(temp.values + 1, result.values, sizeof(int) * result.length);
        temp.values[0] += 1;
        temp.values[1] %= 1000;
        result = temp;
    }
    std::cout << "result: ";
    result.print();
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
    delete []this->values;
    this->values = new int[temp.length];
    this->length = temp.length;
    std::memcpy(this->values, temp.values, sizeof(int) * temp.length);
    return *this;
}

BigInt &BigInt::operator=(const BigInt &that) {
    delete []this->values;
    this->length = that.length;
    this->values = new int[this->length];
    std::memcpy(this->values, that.values, sizeof(int) * that.length);
    return *this;
}

void BigInt::print() const {
    for (int i = 0; i < this->length; ++i) {
        std::cout << this->values[i] << ' ';
    }
    std::cout << std::endl;
}

/*BigInt &BigInt::operator=(int a) {
    char *string = new char[DEFAULT_CAPACITY];
    itoa(a, string, 10);
    *this = string;
    return *this;
}*/

BigInt::BigInt(int value) {
    this->values = new int[1];
    char *string = new char[DEFAULT_CAPACITY];
    itoa(value, string, 10);
    *this = string;
}
