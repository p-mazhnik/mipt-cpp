//
// Created by pavel on 31.10.2017.
//
/*
Дан неориентированный граф. Требуется найти все мосты в нём.
Формат входных данных
Первая строка входного файла содержит два натуральных числа n и m — количества вершин и рёбер графа соответственно
 (1 ≤ n ≤ 20000, 1 ≤ m ≤ 200000).

Следующие m строк содержат описание рёбер по одному на строке.
 Ребро номер i описывается двумя натуральными числами b_i, e_i — номерами концов ребра (1 ≤ b_i,e_i ≤ n).
Формат результата
Первая строка выходного файла должна содержать одно натуральное число b —
 количество мостов в заданном графе. На следующих b строках выведите b целых чисел — номера рёбер,
 которые являются мостами, в возрастающем порядке. Рёбра нумеруются с единицы в том порядке,
 в котором они заданы во входном файле.*/
#include <iostream>
#include <vector>
#include <map>
#include <set>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &up,
               std::vector<int> &d_time, std::vector<int> &f_time, int &time, int vertex,
               std::vector<std::pair<int, int> > &bridges, int previous_vertex = -1){
    col[vertex] = GRAY;
    ++time;
    up[vertex] = d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){ //ребро дерева
            DFS_visit(g, col, up, d_time, f_time, time, g[vertex][i], bridges, vertex);
            up[vertex] = std::min(up[vertex], up[g[vertex][i]]); //сравниваем up[vertex] с up потомков
            if(up[g[vertex][i]] > d_time[vertex]) { //нашли мост
                bridges.push_back(std::make_pair(vertex, g[vertex][i]));
            }
        }
        else if(g[vertex][i] != previous_vertex && col[g[vertex][i]] == GRAY){ //обратное ребро
            up[vertex] = std::min(up[vertex], d_time[g[vertex][i]]); //сравниваем up[vertex] с up обратных рёбер
        }
    }
    col[vertex] = BLACK;
    ++time;
    f_time[vertex] = time;
}

void DFS(const G_list &g, std::vector<std::pair<int, int> > &bridges){
    std::vector<int> up(g.size());

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            DFS_visit(g, col, up, d_time, f_time, time, vertex, bridges);
        }
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_list g(N);
    std::map<std::pair<int, int>, int> ribs;
    std::set<std::pair<int, int> > multiple_ribs;

    for (int i, j, k = 0; k < M; ++k) {
        std::cin >> i >> j;
        g[i - 1].push_back(j - 1);
        g[j - 1].push_back(i - 1);
        if(ribs[std::make_pair(i - 1, j - 1)] != 0 && ribs[std::make_pair(j - 1, i - 1)] != 0){ //выписываем отдельно кратные рёбра
            multiple_ribs.insert(std::make_pair(i - 1, j - 1));
            multiple_ribs.insert(std::make_pair(j - 1, i - 1));
        }
        ribs[std::make_pair(i - 1, j - 1)] = k + 1;
        ribs[std::make_pair(j - 1, i - 1)] = k + 1;
    }
    std::vector<std::pair<int, int> > bridges;
    DFS(g, bridges);

    std::set<int, std::less<int> > number_of_rib_bridge;
    for (int i = 0; i < bridges.size(); ++i) {
        if(multiple_ribs.find(bridges[i]) == multiple_ribs.end()) { //проверяем отсутствие кратных рёбер
            number_of_rib_bridge.insert(ribs[bridges[i]]);
        }
    }
    std::cout << number_of_rib_bridge.size() << '\n';
    for(auto it = number_of_rib_bridge.begin(); it != number_of_rib_bridge.end(); ++it){
        std::cout << *it << '\n';
    }
}
