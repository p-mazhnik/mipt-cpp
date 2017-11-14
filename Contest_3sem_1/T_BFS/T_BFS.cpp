//
// Created by pavel on 01.11.2017.
//

#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void BFS(const G_list &g, std::vector<Color> &col, std::vector<int> &parent, int vertex) {
    std::queue<int> q;
    q.push(vertex);
    col[vertex] = GRAY;

    std::vector<int> d_time(g.size());

    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            if (col[g[v][i]] == WHITE) {
                col[g[v][i]] = GRAY;
                d_time[g[v][i]] = d_time[v] + 1;
                parent[g[v][i]] = v;
                q.push(g[v][i]);
            }
        }
    }
    col[vertex] = BLACK;
}

int main(){
    int N, M;
    std::cin >> N >> M;
    int a, b;
    std::cin >> a >> b;
    G_list g(N);

    for (int i, j, k = 0; k < M; ++k) {
        std::cin >> i >> j;
        g[i - 1].push_back(j - 1);
        g[j - 1].push_back(i - 1);
    }

    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> parent(N, -1);

    BFS(g, col, parent, a - 1);

    if (col[b - 1] == WHITE)
        std::cout << -1;
    else {
        std::vector<int> path;
        for (int i = b - 1; i != -1; i = parent[i]) {
            path.push_back(i);
        }
        std::cout << path.size() - 1 << '\n';
        for (int i = path.size() - 1; i >= 0; --i)
            std::cout << path[i] + 1 << ' ';
    }
}
