//
// Created by pavel on 06.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{
    int max;
    int count_max;
    Node(){
        max = -INFINITY;
        count_max = 0;
    }
    Node(Node a, Node b){
        max = std::max(a.max, b.max);
        count_max = (a.max > b.max ? a.count_max : b.count_max);
        if(a.max == b.max) {
            count_max = a.count_max + b.count_max;
        }
    }
};

class SegmentTree{
private:
    vector<Node> tree;
public:
    SegmentTree(vector<int> a);

    Node get(int vertex, int tree_left, int tree_right, int l, int r);
    void build(std::vector<int> &a, int vertex, int l, int r);

};

SegmentTree::SegmentTree(vector<int> a) {
    tree.resize(4 * a.size());
    build(a, 1, 0, a.size() - 1);
}

void SegmentTree::build (std::vector<int> &a, int vertex, int l, int r) {
    if (l == r) {
        tree[vertex].max = a[l];
        tree[vertex].count_max = 1;
    }
    else {
        int mid = (l + r) / 2;
        build (a, vertex * 2, l, mid);
        build (a, vertex * 2 + 1, mid + 1, r);
        tree[vertex] = Node(tree[2 * vertex], tree[2 * vertex + 1]);
    }
}

Node SegmentTree::get(int vertex, int tree_left, int tree_right, int l, int r) {
    if (l > r)
        return Node();
    if (l == tree_left && r == tree_right)
        return tree[vertex];
    int mid = (tree_left + tree_right) / 2;
    return Node(get(vertex * 2, tree_left, mid, l, min(r, mid)), get(vertex * 2 + 1, mid + 1, tree_right, max(l, mid + 1), r));
}

int main() {
    int N;
    std::cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    SegmentTree tree(a);
    int k, x, y;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        std::cout << tree.get(1, 0, N - 1, x - 1, y - 1).max << ' ';
        std::cout << tree.get(1, 0, N - 1, x - 1, y - 1).count_max << '\n';
    }
    return 0;
}