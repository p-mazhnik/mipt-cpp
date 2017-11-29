//
// Created by pavel on 28.11.2017.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class DSU{
private:
    std::vector<int> tree;
    std::vector<int> rank;
public:
    void make_set(int);
    int find_set (int);
    void union_sets (int a, int b);
    DSU(int n) : tree(n), rank(n){}
};

void DSU::make_set (int v) {
    tree[v] = v;
    rank[v] = 0;
}

int DSU::find_set (int v) {
    if (v == tree[v]) {
        return v;
    }
    return tree[v] = find_set (tree[v]);
}

void DSU::union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b]){
            std::swap (a, b);
        }
        tree[b] = a;
        if (rank[a] == rank[b]) {
            ++rank[a];
        }
    }
}

int main(){
    int N, M, K;
    std::cin >> N >> M >> K ;
    std::string cmd;
    std::stack<std::pair<std::string, std::pair<int, int> > > operations;
    std::stack<std::string> answers;

    DSU system(N);
    for (int j = 0; j < N; ++j) {
        system.make_set(j);
    }
    for (int u, v, i = 0; i < M; ++i) {
        std::cin >> u >> v;
    }
    for (int u, v, k = 0; k < K; ++k) {
        std::cin >> cmd >> u >> v;
        operations.push(std::make_pair(cmd, std::make_pair(u - 1, v - 1)));
    }
    while(!operations.empty()) {
        if(operations.top().first == "ask"){
            if(system.find_set(operations.top().second.first) == system.find_set(operations.top().second.second)){
                answers.push("YES\n");
            } else {
                answers.push("NO\n");
            }
        }
        if(operations.top().first == "cut"){
            system.union_sets(operations.top().second.first, operations.top().second.second);
        }
        operations.pop();
    }
    while(!answers.empty()) {
        std::cout << answers.top();
        answers.pop();
    }
}