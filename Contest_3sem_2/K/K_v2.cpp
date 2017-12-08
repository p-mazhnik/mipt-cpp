//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<std::pair<long long, long long> > > G_matrix;

const long long INF = 10000000000;

void get_path(const std::vector<std::vector<int> > &parent, const G_matrix &g,
              std::vector<long long> &path, int i, int j){
    if(parent[i][j] == -1) {
        path.push_back(g[i][j].second);
        return;
    }
    get_path(parent, g, path, i, parent[i][j]);
    get_path(parent, g, path, parent[i][j], j);
}

void Floyd(const G_matrix &g, std::vector<std::vector<long long > > &length,
           std::vector<std::vector<int> > &parent){
    for (int i = 0; i < length.size(); ++i) { //INIT
        for (int j = 0; j < length.size(); ++j) {
            length[i][j] = g[i][j].first;
        }
    }
    for (int k = 0; k < length.size(); ++k) {
        for (int i = 0; i < length.size(); ++i) {
            for (int j = 0; j < length.size(); ++j) {
                if (length[i][k] < INF && length[k][j] < INF) {
                    if (length[i][k] + length[k][j] < length[i][j]) {
                        length[i][j] = length[i][k] + length[k][j];
                        parent[i][j] = k;
                    }
                }
            }
        }
    }
    for (int k = 0; k < length.size(); ++k) {
        for (int i = 0; i < length.size(); ++i) {
            for (int j = 0; j < length.size(); ++j) {
                if (length[i][k] < INF && length[k][j] < INF && length[k][k] < 0){
                        length[i][j] = -INF;
                }
            }
        }
    }
}

int main(){
    int N, M, K;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M >> K;
    G_matrix g(N, std::vector<std::pair<long long, long long> >(N, std::make_pair(INF, 0)));
    std::vector<std::vector<long long> > length(N, std::vector<long long> (N, INF));
    std::vector<std::vector<int> > parent(N, std::vector<int> (N, -1));

    std::vector<long long> path;
    for (long long i, j, w, k = 0; k < M; ++k) {
        //считываем рёбра
        std::cin >> i >> j >> w;
        if(-w < g[i - 1][j - 1].first) {
            g[i - 1][j - 1].first = -w;
            if (i == j && w > 0) { //петля
                g[i - 1][j - 1].first = -INF;
            }
            g[i - 1][j - 1].second = k + 1;
        }
    }

    Floyd(g, length, parent);

    bool is_cycle = false; // проверка на цикл отрицательного веса
    int prev;
    std::cin >> prev;
    for (int current, l = 0; l < K - 1; ++l) {
        std::cin >> current;
        if(length[prev - 1][current - 1] == -INF){
            is_cycle = true;
            break;
        }
        if(prev == current){
            continue;
        }
        get_path(parent, g, path, prev - 1, current - 1);
        prev = current;
    }
    if(is_cycle) {
        std::cout << "infinitely kind";
    }
    else {
        std::cout << path.size() << '\n';
        for (int j = 0; j < path.size(); ++j) {
            std::cout << path[j] << ' ';
        }
    }
}
