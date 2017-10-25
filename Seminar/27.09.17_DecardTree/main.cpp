//
// Created by pavel on 27.09.2017.
//

#include <iostream>

#define sz(x) ((x) == NULL ? 0 : (x)->size)

class Treap{
public:
    int x; //key
    int y; //priority
    int size;

    Treap *left;
    Treap *right;
    Treap(int key) : x(key), y(rand()), size(1), left(NULL), right(NULL){};
    Treap() : left(NULL), right(NULL){};
};

Treap* root;

void resize(Treap *& T){
    T->size = 1 + sz(T->left) + sz(T->right);
}

void split(Treap *T, int x, Treap* &L, Treap* &R) {
    if (T == NULL){
        L = R = NULL;
        return;
    } else{
        if(x >= T->x){
            split(T->right, x, T->right, R);
            L = T;
        } else{
            split(T->left, x, L, T->left);
            R = T;
        }
    }
    resize(T);
}

Treap *merge(Treap *L, Treap *R) {
    if(L == NULL){
        return R;
    }
    if(R == NULL){
        return L;
    }
    if(L->y >= R->y){
        L->right = merge(L->right, R);
        resize(L);
        return L;
    }else{
        R->left = merge(L, R->left);
        resize(R);
        return R;
    }
}

bool find(Treap *T, int x){
    if(T == NULL){
        return false;
    }
    if(T->x == x){
        return true;
    }
    if(T->x < x){
        return find(T->right, x);
    } else{
        return find(T->left, x);
    }
}

void insert(int x){
    if(!find(root, x)){
        Treap *new_vertex = new Treap(x);
        Treap *l, *r;
        split(root, x, l, r);
        root = merge(merge(l, new_vertex), r);
    }
}

void erase(int x){
    if(find(root, x)){
        //Treap *new_vertex = new Treap(x);
        Treap *l, *r;
        Treap *l_l, *l_r;
        split(root, x, l, r);
        split(l, x - 1, l_l, l_r);
        root = merge(l_l, r);
    }
}

void next(int x){
    Treap *l, *r;
    Treap *k;
    split(root, x, l, r);
    if(r == NULL) {
        std::cout << "none\n";
        return;
    }
    k = r;
    while(k->left != NULL){
        k = k->left;
    }
    std::cout << k->x << "\n";
    root = merge(l, r);
}

void prev(int x){
    Treap *l, *r;
    Treap *k;
    split(root, x - 1, l, r);
    if(l == NULL) {
        std::cout << "none\n";
        return;
    }
    k = l;
    while(l->right != NULL){
        k = k->right;
    }
    std::cout << k->x << "\n";
    root = merge(l, r);
}

bool kth(int k){
    if(root == NULL){
        return false;
    }
    if(root->x == k){
        return true;
    }
    if(root->x < k){
        return kth(root->right, k);
    } else{
        return kth(T->left, x);
    }
}

int main(){
    std::string cmd1 = "insert";
    std::string cmd2 = "delete";
    std::string cmd3 = "exists";
    std::string cmd4 = "exit";
    std::string cmd5 = "next";
    std::string cmd6 = "prev";
    std::string cmd7 = "kth";
    std::string cmd;
    int x;
    while(std::cin >> cmd){
        std::cin >> x;
        if(cmd == cmd1){
            insert(x);
        }
        if(cmd == cmd2){
            erase(x);
        }
        if(cmd == cmd3){
            if(find(root, x)) std::cout << "true\n";
            else std::cout << "false\n";
        }
        if(cmd == cmd5){
            next(x);
        }
        if(cmd == cmd6){
            prev(x);
        }
    }
}