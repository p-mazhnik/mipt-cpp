//
// Created by pavel on 07.03.2017.
//

#ifndef MIPT_CPP_COLLECTION_H
#define MIPT_CPP_COLLECTION_H

typedef int element;

class List {
public:
    bool contains(element e);

    virtual size_t size() = 0; //0 означает, что метод ДОЛЖЕН быть переопределен у потомков!
    virtual void add(element e) = 0;
    virtual element get(size_t index) = 0;
};

class ArrayList: public List {
private:
    element *values;
    size_t length;
    size_t capacity;

    void set_capacity (size_t capacity);
public:
    ArrayList(size_t length);
    ~ArrayList();
    void add(element e);
    size_t size();
    element get(size_t index);
};

struct Node{
    element value;
    Node *next;
    Node *prev;
    Node(Node *prev, Node *next, element e);
};

class LinkedList: public List {
private:
    Node *first;
    Node *last;
    size_t length;
public:
    void add(element e);
    size_t size();
    element get(size_t index);

    element pop();

    LinkedList();
    ~LinkedList();
};


#endif //MIPT_CPP_LIST_H
