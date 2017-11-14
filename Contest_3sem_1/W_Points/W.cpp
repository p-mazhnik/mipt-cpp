//
// Created by pavel on 01.11.2017.
//
/*
Дан неориентированный граф. Требуется найти все точки сочленения в нём.
Формат входных данных
Первая строка входного файла содержит два натуральных числа n и m —
 количества вершин и рёбер графа соответственно (1 ≤ n ≤ 20000, 1 ≤ m ≤ 200000).

Ребро номер i описывается двумя натуральными числами b_i, e_i — номерами концов ребра (1 ≤ b_i,e_i ≤ n).
Формат результата
Первая строка выходного файла должна содержать одно натуральное число b — количество точек сочленения в заданном графе.
 На следующих b строках выведите b целых чисел — номера вершин, которые являются точками сочленения, в возрастающем порядке.*/
#include <iostream>
#include <vector>
#include <map>
#include <set>

typedef std::vector<std::vector<int> > G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &up,
               std::vector<int> &d_time, std::vector<int> &f_time, int &time, int vertex,
               std::set<int> &point, int previous_vertex = -1){
    col[vertex] = GRAY;
    ++time;
    up[vertex] = d_time[vertex] = time;
    int children = 0;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){ //ребро дерева
            DFS_visit(g, col, up, d_time, f_time, time, g[vertex][i], point, vertex);
            up[vertex] = std::min(up[vertex], up[g[vertex][i]]); //сравниваем up[vertex] с up потомков
            if(previous_vertex != -1 && up[g[vertex][i]] >= d_time[vertex]){
                point.insert(vertex);
            }
            children++;
        }
        else if(g[vertex][i] != previous_vertex && col[g[vertex][i]] == GRAY){ //обратное ребро
            up[vertex] = std::min(up[vertex], d_time[g[vertex][i]]); //сравниваем up[vertex] с up обратных рёбер
        }
    }
    if(previous_vertex == -1 && children > 1) {
        point.insert(vertex);
    }
    col[vertex] = BLACK;
    ++time;
    f_time[vertex] = time;
}

void DFS(const G_list &g, std::set<int> &number_of_bridge){
    std::vector<int> up(g.size());

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            DFS_visit(g, col, up, d_time, f_time, time, vertex, number_of_bridge);
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
        g[j - 1].push_back(i - 1);
    }
    std::set<int> point;
    DFS(g, point);
    std::cout << point.size() << '\n';
    for(auto it = point.begin(); it != point.end(); ++it){
        std::cout << *it + 1 << '\n';
    }
}
