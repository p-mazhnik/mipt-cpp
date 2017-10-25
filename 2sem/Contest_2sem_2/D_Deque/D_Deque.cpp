//
// Created by pavel on 08.05.2017.
// Look the task in file "D_Deque.txt"
//

#include <iostream>
#include <algorithm>
#include <deque>
#include <stdexcept>

class DequeEmptyException : std::length_error{
public:
    DequeEmptyException() : std::length_error("DequeEmptyException") {};
};

template <typename value_type>
class Deque : public std::deque<value_type> {
public:
    value_type pop_front();
    value_type pop_back();
    value_type front();
    value_type back();
};

template <typename value_type>
value_type Deque<value_type>::pop_front()
{
    if(this->empty()){
        throw DequeEmptyException();
    }
    value_type result = this->operator[](0);
    this->std::deque<value_type>::pop_front();
    return result;
}

template <typename value_type>
value_type Deque<value_type>::pop_back()
{
    if(this->empty()){
        throw DequeEmptyException();
    }
    value_type result = this->operator[](this->size() - 1);
    this->std::deque<value_type>::pop_back();
    return result;
}

template <typename value_type>
value_type Deque<value_type>::front()
{
    if(this->empty()){
        throw DequeEmptyException();
    }
    return this->std::deque<value_type>::front();
}

template <typename value_type>
value_type Deque<value_type>::back()
{
    if(this->empty()){
        throw DequeEmptyException();
    }
    return this->std::deque<value_type>::back();
}

int main()
{
    int x;
    Deque<int> d;
    int m;
    std::cin >> m;
    std::string s;
    for(int i = 0; i < m; ++i){
        std::cin >> s;
        if (s == "push_front" || s == "push_back"){
            std::cin >> x;
            (s == "push_front" ? d.push_front(x) : d.push_back(x));
            std::cout << "ok" << std::endl;
        }
        if (s == "pop_front" || s == "pop_back"){
            try {
                std::cout << ((s == "pop_front") ? d.pop_front() : d.pop_back()) << std::endl;
            } catch (const DequeEmptyException& ex) {
                std::cout << "error" << std::endl;
            }
        }
        if (s == "front" || s == "back"){
            try {
                std::cout << (s == "front" ? d.front() : d.back()) << std::endl;
            } catch (const DequeEmptyException& ex) {
                std::cout << "error" << std::endl;
            }
        }
        if (s == "size"){
            std::cout << d.size() << std::endl;
        }
        if (s == "clear"){
            d.clear();
            std::cout << "ok" << std::endl;
        }
    }
    return 0;
}