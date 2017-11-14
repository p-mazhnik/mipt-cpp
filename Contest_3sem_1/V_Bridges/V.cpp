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

typedef std::vector<std::vector<std::pair<int, int> > > G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &up,
               std::vector<int> &d_time, std::vector<int> &f_time, int &time, int vertex,
               std::set<int> &number_of_bridge, int previous_vertex = -1){
    col[vertex] = GRAY;
    ++time;
    up[vertex] = d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i].first] == WHITE){ //ребро дерева
            DFS_visit(g, col, up, d_time, f_time, time, g[vertex][i].first, number_of_bridge, vertex);
            up[vertex] = std::min(up[vertex], up[g[vertex][i].first]); //сравниваем up[vertex] с up потомков
            if(up[g[vertex][i].first] > d_time[vertex]) { //нашли мост
                number_of_bridge.insert(g[vertex][i].second);
            }
        }
        else if(g[vertex][i].first != previous_vertex && col[g[vertex][i].first] == GRAY){ //обратное ребро
            up[vertex] = std::min(up[vertex], d_time[g[vertex][i].first]); //сравниваем up[vertex] с up обратных рёбер
        }
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
        g[i - 1].push_back(std::make_pair(j - 1, k + 1));
        g[j - 1].push_back(std::make_pair(i - 1, k + 1));
    }
    std::set<int> number_of_bridge;
    DFS(g, number_of_bridge);
    std::cout << number_of_bridge.size() << '\n';
    for(auto it = number_of_bridge.begin(); it != number_of_bridge.end(); ++it){
        std::cout << *it << '\n';
    }
}
