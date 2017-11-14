//
// Created by pavel on 05.11.2017.
//

#include <iostream>

class Treap{ //Tree + heap
public:
    long long key; //key
    int priority; //priority
    int size;
    long long sum;

    Treap *left;
    Treap *right;
    Treap(long long key) : key(key), priority(rand()), size(1), sum(key), left(NULL), right(NULL){};
    Treap() : left(NULL), right(NULL){};
};

    int sz(Treap* &x){
    return (x == NULL) ? 0 : x->size;
}

long long get_sum(Treap *&x){
    return (x == NULL) ? 0 : x->sum;
}

void resize(Treap *& T){
    T->size = 1 + sz(T->left) + sz(T->right);
    T->sum = get_sum(T->left) + get_sum(T->right) + T->key;
}

void split(Treap *T, long long x, Treap* &left, Treap* &right) {
    if (T == NULL){
        left = right = NULL;
        return;
    } else{
        if(x >= T->key){
            split(T->right, x, T->right, right);
            left = T;
        } else{
            split(T->left, x, left, T->left);
            right = T;
        }
    }
    resize(T);
}

Treap *merge(Treap *left, Treap *right) {
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    if(left->priority >= right->priority){
        left->right = merge(left->right, right);
        resize(left);
        return left;
    }
    else{
        right->left = merge(left, right->left);
        resize(right);
        return right;
    }
}

bool find(Treap *T, long long x){
    if(T == NULL){
        return false;
    }
    if(T->key == x){
        return true;
    }
    if(T->key < x){
        return find(T->right, x);
    } else{
        return find(T->left, x);
    }
}

void insert(Treap* &root, long long x){
    if(!find(root, x)){
        Treap *new_vertex = new Treap(x);
        Treap *left, *right;
        split(root, x, left, right);
        root = merge(merge(left, new_vertex), right);
    }
}

long long sum(Treap* &root, int l, int r){
    Treap *temp_left, *temp_right;
    Treap *left, *right;
    split(root, r, temp_left, temp_right);
    split(temp_left, l - 1, left, right);
    long long result = get_sum(right);
    root = merge(merge(left, right), temp_right);
    return result;
}

int main(){
    Treap* root = NULL;
    char cmd;
    int n, x, y;
    long long sum_x_y;
    int request_number = 1;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> cmd;
        switch (cmd){
            case '+':
            {
                std::cin >> x;
                if(request_number == 1){
                    insert(root, x);
                }
                else {
                    insert(root, (x + sum_x_y) % 1000000000);
                }
                request_number = 1;
                break;
            }
            case '?':
            {
                std::cin >> x >> y;
                sum_x_y = sum(root, x, y);
                std::cout << sum_x_y << '\n';
                request_number = 2;
                break;
            }
        }
    }
}