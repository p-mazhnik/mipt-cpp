#include <iostream>

using namespace std;

struct Node ///узел
{
    int info;
    Node *next;
};

struct Stack
{
    Node *head;
};

void initStack (Stack *s) ///инициализируем *head
{
    s->head = NULL;
}

bool isempty (const Stack *s) ///проверяем, на что ссылается head
{
    return s->head == NULL;
}

void push (int x, Stack *s) ///добавление элемента в стек
{
    Node *n = new Node;
    n->info = x;
    n->next = s->head;
    s->head = n;
}

void pop (Stack *s)
{
    if(!isempty(s)){
        Node *k = s->head->next;
        delete s->head;
        s->head = k;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
