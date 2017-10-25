#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

#define DEFAULT_CAPACITY 100

class String
{
    private:
        char *values;
        size_t capacity; ///кол-во ячеек, выделенных в памяти

    public:
        String(size_t capacity = DEFAULT_CAPACITY); ///конструктор по умолчанию
        String(const char *); ///конструктор от строки
        String(const String &); ///конструктор копирования
        ~String(); ///деструктор

        size_t length() const; ///длина строки
        size_t find(const char); ///поиск символа в строке
        void resize(size_t); ///выделение доп. памяти

        String &append(const char); ///увеличить строку на символ (поменять сам объект)
        String &append(const char *); ///увеличить строку на строку (поменять сам объект)
        //String &append(const String &); ///увеличить строку на другую строку (поменять сам объект)

        String substring(size_t start = 0, int finish = -1) const; ///подстрока

        String operator+(const char) const; ///конкатинация строк
        String operator+(const char *) const;
        String operator+(const String &) const;
        friend String operator+(const char[], const String &);

        char operator[](const int) const; ///Обращение к i-тому элементу строки

        String &operator=(const char *); ///оператор присвания от строки String str = "hello";
        String &operator=(const char); ///оператор присвания от символа String str = 'A';

        friend std::ostream &operator<<(std::ostream &, const String &); ///вывод строки через поток cout << str;
        friend std::istream &operator>>(std::istream &, const String &); ///чтение строки с потока cin >> str;

        operator char *() const; ///кастомизация строки в char*
        operator int() const; ///попытка перевода строки в число
        operator double() const; ///попытка перевода строки в число
    };

#endif // STRING_H_INCLUDED
