#include <iostream>
#include <string.h>

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
    void pop();
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

void Stack::pop ()
{
    Node *k = this->head->next;
    delete this->head;
    this->head = k;
    --this->st_size;
}

void Stack::clear()
{
    while(!this->is_empty()) {
        this->pop();
    }
}

int main()
{
    int x;
    Stack *MyStack = new Stack;
    int m;
    cin >> m;
    char s[6];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "push") == 0){
            cin >> x;
            MyStack->push(x);
            cout << "ok" << endl;
        }
        if (strcmp(s, "pop") == 0 || strcmp(s, "back") == 0){ ///pop or back
            if(!MyStack->is_empty()){
                cout << MyStack->head->info << endl; ///выводим последний элемент на экран
                if (strcmp(s, "pop") == 0){
                   MyStack->pop();
                }
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "min") == 0){
            if(!MyStack->is_empty()){
                cout << MyStack->head->st_min << endl;
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "size") == 0){
            cout << MyStack->st_size << endl;
        }
        if (strcmp(s, "clear") == 0){
            MyStack->clear();
            cout << "ok" << endl;
        }
    }
    delete MyStack;
    return 0;
}
