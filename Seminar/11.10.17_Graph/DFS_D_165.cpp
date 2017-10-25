//
// Created by pavel on 16.10.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> G_matrix;
//typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_matrix &g, std::vector<Color> &col, std::vector<int> &col_2, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, bool &flag, int k);

bool DFS(const G_matrix &g, std::vector<Color> &col, std::vector<int> &col_2, std::vector<int> &d_time, std::vector<int> &f_time, int &time){
    bool flag = true;
    for(int u = 1; u <= g.size(); ++u){
        if(col[u] == WHITE){
            int k = 0;
            DFS_visit(g, col, col_2, d_time, f_time, time, u, flag, k);
        }
    }
    return flag;
}

void DFS_visit(const G_matrix &g, std::vector<Color> &col, std::vector<int> &col_2, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, bool &flag, int k){
    col[u] = GRAY;
    ++k;
    (k % 2) ? col_2[u] = 1 : col_2[u] = 2;
    ++time;
    d_time[u] = time;
    for(int v = 1; v <= g.size(); ++v){//пробегаемся по всем смежным вершинам
        if(g[u - 1][v - 1]){
            if(col[v] == WHITE)DFS_visit(g, col, col_2, d_time, f_time, time, v, flag, k);
            if(col_2[v] == col_2[u]) flag = false;
        }
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_matrix g(N, std::vector<bool> (N));
    std::vector<Color> col(N + 1, WHITE);
    std::vector<int> col_2(N + 1);
    std::vector<int> d_time(N + 1);
    std::vector<int> f_time(N + 1);
    int time = 0;
    for (int k = 0; k < M; ++k) {
        int i, j;
        std::cin >> i >> j;
        g[i - 1][j - 1] = 1;
        g[j - 1][i - 1] = 1;
    }
    if(DFS(g, col, col_2, d_time, f_time, time)){
        std::cout << "YES\n";
        for (int i = 1; i <= col_2.size(); ++i) {
            if(col_2[i] == 1){
                std::cout << i << ' ';
            }
        }
    }
    else std::cout << "NO";
}
