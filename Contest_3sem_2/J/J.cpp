//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > G_matrix;

const int INF = 51000000;

void Floyd(const G_matrix &g, G_matrix &length){
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    G_matrix g(N, std::vector<int>(N)), length(N, std::vector<int>(N)), transitive(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> g[i][j];
            if(g[i][j] == 0){
                g[i][j] = INF;
            }
        }
    }

    Floyd(g, length);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(length[i][j] == INF) {
                transitive[i][j] = 0;
            } else{
                transitive[i][j] = 1;
            }
            std::cout << transitive[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
/*
 * Невзвешенный ориентированный граф задан своей матрицей смежности. Требуется построить его транзитивное замыкание,
 * то есть матрицу, в которой в i-й строке и j-м столбце находится 1, если от вершины i можно добраться до вершины j, и 0 - иначе.

Входные данные
В первой строке дано число N (1￼N￼100) - число вершин в графе. Далее задана матрица смежности графа: в N строках
 даны по N чисел 0 или 1 в каждой. i-е число в i-й строке всегда равно 1.

Выходные данные
Необходимо вывести матрицу транзитивного замыкания графа в формате, аналогичным формату матрицы смежности.

Примеры
входные данные
4
1 1 0 0
0 1 1 0
1 0 1 0
0 0 1 1
выходные данные
1 1 1 0
1 1 1 0
1 1 1 0
1 1 1 1
 */