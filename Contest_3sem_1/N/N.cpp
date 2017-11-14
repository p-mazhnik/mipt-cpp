//
// Created by pavel on 05.11.2017.
//

#include <iostream>

class Treap{ //Tree + heap
public:
    int key; //key
    int priority; //priority
    int size;

    Treap *left;
    Treap *right;
    Treap(int priority) : key(rand()), priority(priority), size(1), left(NULL), right(NULL){};
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
    if(left->priority < right->priority){
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

void insert(Treap* &root, int x, int i = 0){
    Treap *new_vertex = new Treap(x);
    Treap *left, *right;
    split(root, i, left, right);
    root = merge(merge(left, new_vertex), right);
}

int min(Treap* &root, int i, int j){
    Treap *one, *two;
    Treap *three, *four;
    split(root, j, one, two);
    split(one, i - 1, three, four);
    int result = four->priority;
    root = merge(three, merge(four, two));
    return result;
}

int main(){
    Treap* root = NULL;
    char cmd;
    int n, x, y;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> cmd >> x >> y;
        switch (cmd){
            case '+':
            {
                insert(root, y, x);
                break;
            }
            case '?':
            {
                std::cout << min(root, x, y) << '\n';
                break;
            }
        }
    }
}