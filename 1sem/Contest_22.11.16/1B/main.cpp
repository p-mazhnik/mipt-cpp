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
    int q_size;
    Queue ();
    bool is_empty ();
    void enqueue (int x);
    void dequeue ();
    void clear();
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
        this->tail = this->head = n;
    }
    else {
        this->tail->next = n;
        this->tail = n;
    }
    ++this->q_size;
}

void Queue::dequeue () ///delete element
{
    Node *k = this->head->next;
    delete this->head;
    this->head = k;
    --this->q_size;
}

void Queue::clear ()
{
    while(!this->is_empty()) {
        this->dequeue();
    }
}

int main()
{
    int x;
    Queue *MyQueue = new Queue;
    int m;
    cin >> m;
    char s[8];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "enqueue") == 0){
            cin >> x;
            MyQueue->enqueue(x);
            cout << "ok" << endl;
        }
        if (strcmp(s, "dequeue") == 0 || strcmp(s, "front") == 0){ ///dequeue or front
            if(!MyQueue->is_empty()){
                cout << MyQueue->head->info << endl; ///выводим последний элемент на экран
                if (strcmp(s, "dequeue") == 0){
                   MyQueue->dequeue();
                }
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "size") == 0){
            cout << MyQueue->q_size << endl;
        }
        if (strcmp(s, "clear") == 0){
            MyQueue->clear();
            cout << "ok" << endl;
        }
    }
    delete MyQueue;
    return 0;
}
