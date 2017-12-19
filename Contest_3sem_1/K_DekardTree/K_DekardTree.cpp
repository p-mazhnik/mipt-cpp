//
// Created by pavel on 27.09.2017.
//

#include <iostream>

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

int sz(Treap* &x){
    return (x == NULL) ? 0 : x->size;
}

void resize(Treap *& T){
    T->size = 1 + sz(T->left) + sz(T->right);
}

void split(Treap *T, int x, Treap* &left, Treap* &right) {
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

void erase(Treap* &root, int x){
    if(find(root, x)){
        Treap *left, *right;
        Treap *left_son_of_left, *left_son_of_right;
        split(root, x, left, right);
        split(left, x - 1, left_son_of_left, left_son_of_right);
        root = merge(left_son_of_left, right);
    }
}

void next(Treap* &root, int x){
    Treap *left, *right;
    Treap *k;
    split(root, x, left, right);
    if(right == NULL) {
        std::cout << "none\n";
        return;
    }
    k = right;
    while(k->left != NULL){
        k = k->left;
    }
    std::cout << k->key << "\n";
    root = merge(left, right);
}

void prev(Treap* &root, int x){
    Treap *left, *right;
    Treap *k;
    split(root, x - 1, left, right);
    if(left == NULL) {
        std::cout << "none\n";
        return;
    }
    k = left;
    while(k->right != NULL){
        k = k->right;
    }
    std::cout << k->key << "\n";
    root = merge(left, right);
}

bool kth(Treap* &root, int k){
    if(root == NULL){
        std::cout << "none\n";
        return false;
    }
    if(sz(root->left) == k - 1){
        std::cout << root->key << '\n';
        return true;
    }
    if(sz(root->left) < k - 1){
        return kth(root->right, k - sz(root->left) - 1);
    } else{
        return kth(root->left, k);
    }
}

int main(){
    Treap* root = NULL;
    std::string cmd;
    int x;
    while(std::cin >> cmd){
        std::cin >> x;
        if(cmd == "insert"){
            insert(root, x);
        }
        if(cmd == "delete"){
            erase(root, x);
        }
        if(cmd == "exists"){
            if(find(root, x)) std::cout << "true\n";
            else std::cout << "false\n";
        }
        if(cmd == "next"){
            next(root, x);
        }
        if(cmd == "prev"){
            prev(root, x);
        }
        if(cmd == "kth"){
            kth(root, x);
        }
    }
}