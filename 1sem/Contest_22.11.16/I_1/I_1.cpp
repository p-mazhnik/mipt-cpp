#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node ///узел
{
    int info;
    Node *next;
};

struct Stack
{
    Node *head;
    int st_size;
    void push(int x);
    int pop();
    void clear();
    bool is_empty();
    Stack();
};

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
    Stack **s = new Stack *[n];
    int *flag = new int [n];
    for (int i = 0; i < n; ++i){
        s[i] = new Stack;
        flag[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        for(int j = 0; j < x; ++j){
            int num;
            scanf("%d", &num);
            if ((num != i + 1) && flag[i] != 2){
                flag[i] = 1;
            }
            if (num == i + 1 && flag[i] == 1){
                flag[i] = 2;
            }
            s[i]->push(num);
        }
    }
    if(n != 1){
        if(n == 2){
            int flag1 = 1;
            if((flag[0] && flag[1]) || flag[0] == 2 || flag[1] == 2){
                flag1 = 0;
            }
            if(flag1){
                while(flag[0] && !s[0]->is_empty() && s[0]->head->info == 2){
                    printf("1 2\n");
                    s[1]->push(s[0]->pop());
                    flag[1] = 0;
                }
                while(flag[1] && !s[1]->is_empty() && s[1]->head->info == 1){
                    printf("2 1\n");
                    s[0]->push(s[1]->pop());
                    flag[0] = 0;
                }
            }
            else{
                printf("0\n");
            }
        }
        else{
            for(int i = 1; i < n; ++i){ //складываем все в первый стек
                while (!s[i]->is_empty() && flag[i]){
                    printf("%d 1\n", i + 1);
                    s[0]->push(s[i]->pop());
                    flag[0] = 1;
                }
                if(s[i]->is_empty()){
                    flag[i] = 0;
                }
            }
            int i = 0;
            while (!s[0]->is_empty() && flag[0]){
                if (s[0]->head->info == 1){
                    if(s[0]->st_size == 1){
                        flag[0] = 0;
                    }
                    else{
                        printf("1 2\n");
                        s[1]->push(s[0]->pop());
                        flag[1] = 1;
                        ++i;
                    }
                }
                else{
                    printf("1 %d\n", s[0]->head->info);
                    int k = s[0]->head->info;
                    s[k - 1]->push(s[0]->pop());
                }
            }
            while (!s[1]->is_empty() && flag[1]){ //кидаем элементы из второго в третий и обратно в первый
                if (s[1]->head->info == 1){
                    printf("2 1\n");
                    s[0]->push(s[1]->pop());
                    --i;
                    if(i == 0){
                        flag[1] = 0;
                    }
                }
                else{
                    printf("2 3\n");
                    s[2]->push(s[1]->pop());
                    flag[2] = 1;
                }
            }
            while (flag[2] && !s[2]->is_empty() && s[2]->head->info == 2){ //убираем сверху из 3
                    printf("3 2\n");
                    s[1]->push(s[2]->pop());
            }
        }
    }
    for (int i = 0; i < n; ++i){
        s[i]->clear();
        delete s[i];
    }
    delete []flag;
    delete []s;
    return 0;
}
