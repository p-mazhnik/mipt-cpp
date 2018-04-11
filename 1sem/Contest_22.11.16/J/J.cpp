#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node ///узел
{
    int info;
    Node *next;
    int st_min;
};

struct Stack
{
    Node *head;
    int st_size;
    void push(int x);
    int pop();
    void clear();
    bool is_empty();
    ~Stack();
    Stack();
};

Stack::~Stack()
{
    this->clear();
}

Stack::Stack () ///инициализируем *head
{
    this->head = NULL;
    this->st_size = 0;
}

bool Stack::is_empty () ///проверяем, на что ссылается head
{
    return this->head == NULL;
}

void Stack::push (int x) ///добавление элемента в стек
{
    Node *n = new Node;
    if (is_empty() || x < this->head->st_min){
        n->st_min = x;
    }
    else {
        n->st_min = this->head->st_min;
    }
    n->info = x;
    n->next = this->head;
    this->head = n;
    ++this->st_size;
}

int Stack::pop ()
{
    Node *k = this->head->next;
    int info = this->head->info;
    delete this->head;
    this->head = k;
    --this->st_size;
    return info;
}

void Stack::clear()
{
    while(!this->is_empty()) {
        this->pop();
    }
}

int main()
{
    Stack *br = new Stack;
    char s[100000];
    int a = 0;
    cin.getline(s, 100001);
    for(int i = 0; s[i] != 0; ++i){
        if(s[i] == '+'){
            br->push(br->pop() + br->pop());
        }
        else if(s[i] == '-'){
            br->push(a - br->pop() + br->pop());
        }
        else if(s[i] == '*'){
            br->push(br->pop() * br->pop());
        }
        else if(s[i] != ' '){
            br->push(s[i] - '0');
        }
    }
    cout << br->head->info;
    delete br;
    return 0;
}
/*
8 9 + 1 7 - *
*/
