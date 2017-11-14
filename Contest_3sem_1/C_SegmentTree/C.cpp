//
// Created by pavel on 06.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class SegmentTree{
private:
    static int Nod(int a, int b);

    vector<int> tree; //НОД
public:
    SegmentTree(vector<int> input);

    int get(int vertex, int tree_left, int tree_right, int l, int r) const;
    void build(std::vector<int> &input, int vertex, int l, int r);

};

int SegmentTree::Nod(int a, int b)
{
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

SegmentTree::SegmentTree(vector<int> input) {
    tree.resize(4 * input.size());
    build(input, 1, 0, input.size() - 1);
}

void SegmentTree::build (std::vector<int> &input, int vertex, int l, int r) {
    if (l == r) {
        tree[vertex] = input[l];
    }
    else {
        int mid = (l + r) / 2;
        build (input, vertex * 2, l, mid);
        build (input, vertex * 2 + 1, mid + 1, r);
        tree[vertex] = Nod(tree[2 * vertex], tree[2 * vertex + 1]);
    }
}

int SegmentTree::get(int vertex, int tree_left, int tree_right, int l, int r) const {
    if (l > r)
        return 0;
    if (l == tree_left && r == tree_right)
        return tree[vertex];
    int mid = (tree_left + tree_right) / 2;
    return Nod (
            get (vertex * 2, tree_left, mid, l, min(r, mid)),
            get (vertex * 2 + 1, mid + 1, tree_right, max(l, mid + 1), r)
    );
}

int main() {
    int N;
    std::cin >> N;
    vector<int> input(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> input[i];
    }
    SegmentTree tree(input);
    int k, x, y;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        std::cout << tree.get(1, 0, N - 1, x - 1, y - 1) << '\n';
    }
    return 0;
}