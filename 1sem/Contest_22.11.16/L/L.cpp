#include <iostream>
#include <string.h>

using namespace std;

struct Node ///узел
{
    int info;
    Node *next;
};

struct Queue
{
    Node *head;
    Node *tail;
    Node *after;
    int i;
    int q_size;
    Queue ();
    bool is_empty ();
    void enqueue (int x);
    int dequeue ();
    void insert(int info);
    void clear();
    void mid();
    ~Queue();
};

Queue::~Queue()
{
    this->clear();
}

Queue::Queue () ///инициализируем *head и *tail
{
    this->head = NULL;
    this->tail = NULL;
    this->i = 1;
    this->q_size = 0;
}

bool Queue::is_empty () ///проверяем, на что ссылается head
{
    return this->head == NULL;
}

void Queue::enqueue (int x) ///добавление элемента в очередь
{
    Node *n = new Node;
    n->info = x;
    n->next = NULL;
    if (this->is_empty()){
        this->after = this->tail = this->head = n;
        i = 1;
    }
    else {
        this->tail->next = n;
        this->tail = n;
    }
    ++this->q_size;
}

int Queue::dequeue () ///delete element
{
    Node *k = this->head->next;
    int info = this->head->info;
    delete this->head;
    this->head = k;
    --this->q_size;
    this->after = this->head;
    i = 1;
    return info;
}

void Queue::clear ()
{
    while(!this->is_empty()) {
        this->dequeue();
    }
}

void Queue::insert(int info)
{
    this->mid();
    Node *n = new Node;
    n->info = info;
    if(after == this->head && this->q_size == 1){
        this->enqueue(info);
    }
    else{
        n->next = after->next;
        after->next = n;
        ++this->q_size;
    }

}

void Queue::mid()
{
    for(; i < this->q_size / 2.; ++i){
        this->after = this->after->next;
    }
}

int main()
{
    int x;
    Queue *q = new Queue;
    int m;
    cin >> m;
    char s;
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (s == '+'){
            cin >> x;
            q->enqueue(x);
        }
        if (s == '-'){
            cout << q->dequeue() << endl;
        }
        if (s == '*'){
            cin >> x;
            if(!q->is_empty()){
                q->insert(x);
            }
            else{
                q->enqueue(x);
            }
        }
    }
    delete q;
    return 0;
}
