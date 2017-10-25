//
// Created by pavel on 15.10.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> G_matrix;
typedef std::vector<std::vector<int>> G_list;

enum Colors {WHITE, GRAY, BLACK};

void DFS_visit_l(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u);

void DFS(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time){
    for(int u = 1, k = 0; u <= g.size(); ++u){
        if(col[u] == WHITE){
            DFS_visit_l(g, col, d_time, f_time, time, u);
            ++k;//кол-во компонент связности
        }
    }
}

void DFS_visit_l(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u){
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int i = 0; i < g[u - 1].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[u - 1][i]] == WHITE){
            DFS_visit_l(g, col, d_time, f_time, time, g[u - 1][i]);
        }
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
}

void DFS_visit_g(const G_matrix &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u){
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int v = 1; v <= g.size(); v++){//пробегаемся по всем смежным вершинам
        if(g[u - 1][v - 1] && col[v] == WHITE){
            DFS_visit_g(g, col, d_time, f_time, time, v);
        }
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
}
