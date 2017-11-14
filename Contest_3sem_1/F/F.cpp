//
// Created by pavel on 06.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{
    long long count_left_brackets;
    long long count_right_brackets;
    long long max_length_true;
    Node(){
        max_length_true = 0;
        count_left_brackets = 0;
        count_right_brackets = 0;
    }
    Node(Node a, Node b){
        count_left_brackets = a.count_left_brackets + b.count_left_brackets - min(a.count_left_brackets, b.count_right_brackets);
        count_right_brackets = a.count_right_brackets + b.count_right_brackets - min(a.count_left_brackets, b.count_right_brackets);
        max_length_true = a.max_length_true + b.max_length_true + min(a.count_left_brackets, b.count_right_brackets);
    }
};

class SegmentTree{
private:
    vector<Node> tree;
public:
    SegmentTree(std::string input);

    Node get(long long vertex, long long tree_left, long long tree_right, long long l, long long r);
    void build(std::string &a, long long vertex, long long l, long long r);

};

SegmentTree::SegmentTree(std::string input) {
    tree.resize(4 * (input.size()));
    build(input, 1, 0, input.size() - 1);
}

void SegmentTree::build (std::string &a, long long vertex, long long l, long long r) {
    if (l == r) {
        if(a[l] == '('){
            tree[vertex].count_left_brackets = 1;
            tree[vertex].count_right_brackets = 0;
        }
        else{
            tree[vertex].count_left_brackets = 0;
            tree[vertex].count_right_brackets = 1;
        }
        tree[vertex].max_length_true = 0;
    }
    else {
        long long mid = (l + r) / 2;
        build (a, vertex * 2, l, mid);
        build (a, vertex * 2 + 1, mid + 1, r);
        tree[vertex] = Node(tree[2 * vertex], tree[2 * vertex + 1]);
    }
}

Node SegmentTree::get(long long vertex, long long tree_left, long long tree_right, long long l, long long r) {
    if(tree_left > tree_right){
        return Node();
    }
    if (l > r)
        return Node();
    if (l == tree_left && r == tree_right)
        return tree[vertex];
    long long mid = (tree_left + tree_right) / 2;
    return Node(get(vertex * 2, tree_left, mid, l, min(r, mid)),
                get(vertex * 2 + 1, mid + 1, tree_right, max(l, mid + 1), r));
}

int main() {
    long long M, l, r;
    std::string input;
    std::cin >> input;
    SegmentTree tree(input);
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> l >> r;
        std::cout << 2 * tree.get(1, 0, input.size() - 1, l - 1, r - 1).max_length_true << '\n';
    }
    return 0;
}

/*У Сережи есть скобочная последовательность s1, s2, ..., sn, или, другими словами, строка s длины n, состоящая из символов ( и ).

Сереже нужно ответить на m запросов, каждый из которых характеризуется двумя целыми числами li, ri (1 ≤ li ≤ ri ≤ n). Ответом на i-ый запрос является длина наибольшей правильной скобочной подпоследовательности последовательности sli, sli + 1, ..., sri. Помогите Сереже ответить на все запросы.
Формат входных данных
Первая строка содержит последовательность символов без пробелов s1, s2, ..., sn (1 ≤ n ≤ 106). Каждый символ это либо (, либо ). Вторая строка содержит целое число m (1 ≤ m ≤ 105) количество запросов. Каждая из следующих m строк содержит пару целых чисел. В i-ой строке записаны числа li, ri (1 ≤ li ≤ ri ≤ n) - описание i-го запроса.
Формат результата
Выведите ответ на каждый запрос в отдельной строке. Ответы выводите в порядке следования запросов во входных данных.*/