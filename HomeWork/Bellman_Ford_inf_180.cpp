//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> G_matrix;

const int INF = 100000;

int BellmanFord(const G_matrix &g, std::vector<int> &parent){
    std::vector<int> d(g.size());
    for (int k = 0; k < g.size(); ++k) { //INIT
        d[k] = 0;
        parent[k] = 0;
    }

    int accessible_vertex = -1; //вершина, доступная из цикла отриц. веса
    for (int i = 0; i < g.size(); ++i) {
        accessible_vertex = -1;
        for (int vertex = 0; vertex < g.size(); ++vertex) {
            for (int j = 0; j < g.size(); ++j) {
                if (g[j][vertex] < INF) { //RELAX
                    if (d[vertex] > d[j] + g[j][vertex]) {
                        d[vertex] = d[j] + g[j][vertex];
                        parent[vertex] = j;
                        accessible_vertex = vertex;
                    }
                }
            }
        }
    }
    return accessible_vertex;
}

int main(){
    int N;
    std::cin >> N;
    G_matrix g(N, std::vector<int>(N));
    std::vector<int> p(N);

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            std::cin >> g[k][i];
        }
    }
    int accessible_vertex = BellmanFord(g, p);
    if(accessible_vertex != -1){
        int u = accessible_vertex;
        for (int i = 0; i < N; ++i) { //получаем вершину, которая лежит в цикле;
            u = p[u];
        }
        std::vector<int> path;
        for (int current = u; ; current = p[current]) {
            path.push_back(current);
            if (current == u && path.size() > 1)  {
                break;
            }
        }
        reverse (path.begin(), path.end());

        std::cout << "YES\n" << path.size() << '\n';
        for(int i = 0; i < path.size(); ++i) {
            std::cout << path[i] + 1 << ' ';
        }
    } else{
        std::cout << "NO";
    }
}
