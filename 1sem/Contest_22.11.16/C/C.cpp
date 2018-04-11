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
    void front();
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
       cout << this->st2->pop() << endl;
    }
    else cout << "error" << endl;
}

void Queue::front()
{
    if(!this->st1->is_empty() && this->st2->is_empty()){
        copy_st(this->st1, this->st2);
    }
    if(!this->st2->is_empty()){
       cout << this->st2->head->info << endl;
    }
    else cout << "error" << endl;
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
    else {
        cout << "error" << endl;
    }
}

int main()
{
    int x;
    Queue *q = new Queue;
    int m;
    cin >> m;
    char s[8];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "enqueue") == 0){
            cin >> x;
            q->enqueue(x);
            cout << "ok" << endl;
        }
        if (strcmp(s, "dequeue") == 0){
            q->dequeue();
        }
        if (strcmp(s, "front") == 0){
            q->front();
        }
        if (strcmp(s, "size") == 0){
            if(q->st1->is_empty()){
                cout << q->st2->st_size << endl;
            }
            else if (q->st2->is_empty()){
                cout << q->st1->st_size << endl;
            }
            else {
                cout << q->st1->st_size + q->st2->st_size << endl;
            }
        }
        if (strcmp(s, "clear") == 0){
            q->clear();
            cout << "ok" << endl;
        }
        if (strcmp(s, "min") == 0){
            q->q_min();
        }
    }
    delete q;
    return 0;
}
