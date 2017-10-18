//
// Created by pavel on 06.09.2017.
//

#include <iostream>

template <class T, class Cmp = std::less<T> >
class BinarySearchTree{
public:
    struct Node {
        /*Node *left = nullptr; ///11 стандрт
        Node *right = nullptr;*/
        Node *left;
        Node *right;
        T value;

        Node(T value) {
            this->value = value;
        }
    };
        void Insert(const T &elem);
private:
    Node *root;
    bool insert(Node *node, const T &element);
};

template <class T, class Cmp = std::less<T> >
bool BinarySearchTree::insert(Node *node, const T &element) {
    if(Cmp(element, node->value)) {
        if(node->left != nullptr) {
            insert(node->left, element);
        }
        else {
            node->left = new Node(element);
            return true;
        }
    }
    else {
        if(node->right != nullptr) insert(node->right, element);
        else {
            node->right = new Node(element);
            return true;
        }
    }
}

template <class T, class Cmp = std::less<T> >
void BinarySearchTree::Insert(const T &elem) {
    if(!root) {
        root = new Node(elem);
        return;
    }
    insert(root, elem);

}

template <class T, class Cmp = std::less<T> >
bool Erase(const T &elem){

}


int main(){

}