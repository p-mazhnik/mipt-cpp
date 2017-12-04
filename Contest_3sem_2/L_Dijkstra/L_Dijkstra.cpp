//
// Created by pavel on 04.12.2017.
//

#include <iostream>
#include <vector>
#include <queue>

const long long INF = 2009000999;

struct Edge{
    int start;
    int finish;
    int weight;
    Edge(int a = 0, int b = 0, int c = 0){
        start = a;
        finish = b;
        weight = c;
    }
};

typedef std::vector<std::vector<Edge> > G_List;

void Dijkstra(const G_List &g, std::vector<int> &d, int StartVertex){
    std::vector<bool> used(g.size(), false);
    d[StartVertex] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> >      > queue; // dist, vertex
    int current;
    queue.push(std::make_pair(d[StartVertex], StartVertex));
    while (!queue.empty()) {
        current = queue.top().second;
        queue.pop();
        used[current] = true;
        for (int i = 0; i < g[current].size(); ++i) {
            if(!used[g[current][i].finish] && d[g[current][i].finish] > d[current] + g[current][i].weight){
                d[g[current][i].finish] = d[current] + g[current][i].weight;
                queue.push(std::make_pair(d[g[current][i].finish], g[current][i].finish));
            }
        }
        while (!queue.empty() && used[queue.top().second]) {
            queue.pop();
        }
    }
}

int main(){
    int NUM;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> NUM;
    while (NUM != 0){
        int N, M;
        int StartVertex;
        std::cin >> N >> M;
        G_List g(N);
        std::vector<int> d (g.size(), INF);
        for (int start, finish, weight, i = 0; i < M; ++i) {
            std::cin >> start >> finish >> weight;
            g[finish].push_back(Edge(finish, start, weight));
            g[start].push_back(Edge(start, finish, weight));
        }
        std::cin >> StartVertex;
        Dijkstra(g, d,  StartVertex);
        for (int j = 0; j < d.size(); ++j) {
            std::cout << d[j] << ' ';
        }
        NUM--;
        if(NUM != 0) std::cout << '\n';
    }
}

/*
 * Напишите программу, которая будет находить расстояния в неориентированном взвешенном графе с неотрицательными
 * длинами ребер, от указанной вершины до всех остальных. Программа должна работать быстро для больших разреженных графов.
Формат входных данных
В первой строке входных данных задано число NUM — количество различных запусков алгоритма Дейкстры (на разных графах).
 Далее следуют NUM блоков, каждый из которых имеет следующую структуру.

Первая строка блока содержит два числа N и M, разделенные пробелом — количество вершин и количество ребер графа.
 Далее следуют M строк, каждая из которых содержит по три целых числа, разделенные пробелами. Первые два из них в
 пределах от 0 до N–1 каждое и обозначают концы соответствующего ребра, третье — в пределах от 0 до 20000 и обозначает
 длину этого ребра. Далее, в последней строке блока, записанное единственное число от 0 до N–1 — вершина, расстояния
 от которой надо искать.

Количество различных графов в одном тесте NUM не превышает 5. Количество вершин не превышает 60000, рёбер — 200000.
Формат результата
Выведите на стандартный выход (экран) NUM строк, в каждой из которых по N_i чисел, разделенных пробелами — расстояния
 от указанной начальной вершины взвешенного неориентированного графа до его 0-й, 1-й, 2-й и т. д. вершин (допускается
 лишний пробел после последнего числа). Если некоторая вершина недостижима от указанной начальной, вместо расстояния
 выводите число 2009000999 (гарантировано, что все реальные расстояния меньше).
Примеры
Входные данные	Результат работы
1
5 7
1 2 5
1 3 2
2 3 4
2 4 3
3 4 6
0 3 20
0 4 10
1
18 0 5 2 8

 */