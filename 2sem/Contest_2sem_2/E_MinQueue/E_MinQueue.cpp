//
// Created by pavel on 08.05.2017.
// Look the task in file "E_MinQueue.txt"
//

#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
#include <stdexcept>

class MinQueueEmptyException : std::logic_error{
public:
    MinQueueEmptyException() : std::logic_error("MinQueueEmptyException") {};
};

template <typename value_type>
class MinQueue {
    std::stack<std::pair<value_type, value_type> > st1;
    std::stack<std::pair<value_type, value_type> > st2;
    void copy_st(std::stack<std::pair<value_type, value_type> > &st1, std::stack<std::pair<value_type, value_type> > &st2);
public:
    void enqueue(value_type x);
    value_type dequeue();
    value_type front();
    value_type min();
    size_t size();
    void clear();
};

template <typename value_type>
void MinQueue<value_type>::copy_st(std::stack<std::pair<value_type, value_type> > &st1, std::stack<std::pair<value_type, value_type> > &st2)
{
    while(!st1.empty()){
        std::pair<value_type, value_type> it = st1.top();
        value_type st_min;
        st1.pop();
        if (st2.empty() || it.first < st2.top().second){
            st_min = it.first;
        }
        else {
            st_min = st2.top().second;
        }
        st2.push(std::make_pair(it.first, st_min));
    }
    //std::cout << "copy st2 = " << st2.top().first << '\n';
}

template <typename value_type>
void MinQueue<value_type>::enqueue(value_type x) ///добавление элемента в очередь
{
    value_type st_min;
    if (this->st1.empty() || x < this->st1.top().second){
        st_min = x;
    }
    else {
        st_min = this->st1.top().second;
    }
    this->st1.push(std::make_pair(x, st_min));
    //std::cout << "enq st1 = " << st1.top().second << '\n';
}

template <typename value_type>
value_type MinQueue<value_type>::dequeue()
{
    if(!this->st1.empty() && this->st2.empty()){
        copy_st(this->st1, this->st2);
    }
    if(!this->st2.empty()){
        value_type result = this->st2.top().first;
        this->st2.pop();
        return result;
    }
    else {
        throw MinQueueEmptyException();
    }
}

template <typename value_type>
value_type MinQueue<value_type>::front()
{
    if(!this->st1.empty() && this->st2.empty()){
        this->copy_st(this->st1, this->st2);
    }
    if(!this->st2.empty()){
        return this->st2.top().first;
    }
    else {
        throw MinQueueEmptyException();
    }
}

template <typename value_type>
void MinQueue<value_type>::clear()
{
    while(!this->st2.empty()){
        this->st2.pop();
    }
    while(!this->st1.empty()){
        this->st1.pop();
    }
}

template <typename value_type>
value_type MinQueue<value_type>::min()
{
    if(this->st1.empty() && !this->st2.empty()){
        return this->st2.top().second;
    }
    else if(!this->st1.empty() && this->st2.empty()){
        return this->st1.top().second;
    }
    else if(!this->st1.empty() && !this->st2.empty()){
        return std::min(this->st1.top().second, this->st2.top().second);
    }
    else {
        throw MinQueueEmptyException();
    }
}

template <typename value_type>
size_t MinQueue<value_type>::size() {
    return (st1.size() + st2.size());
}

int main()
{
    int x;
    MinQueue<int> q;
    int m;
    std::cin >> m;
    std::string s;
    for(int i = 0; i < m; ++i){
        std::cin >> s;
        if (s == "enqueue"){
            std::cin >> x;
            q.enqueue(x);
            std::cout << "ok" << std::endl;
        }
        if (s == "dequeue"){
            try {
                std::cout << q.dequeue() << std::endl;
            } catch (const MinQueueEmptyException& ex) {
                std::cout << "error" << std::endl;
            }
        }
        if (s == "front"){
            try {
                std::cout << q.front() << std::endl;
            } catch (const MinQueueEmptyException& ex) {
                std::cout << "error" << std::endl;
            }
        }
        if (s == "min"){
            try {
                std::cout << q.min() << std::endl;
            } catch (const MinQueueEmptyException& ex) {
                std::cout << "error" << std::endl;
            }
        }
        if (s == "size"){
            std::cout << q.size() << std::endl;
        }
        if (s == "clear"){
            q.clear();
            std::cout << "ok" << std::endl;
        }
    }
    return 0;
}