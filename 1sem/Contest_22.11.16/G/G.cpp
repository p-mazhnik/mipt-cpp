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
    int n;
    cin >> n;
    int x;
    Stack *st2 = new Stack;
    int *a = new int [n];
    for(int i = 0; i < n; ++i){
        cin >> x;
        a[i] = x;
    }
    for(int i = 0, j = 1; i < n; ++i){
        st2->push(a[i]);
        if(a[i] == j){
            for(;!st2->is_empty() && st2->head->info == j; ++j){
                j = st2->pop();
            }
        }
    }
    if(!st2->is_empty()){
        cout << 0;
    }
    else{
        for(int i = 0, j = 1, i0 = 0; i < n; ++i){
            st2->push(a[i]);
            if(a[i] == j){
                cout << 1 << ' ' << i + 1 - i0 << endl;
                i0 = i + 1;
                int k;
                for(k = 1; !st2->is_empty() && st2->head->info == j; ++j, ++k){ // 2
                    j = st2->pop();
                }
                cout << 2 << ' ' << k - 1 << endl;
            }
        }
    }
    delete st2;
    delete []a;
    return 0;
}
