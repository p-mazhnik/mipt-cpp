//
// Created by pavel on 11.10.2017.
//
/*
Дан ориентированный невзвешенный граф. Необходимо определить есть ли в нём циклы, и если есть, то вывести любой из них.
Формат входных данных
В первой строке входного файла находятся два натуральных числа N и M (1 ≤ N ≤ 100000, M ≤ 100000) - количество вершин и рёбер в графе соответственно.
Далее в M строках перечислены рёбра графа. Каждое ребро задаётся парой чисел - номерами начальной и конечной вершин соответственно.
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &, std::vector<Color> &, std::vector<int> &, std::vector<int> &, int &, int , const int &, std::vector<int> &, bool &, int &);

void DFS(const G_list &g, std::vector<int> &cycle){
    bool is_cycle = false;
    int start_cycle_vertex = -1;

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    for(int u = 0; !is_cycle && u < g.size(); ++u){
        if(col[u] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, u, -1, cycle, is_cycle, start_cycle_vertex);
        }
    }
}

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int u, const int &previous_vertex, std::vector<int> &cycle, bool &is_cycle, int &start_cycle_vertex){
    col[u] = GRAY;
    ++time;
    d_time[u] = time;
    for(int i = 0; !is_cycle && i < g[u].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[u][i]] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, g[u][i], u, cycle, is_cycle, start_cycle_vertex);
        }
        if(col[g[u][i]] == GRAY){
            is_cycle = true;
            start_cycle_vertex = g[u][i];
            cycle.push_back(start_cycle_vertex);
        }
    }
    if(is_cycle){
        if(u != start_cycle_vertex) {
            cycle.push_back(u);
        }
        else {
            start_cycle_vertex = previous_vertex;
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
    for (int i, j, k = 0; k < M; ++k) {
        std::cin >> i >> j;
        g[i - 1].push_back(j - 1);
    }
    std::vector<int> cycle;
    DFS(g, cycle);
    if(cycle.size() != 0) {
        std::cout << "YES" << '\n';
        std::cout << cycle[0] + 1 << ' ';
        for(int i = cycle.size() - 1; i > 0; --i){
            std::cout << cycle[i] + 1 << ' ';
        }
    }
    else {
        std::cout << "NO";
    }
    //system("pause");
}
