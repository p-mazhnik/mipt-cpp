//
// Created by pavel on 06.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{
    long long value;
    Node(){
        value = 0;
    }
};

class SegmentTree{
private:
    vector<Node> tree;
public:
    SegmentTree(vector<long long> a);

    long long get(long long pos, long long vertex, long long tree_left, long long tree_right);
    void build(std::vector<long long> &a, long long vertex, long long l, long long r);
    void update(long long vertex, long long tree_left, long long tree_right, long long l, long long r, long long add);

};

SegmentTree::SegmentTree(vector<long long> a) {
    tree.resize(4 * a.size());
    build(a, 1, 0, a.size() - 1);
}

void SegmentTree::build (std::vector<long long> &a, long long vertex, long long l, long long r) {
    if (l == r) {
        tree[vertex].value = a[l];
    }
    else {
        long long mid = (l + r) / 2;
        build (a, vertex * 2, l, mid);
        build (a, vertex * 2 + 1, mid + 1, r);
    }
}

long long SegmentTree::get(long long pos, long long vertex, long long tree_left, long long tree_right) {
    if (tree_left == tree_right) {
        return tree[vertex].value;
    }
    long long mid = (tree_left + tree_right) / 2;
    if (pos <= mid) {
        return tree[vertex].value + get(pos, vertex * 2, tree_left, mid);
    }
    else {
        return tree[vertex].value + get(pos, vertex * 2 + 1, mid + 1, tree_right);
    }
}

void SegmentTree::update(long long vertex, long long tree_left, long long tree_right, long long l, long long r, long long add) {
    if (l > r)
        return;
    if (l == tree_left && r == tree_right) {
        tree[vertex].value += add;
    } else {
        long long mid = (tree_left + tree_right) / 2;
        update(vertex * 2, tree_left, mid, l, min(r, mid), add);
        update(vertex * 2 + 1, mid + 1, tree_right, max(l, mid + 1), r, add);
    }
}

int main() {
    long long N;
    std::cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    SegmentTree tree(a);
    int k, x, y, add;
    std::cin >> k;
    char cmd;
    for (int i = 0; i < k; ++i) {
        cin >> cmd;
        if(cmd == 'g'){
            cin >> x;
            cout << tree.get(x - 1, 1, 0, N - 1) << '\n';
        }
        if (cmd == 'a') {
            cin >> x >> y >> add;
            tree.update(1, 0, N - 1, x - 1, y - 1, add);
        }
    }
    return 0;
}