//
// Created by pavel on 11.04.2017.
//

#include <iostream>

template <typename U>
class Function;

template <typename return_type, typename ... argument_type>
class Function <return_type (argument_type ...)> {
private:
    class F{ //abstract
    protected:
        void empty(){};
    public:
        virtual F *get_copy() const = 0;
        virtual return_type execute(argument_type ... args) = 0; //результат работы функции
    };
    template <typename T>
    class Simple : public F{
    private:
        T primary_func;
    public:
        Simple() : primary_func(this->empty) {};
        Simple(T func) : primary_func(func) {};

        T &operator=(const Simple<T> &that);

        return_type execute(argument_type... args){ return this->primary_func(args ...); }
        F *get_copy() const{ return (new Simple<T>(this->primary_func)); }; //создаёт копию хранимой внутри класса функции
    };
    template <typename return_type_2, typename ...argument_type_2>
    class Compose : public F{
    private:
        Function<return_type(argument_type_2...)> first_func;
        Function<return_type_2(argument_type...)> second_func;
    public:
        Compose(Function<return_type(argument_type_2...)> f1, Function<return_type_2(argument_type...)> f2)
                : first_func(f1), second_func(f2){};
        return_type execute(argument_type ... args){ return first_func(second_func(args...)); };
        F *get_copy() const {return new Compose<return_type_2, argument_type_2...>(first_func, second_func);};
    };
    bool capacity;
    F *storage;
public:
    Function(): capacity(0) {};
    template <typename T>
    Function(T f) : storage(new Simple<T>(f)), capacity(1) {}; //конструктор от обычной функции
    Function(const Function &that) : storage(that.storage->get_copy()), capacity(1) {};

    template <typename return_type_2, typename ...argument_type_2>
    Function(Function<return_type(argument_type_2...)> f, Function<return_type_2(argument_type...)> g)
        : storage (new Compose<return_type_2, argument_type_2...>(f, g)), capacity(1) {};

    ~Function();

    return_type operator ()(argument_type ... args);

    Function &operator=(const Function &);

    template <typename return_type_2, typename ...argument_type_2>
    friend Function<return_type (argument_type_2...)> operator*(Function <return_type (argument_type ...)> f,
                                                       Function<return_type_2 (argument_type_2...)> g){
        Function<return_type (argument_type_2...)> h(f, g);
        return h;
    };
};

//Simple

template <typename return_type, typename ... argument_type>
template <typename T>
T &Function<return_type(argument_type...)>::Simple<T>::operator=(
        const Function<return_type(argument_type...)>::Simple<T> &that) {
    this->primary_func = that.primary_func;
    return *this;
}

//Function

template <typename return_type, typename ... argument_type>
Function<return_type(argument_type...)>::~Function() {
    if(this->capacity) delete this->storage;
}

template <typename return_type, typename ... argument_type>
return_type Function<return_type(argument_type...)>::operator()(argument_type... args){
    return this->storage->execute(args ...);
}

template <typename return_type, typename ... argument_type>
Function<return_type(argument_type...)> &Function<return_type(argument_type...)>::operator=(const Function &that) {
    if(this->capacity) delete this->storage;
    if(that.capacity){
        this->storage = that.storage->get_copy();
        this->capacity = 1;
    }
    return *this;
}

//main

typedef long type;

int f_1(type x, int y) {
    return x + y;
}

double f_2(int x) {
    return x * 2;
}

float f_3(int x){
    return (float)x / 1000;
}

int main() {
    Function<int(type, int)> f(f_1);
    Function<double (int)> g;
    g = f_2;
    Function<double (type, int)> k(f);
    k = (g * f);
    std::cout << "f:       " << (f)(10, 20) << std::endl;
    std::cout << "g:       " << (g)(10) << std::endl;
    std::cout << "(g * f): " << (k)(10, 20) << std::endl;
    std::cout << "f_3 * g * g * k: " <<  (f_3 * g * g * k)(10, 20) << std::endl;
    std::cout << "f_3 * g * g * k: " <<  (f_2 * g * f)(10, 20) << std::endl;
    return 0;
}