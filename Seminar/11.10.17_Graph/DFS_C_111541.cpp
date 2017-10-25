//
// Created by pavel on 11.10.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> G_matrix;

enum Colors {WHITE, GRAY, BLACK};

void DFS_visit(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, bool &flag);

bool DFS(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time){
    int k = 0;
    bool flag = true;
    for(int u = 1; u <= g.size(); ++u){
        if(col[u] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, u, flag);
            ++k;//кол-во компонент связности
        }
    }
    return (k == 1) && flag;
}

void DFS_visit(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, bool &flag){
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int v = 1, l = 0; v <= g.size(); v++){//пробегаемся по всем смежным вершинам
        if(g[u - 1][v - 1]){
            if(col[v] == WHITE) DFS_visit(g, col, d_time, f_time, time, v, flag);
            else ++l;
        }
        if(l > 1) flag = false;
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
}


int main(){
    int N;
    std::cin >> N;
    G_matrix g(N, std::vector<bool>(N));
    std::vector<Colors> col(N + 1, WHITE);
    std::vector<int> d_time(N + 1);
    std::vector<int> f_time(N + 1);
    int time;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            bool k;
            std::cin >> k;
            g[i][j] = k;
        }
    }
    DFS(g, col, d_time, f_time, time) ? std::cout << "YES" : std::cout << "NO";
}
