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
};

void initQueue (Queue *q) ///инициализируем *head
{
    q->head = NULL;
    q->tail = NULL;
    q->q_size = 0;
}

bool isempty (const Queue *q) ///проверяем, на что ссылается head
{
    return q->head == NULL;
}

void enqueue (int x, Queue *q) ///добавление элемента в очередь
{
    Node *n = new Node;
    n->info = x;
    n->next = NULL;
    if (isempty(q)){
        q->tail = q->head = n;
    }
    else {
        q->tail->next = n;
        q->tail = n;
    }
    ++q->q_size;
}

void dequeue (Queue *q) ///delete element
{
    Node *k = q->head->next;
    delete q->head;
    q->head = k;
    --q->q_size;
}

int main()
{
    int x;
    Queue *MyQueue = new Queue;
    initQueue(MyQueue);
    int m;
    cin >> m;
    char s[8];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "enqueue") == 0){
            cin >> x;
            enqueue(x, MyQueue);
            cout << "ok" << endl;
        }
        if (strcmp(s, "dequeue") == 0 || strcmp(s, "front") == 0){ ///dequeue or front
            if(!isempty(MyQueue)){
                cout << MyQueue->head->info << endl; ///выводим последний элемент на экран
                if (strcmp(s, "dequeue") == 0){
                   dequeue(MyQueue);
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
            while(!isempty(MyQueue)) {
                 dequeue(MyQueue);
            }
            cout << "ok" << endl;
        }
    }
    delete MyQueue;
    return 0;
}
