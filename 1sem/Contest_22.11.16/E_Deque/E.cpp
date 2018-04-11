#include <iostream>
#include <string.h>

using namespace std;

struct Node ///узел
{
    int info;
    Node *next;
    Node *prev;
};

struct dek
{
    Node *head;
    Node *tail;
    int d_size;
    dek ();
    bool is_empty ();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    void front();
    void back();
    void clear();
    ~dek();
};

dek::~dek()
{
    this->clear();
}

dek::dek () ///инициализируем *head и *tail
{
    this->head = NULL;
    this->tail = NULL;
    this->d_size = 0;
}

bool dek::is_empty () ///проверяем, на что ссылается head
{
    return (this->head == NULL && this->tail == NULL);
}

void dek::push_back(int x)
{
    Node *n = new Node;
    n->info = x;
    n->next = n->prev = NULL;
    if (this->is_empty()){
        this->tail = this->head = n;
    }
    else {
        this->tail->next = n;
        n->prev = this->tail;
        this->tail = n;
    }
    ++this->d_size;
}

void dek::push_front(int x)
{
    Node *n = new Node;
    n->info = x;
    n->next = n->prev = NULL;
    if (this->is_empty()){
        this->tail = this->head = n;
    }
    else {
        this->head->prev = n;
        n->next = this->head;
        this->head = n;
    }
    ++this->d_size;
}

int dek::pop_front()
{
        if(this->d_size == 1){
            int info = head->info;
            delete this->head;
            this->head = this->tail = NULL;
            --this->d_size;
            return info;
        }
        else{
            Node *k = this->head->next;
            int info = head->info;
            delete this->head;
            this->head = k;
            this->head->prev = NULL;
            --this->d_size;
            return info;
        }
}

int dek::pop_back()
{
        if(this->d_size == 1){
            int info = head->info;
            delete this->head;
            this->head = this->tail = NULL;
            --this->d_size;
            return info;
        }
        else{
            Node *k = this->tail->prev;
            int info = tail->info;
            delete this->tail;
            this->tail = k;
            this->tail->next = NULL;
            --this->d_size;
            return info;
        }
}

void dek::front()
{
    if(!this->is_empty()){
        cout << this->head->info << endl;
    }
    else{
        cout << "error" << endl;
    }
}

void dek::back()
{
    if(!this->is_empty()){
        cout << this->tail->info << endl;
    }
    else{
        cout << "error" << endl;
    }
}

void dek::clear()
{
    while(!this->is_empty()) {
        this->pop_front();
    }
}

int main()
{
    int x;
    dek *d = new dek;
    int m;
    cin >> m;
    char s[11];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "push_front") == 0 || strcmp(s, "push_back") == 0){
            cin >> x;
            (strcmp(s, "push_front") == 0 ? d->push_front(x) : d->push_back(x));
            cout << "ok" << endl;
        }
        if (strcmp(s, "pop_front") == 0 || strcmp(s, "pop_back") == 0){
            if(!d->is_empty()) {
                cout << (strcmp(s, "pop_front") == 0 ? d->pop_front() : d->pop_back()) << endl;
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "front") == 0 || strcmp(s, "back") == 0){
            (strcmp(s, "front") == 0 ? d->front() : d->back());
        }
        if (strcmp(s, "size") == 0){
            cout << d->d_size << endl;
        }
        if (strcmp(s, "clear") == 0){
            d->clear();
            cout << "ok" << endl;
        }
    }
    delete d;
    return 0;
}
