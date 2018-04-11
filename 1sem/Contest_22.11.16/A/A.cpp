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
};

void initStack (Stack *s) ///инициализируем *head
{
    s->head = NULL;
    s->st_size = 0;
}

bool isempty (const Stack *s) ///проверяем, на что ссылается head
{
    return s->head == NULL;
}

void push (int x, Stack *s) ///добавление элемента в стек
{
    Node *n = new Node;
    if (isempty(s) || x < s->head->st_min){
        n->st_min = x;
    }
    else {
        n->st_min = s->head->st_min;
    }
    n->info = x;
    n->next = s->head;
    s->head = n;
    ++s->st_size;
}

void pop (Stack *s)
{
    Node *k = s->head->next;
    delete s->head;
    s->head = k;
    --s->st_size;
}

int main()
{
    int x;
    Stack *MyStack = new Stack;
    initStack(MyStack);
    int m;
    cin >> m;
    char s[6];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "push") == 0){
            cin >> x;
            push(x, MyStack);
            cout << "ok" << endl;
        }
        if (strcmp(s, "pop") == 0 || strcmp(s, "back") == 0){ ///pop or back
            if(!isempty(MyStack)){
                cout << MyStack->head->info << endl; ///выводим последний элемент на экран
                if (strcmp(s, "pop") == 0){
                   pop(MyStack);
                }
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "min") == 0){
            if(!isempty(MyStack)){
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
            while(!isempty(MyStack)) {
                 pop(MyStack);
            }
            cout << "ok" << endl;
        }
    }
    delete MyStack;
    return 0;
}
