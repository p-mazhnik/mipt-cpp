//
// Created by pavel on 19.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> G_matrix;

void print(const std::vector<int> &parent, int StartVertex, int finishVertex) {
    if(finishVertex == StartVertex){
        std::cout << finishVertex + 1 << ' ';
        return;
    }
    print(parent, StartVertex, parent[finishVertex]);
    std::cout << finishVertex + 1 << ' ';
}

void Dijkstra(const G_matrix &g, std::vector<int> &parent, int StartVertex){
    std::vector<int> d (g.size(), -1);
    std::vector<bool> usage(g.size(), false);
    d[StartVertex] = 0;
    parent[StartVertex] = StartVertex;
    for (int i = 0; i < g.size(); ++i) {
        int new_vertex = -1;
        for (int j = 0; j < g.size(); ++j) {
            if (!usage[j] && d[j] != -1 && (new_vertex == -1 || d[j] < d[new_vertex])) {
                new_vertex = j;
            }
        }
        if (new_vertex == -1) {
            break;
        }
        usage[new_vertex] = true;
        for (int j = 0; j < g.size(); ++j) {
            int len = g[new_vertex][j];
            if (len != -1 && (d[new_vertex] + len < d[j] || d[j] == -1)) { //релаксация
                d[j] = d[new_vertex] + len;
                parent[j] = new_vertex;
            }
        }
    }
}

int main(){
    int N, StartVertex, FinishVertex;
    std::cin >> N >> StartVertex >> FinishVertex;
    G_matrix g(N, std::vector<int>(N));
    std::vector<int> parent(N, -1);
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            std::cin >> g[k][i];
        }
    }
    Dijkstra(g, parent,  StartVertex - 1);
    if(parent[FinishVertex - 1] == -1) {
        std::cout << -1;
    } else {
        print(parent, StartVertex - 1, FinishVertex - 1);
    }
    //system("pause");
}