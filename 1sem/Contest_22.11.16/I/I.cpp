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
    void push(int x);
    int pop();
    void clear();
    bool is_empty();
    ~Stack();
    Stack();
};

Stack::~Stack()
{
    //this->clear();
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

int Stack::pop ()
{
    Node *k = this->head->next;
    int info = this->head->info;
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
    int n;
    cin >> n;
    if(n != 1){
        Stack **s = new Stack *[n];
        int flag1 = 1;
        int *flag = new int [n + 2];
        for (int i = 0; i < n; ++i){
            s[i] = new Stack;
            flag[i] = 0;
        }
        flag[0] = 0;
        flag[1] = 0;
        flag[2] = 0;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            for(int j = 0; j < x; ++j){
                int num;
                cin >> num;
                if(num > n) {
                    flag1 = 0;
                }
                if (!s[i]->is_empty() && (s[i]->head->info != num || num != i + 1)){
                    flag[i] = 1;
                }
                s[i]->push(num);
            }
        }
        if(n == 2){
            if(flag[0] && flag[1]){
                flag1 = 0;
            }
            else{
                if(flag[0]){
                    Node* k = new Node;
                    k = s[0]->head;
                    for(int i = 0;  k != 0; ++i, k = k->next){
                        if(k->info == 1){
                            flag[0] = 0;
                        }
                        if(k->info == 2 && !flag[0]){
                            flag1 = 0;
                            flag[0] = 1;
                        }
                    }
                    delete k;
                }
                else{
                    Node* k = new Node;
                    k = s[1]->head;
                    for(int i = 0; k != 0; ++i, k = k->next){
                        if(k->info == 2){
                            flag[1] = 0;
                        }
                        if(k->info == 1 && !flag[1]){
                            flag1 = 0;
                            flag[1] = 1;
                        }
                    }
                    delete k;
                }
            }
        }
        if(flag1){
        for (int i = 1; i < n; ++i){ //складываем все в первый стек
            while (flag[i] && !s[i]->is_empty()){
                cout << i + 1 << '1' << endl;
                s[0]->push(s[i]->pop());
                flag[0] = 1;
            }
        }
        while (flag[0] && !s[0]->is_empty()){
            if (s[0]->head->info == 1){
                if (s[0]->st_size == 1){
                    flag[0] = 0;
                }
                else{
                    cout << "1 2" << endl;
                    s[1]->push(s[0]->pop());
                    flag[1] = 1;
                }
            }
            else{
                cout << "1 " << s[0]->head->info << endl;
                int k = s[0]->head->info;
                s[k - 1]->push(s[0]->pop());
            }
        }
        while (flag[1] && !s[1]->is_empty()){ //кидаем элементы из второго в третий и обратно в первый
            if (s[1]->head->info == 1){
                s[0]->push(s[1]->pop());
                cout << "2 1" << endl;
            }
            else if (n > 2){
                cout << "2 3" << endl;
                s[2]->push(s[1]->pop());
                flag[2] = 1;
            }
        }
        while (flag[2] && !s[2]->is_empty() && s[2]->head->info == 2){ //убираем сверху из 3
                cout << "3 2" << endl;
                s[1]->push(s[2]->pop());
        }
        }
        else {
            cout << '0';
        }
        for (int i = 0; i < n; ++i){
            s[i]->clear();
            delete []s[i];
        }
        delete []s;
        delete []flag;
    }
    return 0;
}
