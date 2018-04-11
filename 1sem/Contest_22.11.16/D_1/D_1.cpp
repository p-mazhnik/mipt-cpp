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
    void copy_st(Stack *st1, Stack *st2);
    void enqueue(int x);
    void dequeue();
    void clear();
    void q_min();
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

void Queue::copy_st(Stack *st1, Stack *st2)
{
    while(!st1->is_empty()){
        st2->push(st1->pop());
    }
}

void Queue::enqueue (int x) ///добавление элемента в очередь
{
    this->st1->push(x);
}

void Queue::dequeue()
{
    if(!this->st1->is_empty() && this->st2->is_empty()){
        copy_st(this->st1, this->st2);
    }
    if(!this->st2->is_empty()){
       this->st2->pop();
    }
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

void Queue::q_min()
{
    if(this->st1->is_empty() && !this->st2->is_empty()){
        cout << this->st2->head->st_min << endl;
    }
    else if(!this->st1->is_empty() && this->st2->is_empty()){
        cout << this->st1->head->st_min << endl;
    }
    else if(!this->st1->is_empty() && !this->st2->is_empty()){
        cout << min(this->st1->head->st_min, this->st2->head->st_min) << endl;
    }
}

int main()
{
    int x;
    Queue *q = new Queue;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i){
        cin >> x;
        q->enqueue(x);
    }
    for(int i = 0; i < n - k + 1; ++i){
        q->q_min();
        q->dequeue();
        cin >> x;
        q->enqueue(x);
    }
    delete q;
    return 0;
}
