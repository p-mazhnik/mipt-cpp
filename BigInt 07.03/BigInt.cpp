//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

void BigInt::set_length(const int length) {
    this->length = length;
    this->values = new int[this->length];
}

BigInt::BigInt(number_size value) { //конструктор от int
    this->set_length(1);
    char *string = new char[DEFAULT_CAPACITY];
    itoa(value, string, 10);
    *this = string;
}

BigInt::BigInt(const char *string) { //конструктор от строки
    int l = (int)strlen(string);
    if(string[0] == '-'){
        --l;
        ++string;
        this->sign = -1;
    }
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

BigInt::BigInt(const BigInt &that) { //конструктор копирования
    this->values = new int[1];
    *this = that;
}

BigInt::~BigInt() {
    delete []this->values;
}

bool BigInt::operator>(const BigInt &that) const {
    if(this->length != that.length) {
        return this->length > that.length;
    }
    else{
        for (int i = 0; i < this->length; ++i) {
            if (this->values[i] != that.values[i]){
                return this->values[i] > that.values[i];
            }
        }
        return false;
    }
}

bool BigInt::operator==(const BigInt &that) const {
    if(this->length == that.length) {
        for (int i = 0; i < this->length; ++i) {
            if (this->values[i] != that.values[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

const BigInt & abs_max(const BigInt &a, const BigInt &b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

const BigInt & abs_min(const BigInt &a, const BigInt &b){
    return a > b ? b : a;
}

BigInt BigInt::abs_sum(const BigInt &that) const {
    int l_max = std::max(this->length, that.length);
    int l_min = std::min(this->length, that.length);
    int d_l = l_max - l_min;
    BigInt result (abs_max(*this, that));
    bool flag = *this > that;
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
    result.sign = 1;
    return result;
}

BigInt BigInt::abs_sub(const BigInt &that) const {
    BigInt result (abs_max(*this, that));
    if(*this == that){
        result = 0;
    }
    else {
        int l_max = std::max(this->length, that.length);
        int l_min = std::min(this->length, that.length);
        int d_l = l_max - l_min;
        bool flag = *this > that;
        for (int i = l_max - 1; i >= 0; --i) {
            if (flag && i - d_l >= 0) result.values[i] -= that.values[i - d_l];
            else if (i - d_l >= 0) result.values[i] -= this->values[i - d_l];
            if (result.values[i] < 0 && i > 0) {
                result.values[i - 1] -= 1;
                result.values[i] += 1000;
            }
        }
        if (result.values[0] == 0) {
            int i = 0;
            while(result.values[i] == 0){
                ++i;
            }
            BigInt temp;
            temp.set_length(l_max - i);
            std::memcpy(temp.values, result.values + i, sizeof(int) * temp.length);
            result = temp;
        }
    }
    return result;
}

BigInt BigInt::operator+(const BigInt &that) const {
    BigInt result;
    if(this->sign * that.sign == 1){
        result = this->abs_sum(that);
        if(this->sign < 0){
            result.sign = -1;
        }
    }
    else{
        result = this->abs_sub(that);
    }
    return result;
}

BigInt BigInt::operator-(const BigInt &that) const {
    BigInt result;
    if(this->sign * that.sign == 1){
        result = this->abs_sub(that);
        if(that > *this){
            result.sign = -1;
        }
    }
    else{
        result = this->abs_sum(that);
        if(this->sign < 0){
            result.sign = -1;
        }
    }
    return result;
}

std::ostream &operator<<(std::ostream &out, const BigInt &t) {
    if(t.sign < 0){
        out << '-';
    }
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

BigInt &BigInt::operator=(const number_size value) {
    BigInt temp(value);
    *this = temp;
    return *this;
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
    this->sign = that.sign;
    return *this;
}

void BigInt::print() const {
    if(this->sign < 0){
        std::cout << '-' << ' ';
    }
    for (int i = 0; i < this->length; ++i) {
        std::cout << this->values[i] << ' ';
    }
    std::cout << std::endl;
}

BigInt BigInt::operator*(const BigInt &that) const {

    return BigInt();
}

BigInt BigInt::operator-() {
    BigInt result(*this);
    result.sign = -1;
    return result;
}
