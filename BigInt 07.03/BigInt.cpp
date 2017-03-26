//
// Created by pavel on 12.03.2017.
//

#include "BigInt.h"

void BigInt::set_length(const int new_length) {
    if(new_length > LIM_LENGTH){
        throw BigIntegerOverflow();
    }
    if (this->length != 0 && this->length != new_length) {
        delete []this->values;
    }
    if (this->length != new_length) {
        this->values = new int[new_length];
    }
    this->length = new_length;
}

BigInt::BigInt(const long long value) { //конструктор от числа
    this->sign = 1;
    this->length = 0;
    int len_s = 0;
    if(value < 0){
        ++len_s;
    }
    long long temp_value = value;
    for (; temp_value != 0 || len_s == 0; ++len_s) {
        temp_value /= 10;
    }
    char *string = new char[len_s + 1];
    temp_value = value;
    if(temp_value < 0){
        string[0] = '-';
        temp_value *= -1;
    }
    for (int j = len_s - 1; temp_value != 0 || j == len_s - 1; --j) {
        string[j] = (temp_value % 10) + '0';
        temp_value /= 10;
    }
    string[len_s] = 0;
    *this = string;
}

BigInt::BigInt(const char *string) { //конструктор от строки
    this->sign = 1;
    int l = (int)strlen(string);
    if(string[0] == '-'){
        --l;
        ++string;
        this->sign = -1;
    }
    this->length = (l / BASE);
    if (l % BASE) {
        this->length = (l / BASE) + 1;
    }
    if(this->length > LIM_LENGTH){
        throw BigIntegerOverflow();
    }
    this->values = new int[this->length];
    int j = 0;
    if (l % BASE) {
        char *c = new char[l % BASE + 1];
        std::memcpy(c, string, (size_t)(l % BASE));
        c[l % BASE] = 0;
        this->values[0] = atoi(c);
        delete []c;
        ++j;
    }
    for (int i = l % BASE; i < l; i += BASE, ++j) {
        char *c = new char[BASE + 1];
        std::memcpy(c, string + i, BASE);
        c[BASE] = 0;
        this->values[j] = atoi(c);
        delete []c;
    }
}

BigInt::BigInt(const BigInt &that) { //конструктор копирования
    this->length = 0;
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

bool operator!=(const BigInt &a, const BigInt &b) {
    return !(a == b);
}

bool BigInt::operator>=(const BigInt &that) const {
    return (*this > that || *this == that);
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
        if (result.values[i] >= MAX_VALUE && i > 0){
            result.values[i - 1] += result.values[i] / MAX_VALUE;
            result.values[i] %= MAX_VALUE;
        }
    }
    while(result.values[0] >= MAX_VALUE){
        BigInt temp;
        temp.set_length(l_max + 1);
        temp.values[0] = 0;
        std::memcpy(temp.values + 1, result.values, sizeof(int) * result.length);
        temp.values[0] += temp.values[1] / MAX_VALUE;
        temp.values[1] %= MAX_VALUE;
        result = temp;
    }
    if(result.length > LIM_LENGTH){
        throw BigIntegerOverflow();
    }
    result.sign = 1;
    return result;
}

