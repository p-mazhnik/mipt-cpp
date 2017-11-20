//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > G_matrix;

const int INF = 100000;

void BellmanFord(const G_matrix &g, G_matrix &length){
    for (int i = 0; i < length.size(); ++i) {
        for (int j = 0; j < length.size(); ++j) {
            length[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < length.size(); ++k) {
        for (int i = 0; i < length.size(); ++i) {
            for (int j = 0; j < length.size(); ++j) {
                if (length[i][k] < INF && length[k][j] < INF){
                    if(length[i][k] + length[k][j] < length[i][j]){
                            length[i][j] = length[i][k] + length[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    G_matrix g(N, std::vector<int>(N)), length(N, std::vector<int>(N));

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            std::cin >> g[k][i];
            if(g[k][i] == 0 && k != i) { //нет ребра
                g[k][i] = INF;
            }
            if(g[k][i] == 1) {
                g[k][i] = -1;
            }
        }
    }

    BellmanFord(g, length);
    bool is_cycle = false;
    for (int j = 0; j < length.size(); ++j) {
        if(length[j][j] < 0) {
            is_cycle = true;
        }
    }
    std::cout << is_cycle;
}
