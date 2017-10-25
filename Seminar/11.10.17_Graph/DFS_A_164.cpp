//
// Created by pavel on 11.10.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> G_matrix;

enum Colors {WHITE, GRAY, BLACK};

bool DFS_visit(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, int S, bool);

int DFS(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int time, int S){
    time = 0;
    bool flag = false;
    int vertex = 1;
    for(int u = 1; u <= g.size(); ++u){
        if(col[u] == WHITE){
            if(DFS_visit(g, col, d_time, f_time, time, u, S, flag)) vertex = u;
        }
    }
    return vertex;
}

bool DFS_visit(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, int S, bool flag){
    if(u == S) flag = true;
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int v = 1; v <= g.size(); v++){//пробегаемся по всем смежным вершинам
        if(g[u - 1][v - 1] && col[v] == WHITE){
            flag = DFS_visit(g, col, d_time, f_time, time, v, S, flag);
        }
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
    return flag;
}

int main(){
    int N, S;
    std::cin >> N >> S;
    G_matrix g(N);
    std::vector<Colors> col(N + 1, WHITE);
    std::vector<int> d_time(N + 1);
    std::vector<int> f_time(N + 1);
    int time;
    for(int i = 0; i < N; ++i){
        g[i].resize(N);
        for(int j = 0; j < N; ++j) {
            bool k;
            std::cin >> k;
            g[i][j] = k;
        }
    }
    int vertex = DFS(g, col, d_time, f_time, time, S);
    std::cout << (f_time[vertex] - d_time[vertex] + 1) / 2;
}
