#include "String.h"

String::String(size_t capacity)
{
    //ctor
    this->capacity = capacity;
    this->values = new char[capacity];
    this->values[0] = 0;
}

String::String(const char *s)
{
    //ctor()
    size_t n = strlen(s);
    this->capacity = n + 1;
    this->values = new char[n + 1];
    strcpy(this->values, s);
}

String::String(const String &that)
{
    //ctor_cpy
    this->values = new char[that.length() + 1];
    this->capacity = that.length() + 1;
    std::memcpy(this->values, that.values, that.length());
    this->values[that.length()] = 0;
}

String::~String()
{
    //dtor
    delete []this->values;
}


size_t String::length() const
{
    return strlen(this->values);
}

size_t String::find(const char c1)
{
    size_t length = this->length();
    size_t i;
    for(i = 0; i < length + 1 && this->values[i] != c1; ++i){};
    if(i == length + 1)
    {
        i = 0;
    }
    return i;
}

void String::resize(size_t n)
{
    size_t length = this->length();
    this->capacity += n;
    char *s = new char[length + n + 1];
    strcpy(s, this->values);
    delete []this->values;
    this->values = s;
}

String &String::append(const char s)
{
    size_t length = this->length();
    if(this->capacity <= length + 1)
    {
        this->resize(1);
    }
    this->values[length] = s;
    this->values[length + 1] = 0;
    return *this;
}

String &String::append(const char *s)
{
    size_t n = strlen(s);
    size_t length = this->length();
    if(this->capacity <= length + n)
    {
        this->resize(n);
    }
    for(size_t i = length, j = 0; i < length + n + 1; ++i, ++j)
    {
        this->values[i] = s[j];
    }
    return *this;
}

String String::substring(size_t start, int finish) const
{
    int n = (int)length();
    if(finish < 0)
    {
        finish = n + finish;
    }
    size_t finish2 = (size_t)finish;
    String result(finish2 - start + 2);
    for(size_t i = start, j = 0; i <= finish; ++i, ++j)
    {
        result.values[j] = this->values[i];
    }
    result.values[finish - start + 1] = 0;
    return result;
}

String String::operator+(const char symbol) const
{
    String result(this->capacity + 1);
    std::memcpy(result.values, this->values, this->length()); ///memcpy
    result.values[length()] = symbol;
    result.values[length() + 1] = 0;
    return result;
}

String String::operator+(const String &that) const
{
    size_t n = this->length() + that.length() + 1;
    String result(n);
    for(size_t i = 0, j = 0; i < n; ++i)
    {
        if(i < this->length())
        {
           result.values[i] = this->values[i];
        }
        else
        {
           result.values[i] = that.values[j];
           ++j;
        }
    }
    result.values[n - 1] = 0;
    return result;
}

String String::operator+(const char c[]) const
{
    size_t n = this->length() + strlen(c) + 1;
    String result(n);
    for(size_t i = 0, j = 0; i < n; ++i)
    {
        if(i < this->length())
        {
           result.values[i] = this->values[i];
        }
        else
        {
            result.values[i] = c[j];
            ++j;
        }
    }
    result.values[n - 1] = 0;
    return result;
}

String operator+(const char c[], const String &s)
{
    String result(c);
    return (result + s);
}

char String::operator[](const int i) const
{
    return this->values[i];
}

String &String::operator=(const char c)
{
    delete []this->values;
    this->values = new char[2];
    this->values[0] = c;
    this->values[1] = 0;
    this->capacity = 2;
    return *this;
}

String &String::operator=(const char *c)
{
    delete []this->values;
    size_t lenc = strlen(c);
    this->values = new char[lenc + 1];
    for(size_t i = 0; i < lenc; ++i)
    {
        this->values[i] = c[i];
    }
    this->values[lenc] = 0;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    out << s.values;
    return out;
}

std::istream &operator>>(std::istream &in, const String &s)
{
    in >> s.values;
    return in;
}

String::operator char *() const
{
    return this->values;
}

String::operator int() const
{
    return atoi(this->values);
}

String::operator double() const
{
    return atof(this->values);
}

/*void String::print() const
{
    std::cout << this->values << std::endl;
}
*/
