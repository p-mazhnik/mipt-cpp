//
// Created by pavel on 05.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Treap{ //Tree + heap
private:
    int key;
    int priority;
    int size;

    int number;

    Treap *left;
    Treap *right;
public:
    Treap(int key, int priority, int number) : key(key), priority(priority), number(number), size(1), left(NULL), right(NULL){};
    Treap() : left(NULL), right(NULL){};
    ~Treap();

    int get_size() const;
    void resize();

    static Treap* build(std::vector<Treap> &input, int left, int right);

    bool operator()(Treap a, Treap b){
        return(a.key < b.key);
    }

    void print(std::vector<int> &parent, std::vector<int> &left, std::vector<int> &right, int number_parent = 0) const;

    friend Treap *merge(Treap *left, Treap *right);
};

int Treap::get_size() const{
    return (this == NULL) ? 0 : this->size;
}

void Treap::resize(){
    this->size = 1 + this->left->get_size() + this->right->get_size();
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
        left->resize();
        return left;
    }
    else {
        right->left = merge(left, right->left);
        right->resize();
        return right;
    }
}

Treap* Treap::build(std::vector<Treap> &input, int left, int right) {
    if (right == left) {
        return new Treap(input[left].key, input[left].priority, input[left].number);
    }
    int mid = (left + right) / 2;
    Treap* temp_left = build(input, left, mid);
    Treap* temp_right = build(input, mid + 1, right);
    return merge(temp_left, temp_right);
}

void Treap::print(std::vector<int> &parent, std::vector<int> &left, std::vector<int> &right, int number_parent) const {
    if(this == NULL) {
        return;
    }
    if(this->left == NULL) {
        left[this->number] = 0;
    }
    else {
        left[this->number] = this->left->number;
    }
    if(this->right == NULL) {
        right[this->number] = 0;
    }
    else {
        right[this->number] = this->right->number;
    }
    parent[this->number] = number_parent;
    this->left->print( parent, left, right, this->number);
    this->right->print( parent, left, right, this->number);
}

Treap::~Treap() {
    delete left;
    delete right;
}

int main(){
    int N, key, priority;
    std::cin >> N;
    std::vector<Treap> input(N);

    std::vector<int> parent(N + 1);
    std::vector<int> left(N + 1);
    std::vector<int> right(N + 1);
    int i = 1;
    while(i != N + 1){
        std::cin >> key >> priority;
        input[i - 1] = Treap(key, priority, i);
        ++i;
    }
    std::sort(input.begin(), input.end(), Treap());
    Treap* root = Treap::build(input, 0, N - 1);
    std::cout << "YES\n";
    root->print(parent, left, right);
    for (int j = 1; j <= N; ++j) {
        std::cout << parent[j] << ' ' << left[j] << ' ' << right[j] << '\n';
    }
    delete root;
}