#include <iostream>
#include <string.h>

using namespace std;

struct Node ///узел
{
    char info;
    Node *next;
    int st_min;
};

struct Stack
{
    Node *head;
    int st_size;
    void push(int x);
    char pop();
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

char Stack::pop ()
{
    Node *k = this->head->next;
    char info = this->head->info;
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
    Stack *br = new Stack;
    char s[100000];
    cin.getline(s, 100001);
    int i;
    for(i = 0; s[i] != 0 && !(br->is_empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')); ++i){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            br->push(s[i]);
           }
        if(!br->is_empty() && ((s[i] == ')' && br->head->info == '(') || (s[i] == '}' && br->head->info == '{') || (s[i] == ']' && br->head->info == '['))){
            br->pop();
        }
    }
    if(br->is_empty() && s[i] == 0){
        cout << "yes";
    }
    else {
        cout << "no";
    }
    delete br;
    return 0;
}
