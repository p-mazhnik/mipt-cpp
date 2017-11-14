//
// Created by pavel on 30.10.2017.
//
/*
Дан неориентированный граф. Проверить его на двудольность.
Формат входных данных
В первой строке находятся два числа N и M - количество вершин и ребер. (1 ≤ N ≤ 100, 0 ≤ M ≤ N * (N - 1) / 2)
 Далее в M строках перечислены рёбра графа. Каждое ребро задаётся парой чисел - номерами начальной и конечной вершин соответственно.
 В графе нет кратных ребер.
Формат результата
Если данный граф является двудольным, выведите "YES", иначе, выведите "NO".*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &, std::vector<Color> &, std::vector<int> &, std::vector<int> &, std::vector<int> &, int &, int, int, bool &);

void DFS(const G_list &g, bool &is_bipartite){
    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    std::vector<int> parity_color(g.size());
    is_bipartite = true;

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            int parity = 0;
            DFS_visit(g, col, parity_color, d_time, f_time, time, vertex, parity, is_bipartite);
        }
    }
}

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &parity_color, std::vector<int> &d_time, std::vector<int> &f_time, int &time, int vertex, int parity, bool &is_bipartite){
    col[vertex] = GRAY;
    ++parity;
    parity_color[vertex] = (parity % 2) ?  1 : 2;
    ++time;
    d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){
            DFS_visit(g, col, parity_color, d_time, f_time, time, g[vertex][i], parity, is_bipartite);
        }
        if(parity_color[g[vertex][i]] == parity_color[vertex]) {
            is_bipartite = false;
        }
    }
    col[vertex] = BLACK;
    ++time;
    f_time[vertex] = time;
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_list g(N);
    for (int i, j, k = 0; k < M; ++k) {
        std::cin >> i >> j;
        g[i - 1].push_back(j - 1);
        g[j - 1].push_back(i - 1);
    }
    bool is_bipartite;
    DFS(g, is_bipartite);
    if(is_bipartite) {
        std::cout << "YES" << '\n';
    }
    else {
        std::cout << "NO";
    }
    //system("pause");
}
