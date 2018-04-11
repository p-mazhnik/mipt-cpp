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
    void initStack ();
    void push(int x);
    int pop();
    void clear();
    bool is_empty();
    ~Stack();
    Stack();
};

Stack::Stack()
{
    this->head = NULL; ///инициализируем *head
    this->st_size = 0;
}

Stack::~Stack()
{
    this->clear();
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
    int info = this->head->info;
    Node *k = this->head->next;
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

struct Queue
{
    Stack *st1;
    Stack *st2;
    void copy_st(Stack *st1, Stack *st2, int k);
    void enqueue(int x);
    void clear();
    int window_min(int k);
    Queue();
    ~Queue();
};

Queue::Queue()
{
    this->st1 = new Stack;
    this->st2 = new Stack;
}

Queue::~Queue()
{
    delete this->st1;
    delete this->st2;
}

void Queue::copy_st(Stack *st1, Stack *st2, int k)
{
    for(int i = 0; i < k && !st1->is_empty(); ++i){
        st2->push(st1->pop());
    }
}

void Queue::enqueue (int x) ///добавление элемента в очередь
{
    this->st1->push(x);
}

void Queue::clear()
{
    if(!this->st2->is_empty()){
        this->st2->clear();
    }
    if(!this->st1->is_empty()){
        this->st1->clear();
    }
}

int Queue::window_min(int k) //window
{
    int w;
    if(this->st2->is_empty()){
        this->copy_st(st1, st2, k);
        w = this->st2->head->st_min;
        this->copy_st(st2, st1, k);
        this->st1->pop();
    }
    return w;
}

int main()
{
    int x;
    Queue *q = new Queue;
    int n, k;
    cin >> n >> k;
    int *a = new int[n - k + 1];
    for (int i = 0; i < n; ++i){
        cin >> x;
        q->enqueue(x);
    }
    for(int i = 0; i < n - k + 1; ++i){
        a[i] = q->window_min(k);
    }
    for(int i = n - k; i >= 0; --i){
        cout << a[i] << endl;
    }
    delete q;
    delete []a;
    return 0;
}
/*
7 3
1 3 2 4 5 3 1
*/
