//
// Created by pavel on 30.10.2017.
//
/*
Дан ориентированный невзвешенный граф. Необходимо его топологически отсортировать.
Формат входных данных
        В первой строке входного файла даны два целых числа N и M (1 ≤ N ≤ 100000, 0 ≤ M ≤ 100000) - количества
        вершин и рёбер в графе соответственно. Далее в M строках перечислены рёбра графа. Каждое ребро задаётся
        парой чисел - номерами начальной и конечной вершин соответственно.
Формат результата
Вывести любую топологическую сортировку графа в виде последовательности номеров вершин.
Если граф невозможно топологически отсортировать, вывести -1.*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int vertex, bool &is_cycle, std::vector<int> &topological){
    col[vertex] = GRAY;
    ++time;
    d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, g[vertex][i], is_cycle, topological);
        }
        if(col[g[vertex][i]] == GRAY){
            is_cycle = true;
        }
    }
    col[vertex] = BLACK;
    topological.push_back(vertex);
    ++time;
    f_time[vertex] = time;
}

void DFS(const G_list &g, std::vector<int> &topological, bool &is_cycle){
    is_cycle = false;

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, vertex, is_cycle, topological);
        }
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_list g(N);
    for (int i, j, k = 0; k < M; ++k) {
        std::cin >> i >> j;
        g[i - 1].push_back(j - 1);
    }
    bool is_cycle;
    std::vector<int> topological;
    DFS(g, topological, is_cycle);
    if(is_cycle) {
        std::cout << -1;
    }
    else {
        for(int i = N - 1; i >= 0; --i){
            std::cout << topological[i] + 1 << ' ';
        }
    }
}