BigInt BigInt::abs_sub(const BigInt &that) const {
    BigInt result (abs_max(*this, that));
    if(*this == that){
        result = "0";
    }
    else {
        int l_max = std::max(this->length, that.length);
        int l_min = std::min(this->length, that.length);
        int d_l = l_max - l_min;
        bool flag = *this > that;
        for (int i = l_max - 1; i >= 0; --i) {
            if (flag && i - d_l >= 0) {
                result.values[i] -= that.values[i - d_l];
            }
            else if (i - d_l >= 0) {
                result.values[i] -= this->values[i - d_l];
            }
            if (result.values[i] < 0 && i > 0) {
                result.values[i - 1] -= 1;
                result.values[i] += MAX_VALUE;
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

BigInt BigInt::operator+(const long long that) const {
    return (*this + BigInt(that));
}

BigInt operator+(const long long a, const BigInt &b) {
    return (BigInt(a) + b);
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

BigInt BigInt::operator-() {
    BigInt result(*this);
    result.sign = -1;
    return result;
}

BigInt BigInt::operator-(const long long that) const {
    return (*this - BigInt(that));
}

BigInt operator-(const long long a, const BigInt &b) {
    return (BigInt(a) - b);
}

std::ostream &operator<<(std::ostream &out, const BigInt &t) {
    if(t.sign < 0){
        out << '-';
    }
    for (int i = 0; i < t.length; ++i) {
        int k = MAX_VALUE / 10;
        int value = t.values[i];
        while(value < k && i != 0 && k != 1){
            out << 0;
            k /= 10;
        }
        out << t.values[i];
    }
    return out;
}

std::istream &operator>>(std::istream &in, BigInt &t) {
    char *string = new char[10002];
    in >> string;
    t = string;
    delete []string;
    return in;
}

BigInt &BigInt::operator=(const long long value) {
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
    BigInt result;
    int l_max = std::max(this->length, that.length);
    int l_min = std::min(this->length, that.length);
    BigInt a;
    a.set_length(this->length + that.length);
    a.length = l_max;
    a = abs_max(*this, that);
    BigInt b = abs_min(*this, that);
    if(a == result || b == result){
        return result;
    }
    BigInt temp(a);
    a.sign = b.sign = 1;
    for (int i = l_min - 1; i >= 0; --i) {
        for (int j = l_max - 1; j >= 0; --j) {
            temp.values[j] *= b.values[i];
        }
        result += temp;
        ++a.length;
        a.values[a.length - 1] = 0;
        temp = a;
    }
    if(result.length > LIM_LENGTH){
        throw BigIntegerOverflow();
    }
    result.sign = this->sign * that.sign;
    return result;
}

BigInt BigInt::operator*(const long long that) const{
    return (*this * BigInt(that));
}

BigInt operator*(const long long a, const BigInt &b) {
    return (BigInt(a) * b);
}

BigInt BigInt::operator/(const BigInt &that) const {
    BigInt result;
    if (that == result){
        throw BigIntegerDivisionByZero();
    }
    if(!(*this >= that)){
        return result;
    }
    BigInt temp;
    BigInt zero;
    temp.set_length(that.length + 200);
    int  temp_capacity;
    int l_max = this->length;
    int l_min = that.length;
    int d_l = l_max - l_min;
    result.set_length(d_l + 200);
    int sign = this->sign * that.sign;
    BigInt rest = this->values[0];
    int i = 0;
    for (int m = 0; m < l_max; ++i, ++m) {
        temp_capacity = l_min;
        for (int j = 0; j < temp_capacity && m < l_max; ++j, ++m) {
            if(j < rest.length && rest.values[0] != 0){
                if(i != 0) {
                    --m;
                }
                temp.values[j] = rest.values[j];
                temp.length = j + 1;
                if(j == temp_capacity - 1 && !(temp >= that)) {
                    ++temp_capacity;
                }
            }
            else {
                temp.values[j] = this->values[m];
                temp.length = j + 1;
                if(!(temp >= that)){
                    if(i != 0){
                        result.values[i] = 0;
                        if(m + 1 != l_max) ++i;
                    }
                    if(j == temp_capacity - 1 && temp != zero){
                        ++temp_capacity;
                    }
                }
                if(temp.values[0] == 0){
                    --j;
                }
            }
        }
        --m;
        int k = 1;
        while(temp >= that * k){
            ++k;
        }
        --k;
        rest = temp - that * k * that.sign;
        if(m < l_max) result.values[i] = k;
    }
    result.length = i;
    result.sign = sign;
    return result;
}

BigInt BigInt::operator/(const long long that) const {
    return (*this / BigInt(that));
}

BigInt operator/(const long long a, const BigInt &b) {
    return (BigInt(a) / b);
}

BigInt operator%(const BigInt &a, const BigInt &b) {
    return (a - (a / b) * b);
}

BigInt &BigInt::operator+=(const BigInt &that) {
    *this = (*this + that);
    return *this;
}

BigInt &BigInt::operator+=(const long long that) {
    *this = (*this + that);
    return *this;
}

BigInt &BigInt::operator-=(const BigInt &that) {
    *this = (*this - that);
    return *this;
}

BigInt &BigInt::operator-=(const long long that) {
    *this = (*this - that);
    return *this;
}

BigInt &BigInt::operator*=(const BigInt &that) {
    *this = *this * that;
    return *this;
}

BigInt &BigInt::operator*=(const long long that) {
    *this = *this * that;
    return *this;
}

BigInt &BigInt::operator/=(const BigInt &that) {
    *this = *this / that;
    return *this;
}

BigInt &BigInt::operator/=(const long long that) {
    *this = *this / that;
    return *this;
}

BigInt &BigInt::operator++() {
    *this += 1;
    return *this;
}

BigInt BigInt::operator++(int) {
    BigInt old(*this);
    *this += 1;
    return old;
}

BigInt &BigInt::operator--() {
    *this -= 1;
    return *this;
}

BigInt BigInt::operator--(int) {
    BigInt old(*this);
    *this -= 1;
    return old;
}

BigInt nod(const BigInt &a, const BigInt &b) {
    BigInt zero;
    BigInt a1(abs_max(a, b));
    BigInt b1(abs_min(a, b));
    while(b1 != zero) {
        BigInt temp(b1);
        b1 = a1 % b1;
        a1 = temp;
    }
    return a1;
}

BigInt sqrt(const BigInt &that) {
    BigInt left(1);
    BigInt right(that);
    BigInt middle((left + right) / 2);
    while (left != middle) {
        if(middle * middle > that){
            right = middle;
        } else{
            left = middle;
        }
        middle = (left + right) / 2;
    }
    return middle;
}