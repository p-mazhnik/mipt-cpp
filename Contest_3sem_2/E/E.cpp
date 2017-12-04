//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> G_matrix;

const int INF = 300000000;

int BellmanFord(const G_matrix &g, std::vector<int> &d, int Start){
    for (int k = 0; k < g.size(); ++k) { //INIT
        d[k] = INF;
    }
    d[Start] = 0;

    for (int i = 0; i < g.size() - 1; ++i) {
        for (int vertex = 0; vertex < g.size(); ++vertex) {
            for (int j = 0; j < g.size(); ++j) {
                if (d[j] < INF) { //RELAX
                    if (d[vertex] > d[j] + g[j][vertex]) {
                        d[vertex] = d[j] + g[j][vertex];
                    }
                }
            }
        }
    }
}

int main(){
    int N, M;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    G_matrix g(N, std::vector<int>(N, INF));
    g[0][0] = 0;
    for (int i, j, w, k = 0; k < M; ++k) {
        std::cin >> i >> j >> w;
        if(i != j && w < g[i - 1][j - 1]) {
            g[i - 1][j - 1] = w;
        }
    }

    std::vector<int> d(g.size());
    BellmanFord(g, d, 0);

    for (int j = 0; j < d.size(); ++j) {
        if(d[j] == INF) d[j] = 30000;
        std::cout << d[j] << ' ';
    }
}

/*
 * Дан ориентированный граф, в котором могут быть кратные ребра и петли. Каждое ребро имеет вес, выражающийся целым числом (возможно, отрицательным). Гарантируется, что циклы отрицательного веса отсутствуют.

Требуется посчитать длины кратчайших путей от вершины номер 1 до всех остальных вершин.

Входные данные
Программа получает сначала число N (1 <= N <= 100) – количество вершин графа и число M (0 <= M <= 10000) – количество ребер. В следующих строках идет M троек чисел, описывающих ребра: начало ребра, конец ребра и вес (вес – целое число от -100 до 100).

Выходные данные
Программа должна вывести N чисел – расстояния от вершины номер 1 до всех вершин графа. Если пути до соответствующей вершины не существует, вместо длины пути выведите число 30000.

Примеры
входные данные
6 4
1 2 10
2 3 10
1 3 100
4 5 -10
выходные данные
0 10 20 30000 30000 30000
 */