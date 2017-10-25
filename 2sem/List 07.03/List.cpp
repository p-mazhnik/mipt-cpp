//
// Created by pavel on 07.03.2017.
//

#include <cstring>
#include <cstdlib>
#include "List.h"

ArrayList::ArrayList(size_t length) {
    set_capacity(length);
    this->length = 0;
}

ArrayList::~ArrayList() {
    delete []this->values;
}

void ArrayList::set_capacity(size_t capacity) {
    this->capacity = capacity;
    this->values = new element[this->capacity];
}

void ArrayList::add(element e) {
    if(this->length >= this->capacity)
    {
        element *old_values = this->values;
        size_t old_capacity = this->capacity;
        set_capacity(this->capacity * 2);
        std::memcpy(this->values, old_values, (old_capacity * sizeof(element)));
        delete []old_values;
    }
    this->values[this->length] = e;
    this->length++;
}

size_t ArrayList::size() {
    return this->length;
}

element ArrayList::get(size_t index) {
    return this->values[index];
}

bool List::contains(element e) {
    for (size_t i = 0; i < size(); ++i) {
        if(get(i) == e)
        {
            return true;
        }
    }
    return false;
}

LinkedList::LinkedList() {
    this->first = 0;
    this->last = 0;
    this->length = 0;
}

void LinkedList::add(element e) {
    if(this->last != 0){
        Node *node = new Node(this->last, 0, e);
        this->last->next = node;
        this->last = node;
    } else{
        Node *node = new Node(0, 0, e);
        this->last = node;
        this->first = node;
    }
    this->length++;
}

size_t LinkedList::size() {
    return this->length;
}

element LinkedList::get(size_t index) {
    Node *iter = this->first;
    while(index > 0)
    {
        iter = iter->next;
        index--;
    }
    return iter->value;
}

element LinkedList::pop() {
    element e = this->last->value;
    Node *new_last = this->last->prev;
    delete this->last;
    this->last = new_last;
    return e;
}

LinkedList::~LinkedList() {
    while (this->last != 0) {
        this->pop();
    }
}

Node::Node(Node *prev, Node *next, element e) :
        prev(prev), next(next), value(e) {}
