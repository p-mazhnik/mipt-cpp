//
// Created by pavel on 05.11.2017.
//

#include <iostream>
#include <vector>

class Treap{ //Tree + heap
public:
    int key; //key
    int priority; //priority
    int size;

    Treap *left;
    Treap *right;
    Treap(int key) : key(key), priority(rand()), size(1), left(NULL), right(NULL){};
    Treap() : left(NULL), right(NULL){};
};

int get_size(Treap *&x){
    return (x == NULL) ? 0 : x->size;
}

void resize(Treap *& T){
    T->size = 1 + get_size(T->left) + get_size(T->right);
}

void split(Treap *T, int x, Treap* &left, Treap* &right, int size = 1) {
    if (T == NULL){
        left = right = NULL;
        return;
    }
    else{
        int key = size + get_size(T->left);
        if(x >= key){
            split(T->right, x, T->right, right, key + 1);
            left = T;
        } else{
            split(T->left, x, left, T->left, size);
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
    }else{
        right->left = merge(left, right->left);
        resize(right);
        return right;
    }
}

bool find(Treap *T, int x){
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

void insert(Treap* &root, int x){
    if(!find(root, x)){
        Treap *new_vertex = new Treap(x);
        Treap *left, *right;
        split(root, x, left, right);
        root = merge(merge(left, new_vertex), right);
    }
}

void print(Treap* &root){
    if(root == NULL) {
        return;
    }
    print(root->left);
    std::cout << root->key << ' ';
    print(root->right);
}

void transposition(Treap* &root, int l, int r){
    Treap *one, *two;
    Treap *three, *four;
    split(root, r, one, two);
    split(one, l - 1, three, four);
    root = merge(four, merge(three, two));
}

int main(){
    Treap* root = NULL;
    int n, m;
    std::cin >> n >> m;
    int l, r;
    for (int i = 0; i < n; ++i) {
        insert(root, i + 1);
    }
    for (int j = 0; j < m; ++j) {
        std::cin >> l >> r;
        transposition(root, l, r);
    }
    print(root);
}