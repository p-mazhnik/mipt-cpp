//
// Created by pavel on 11.10.2017.
//

#include <iostream>
#include <vector>

//typedef std::vector<std::vector<bool>> G_matrix;
typedef std::vector<std::vector<int>> G_list;

enum Colors {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, std::vector<std::vector<int>> &answer, const int &k);

void DFS(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, std::vector<std::vector<int>> &answer){
    for(int u = 1, k = 0; u <= g.size(); ++u){
        if(col[u] == WHITE){
            answer.push_back(std::vector<int> ());
            DFS_visit(g, col, d_time, f_time, time, u, answer, k);
            answer[k].push_back(u);
            ++k;
        }
    }
}

void DFS_visit(const G_list &g, std::vector<Colors> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, std::vector<std::vector<int>> &answer, const int &k){
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int i = 0; i < g[u - 1].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[u - 1][i]] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, g[u - 1][i], answer, k);
            answer[k].push_back(g[u - 1][i]);
        }
    }
    col[u] = BLACK;
    ++time;
    f_time[u] = time;
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_list g(N);
    std::vector<Colors> col(N + 1, WHITE);
    std::vector<int> d_time(N + 1);
    std::vector<int> f_time(N + 1);
    int time = 0;
    for (int k = 0; k < M; ++k) {
        int i, j;
        std::cin >> i >> j;
        g[i - 1].push_back(j);
        g[j - 1].push_back(i);
    }
    std::vector<std::vector<int>> answer;
    DFS(g, col, d_time, f_time, time, answer);
    std::cout << answer.size() << '\n';
    for(int i = 0; i < answer.size(); ++i){
        std::cout << answer[i].size() << '\n';
        for(int j = 0; j < answer[i].size(); j++){//пробегаемся по всем смежным вершинам
            std::cout << answer[i][j] << ' ';
        }
        if(i != answer.size() - 1) std::cout << '\n';
    }
}
