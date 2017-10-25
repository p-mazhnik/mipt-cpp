//
// Created by pavel on 15.10.2017.
//

#include <iostream>
#include <vector>

//typedef std::vector<std::vector<bool>> G_matrix;
typedef std::vector<std::vector<int>> G_list;

enum Colors {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u);

int DFS(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time){
    int k = 0;
    for(int u = 1; u <= g.size(); ++u){
        if(col[u] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, u);
            ++k;//кол-во компонент связности
        }
    }
    return k;
}

void DFS_visit(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u){
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int i = 0; i < g[u - 1].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[u - 1][i]] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, g[u - 1][i]);
        }
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
}

int main(){
    int N, M;
    std::cin >> M >> N;
    std::vector<std::vector<int> > input(M, std::vector<int> (N));
    int k = 0;
    char c = '#';
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> c;
            if(c == '#') {
                ++k;
                input[i][j] = k;
            }
        }
    }
    G_list g(k);
    std::vector<Colors> col(k + 1, WHITE);
    std::vector<int> d_time(k + 1);
    std::vector<int> f_time(k + 1);
    int time = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if(input[i][j]) {
                if (j > 0 && input[i][j - 1]) g[input[i][j] - 1].push_back(input[i][j - 1]);
                if (j < (N - 1) && input[i][j + 1]) g[input[i][j] - 1].push_back(input[i][j + 1]);
                if (i > 0 && input[i - 1][j]) g[input[i][j] - 1].push_back(input[i - 1][j]);
                if (i < (M - 1) && input[i + 1][j]) g[input[i][j] - 1].push_back(input[i + 1][j]);
            }
        }
    }
    std::cout << DFS(g, col, d_time, f_time, time) << '\n';
}
