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

    int number;

    Treap *left;
    Treap *right;
    Treap(int key, int priority, int number) : key(key), priority(priority), number(number), size(1), left(NULL), right(NULL){};
    Treap() : left(NULL), right(NULL){};
};

int sz(Treap* &x){
    return (x == NULL) ? 0 : x->size;
}

void resize(Treap *& T){
    T->size = 1 + sz(T->left) + sz(T->right);
}

void split(Treap *T, int key, Treap* &left, Treap* &right) {
    if (T == NULL){
        left = right = NULL;
        return;
    }
    else {
        if(key >= T->key) {
            split(T->right, key, T->right, right);
            left = T;
        }
        else {
            split(T->left, key, left, T->left);
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
    if(left->priority < right->priority) {
        left->right = merge(left->right, right);
        resize(left);
        return left;
    }
    else {
        right->left = merge(left, right->left);
        resize(right);
        return right;
    }
}

void insert(Treap* &root, int key, int priority, int number){
    Treap *new_vertex = new Treap(key, priority, number);
    Treap *left, *right;
    split(root, key, left, right);
    root = merge(merge(left, new_vertex), right);
}

void print(Treap* &root, std::vector<int> &parent, std::vector<int> &left, std::vector<int> &right, int number_parent = 0){
    if(root == NULL) {
        return;
    }
    if(root->left == NULL) {
        left[root->number] = 0;
    }
    else {
        left[root->number] = root->left->number;
    }
    if(root->right == NULL) {
        right[root->number] = 0;
    }
    else {
        right[root->number] = root->right->number;
    }
    parent[root->number] = number_parent;
    print(root->left, parent, left, right, root->number);
    print(root->right, parent, left, right, root->number);
}

int main(){
    Treap* root = NULL;
    int N, key, priority;
    std::cin >> N;
    std::vector<int> parent(N + 1);
    std::vector<int> left(N + 1);
    std::vector<int> right(N + 1);
    int i = 1;
    while(i != N + 1){
        std::cin >> key >> priority;
        insert(root, key, priority, i);
        ++i;
    }
    std::cout << "YES\n";
    print(root, parent, left, right);
    for (int j = 1; j <= N; ++j) {
        std::cout << parent[j] << ' ' << left[j] << ' ' << right[j] << '\n';
    }
}