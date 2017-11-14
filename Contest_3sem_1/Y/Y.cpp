//
// Created by pavel on 08.11.2017.
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void find_bridge_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &up,
                        std::vector<int> &d_time, int &time, int vertex,
                        std::set<std::pair<int, int> > &bridges, int previous_vertex = -1){
    col[vertex] = GRAY;
    ++time;
    up[vertex] = d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){ //ребро дерева
            find_bridge_visit(g, col, up, d_time, time, g[vertex][i], bridges, vertex);
            up[vertex] = std::min(up[vertex], up[g[vertex][i]]); //сравниваем up[vertex] с up потомков
            if(up[g[vertex][i]] > d_time[vertex]) { //нашли мост
                bridges.insert(std::make_pair(vertex, g[vertex][i]));
                bridges.insert(std::make_pair(g[vertex][i], vertex));
            }
        }
        else if(g[vertex][i] != previous_vertex && col[g[vertex][i]] == GRAY){ //обратное ребро
            up[vertex] = std::min(up[vertex], d_time[g[vertex][i]]); //сравниваем up[vertex] с up обратных рёбер
        }
    }
    col[vertex] = BLACK;
}

void find_bridge(const G_list &g, std::set<std::pair<int, int> > &bridges){
    std::vector<int> up(g.size());

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            find_bridge_visit(g, col, up, d_time, time, vertex, bridges);
        }
    }
}

void DFS_visit(const G_list &g, std::vector<Color> &col,
                       std::vector<int> &d_time, int &time, int vertex, std::set<std::pair<int, int> > &bridges,
               std::vector<int> &number_component, int &count_component){
    col[vertex] = GRAY;
    ++time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if((bridges.find(std::make_pair(vertex, g[vertex][i])) == bridges.end()) && col[g[vertex][i]] == WHITE){ //ребро дерева, не мост
            DFS_visit(g, col, d_time, time, g[vertex][i], bridges, number_component, count_component);
        }
    }
    col[vertex] = BLACK;
    number_component[vertex] = (count_component);
}

void DFS(const G_list &g, int &result_edges){

    std::set<std::pair<int, int> > bridges;
    find_bridge(g, bridges);

    std::vector<int> up(g.size());

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> number_component(g.size());
    int count_component = 0;

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            DFS_visit(g, col, d_time, time, vertex, bridges, number_component, count_component);
            ++count_component;
        }
    }

    G_list new_g(count_component);
    for (auto j = bridges.begin(); j != bridges.end(); ++j) {
        new_g[number_component[j->first]].push_back(number_component[j->second]);
    }
    int count_hanging_top = 0;
    for(int i = 0; i < count_component; ++i){
        if(new_g[i].size() == 1){
            ++count_hanging_top;
        }
    }
    result_edges = (count_hanging_top + 1) / 2;
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
    int result_edges;

    DFS(g, result_edges);
    std::cout << result_edges;
}

/*
 * Дан простой(без кратных ребер) связный неориентированный граф на n вершинах с m ребрами. Найдите минимальное количество дорог, которое можно добавить в граф, чтобы при удалении любого ребра граф не переставал быть связным.
Формат входных данных
Первая строка содержит два числа n (3 ≤ n ≤ 5000) и m (1 ≤ m ≤ 100000). Следующие m строк содержат два числа - описание ребра графа.
Формат результата
Выведите минимальное количество ребер, которое нужно добавить в граф.
Примеры
Входные данные	Результат работы
4 3
1 2
2 3
2 4
2

 */