//
// Created by pavel on 08.11.2017.
//

#include <iostream>
#include <vector>
#include <set>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &d_time, std::vector<int> &f_time, int &time,
               int vertex, std::vector<int> &finish, std::vector<int> &number_component, int &count_connected_component){
    col[vertex] = GRAY;
    ++time;
    d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, g[vertex][i], finish, number_component, count_connected_component);
        }
    }
    col[vertex] = BLACK;
    finish.push_back(vertex);
    number_component[vertex] = count_connected_component;
    ++time;
    f_time[vertex] = time;
}

void DFS(const G_list &g, std::vector<int> &finish){
    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    std::vector<int> number_component(g.size());
    int count_connected_component = 0;
    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, vertex, finish, number_component, count_connected_component);
        }
    }
}

void Kosaraju(const G_list &g, const G_list &new_g, std::vector<int> &number_component, int &count_connected_component){
    std::vector<int> finish;
    DFS(g, finish);

    int time = 0;
    std::vector<Color> col(new_g.size(), WHITE);
    std::vector<int> d_time(new_g.size());
    std::vector<int> f_time(new_g.size());
    std::vector<int> topological;

    for (int i = finish.size() - 1; i >= 0; --i) {
        if(col[finish[i]] == WHITE){
            ++count_connected_component;
            DFS_visit(new_g, col, d_time, f_time, time, finish[i], topological, number_component, count_connected_component);
        }
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_list g(N);
    G_list new_g(N);
    for (int i, j, k = 0; k < M; ++k) {
        std::cin >> i >> j;
        g[i - 1].push_back(j - 1);
        new_g[j - 1].push_back(i - 1);
    }

    std::vector<int> number_component(N);
    int count_connected_component = 0;
    Kosaraju(g , new_g, number_component, count_connected_component);
    std::cout << count_connected_component << '\n';
    for (int l = 0; l < N; ++l) {
        std::cout << number_component[l] << ' ';
    }
}


/*
 * Вам задан ориентированный граф с N вершинами и M ребрами (1 ≤ N ≤ 20000, 1 ≤ M ≤ 200000).
 * Найдите компоненты сильной связности заданного графа и топологически отсортируйте его конденсацию.
Формат входных данных
Граф задан во входном файле следующим образом: первая строка содержит числа N и M.
 Каждая из следующих M строк содержит описание ребра — два целых числа из диапазона от 1 до N — номера начала и конца ребра.
Формат результата
На первой строке выведите число K — количество компонент сильной связности в заданном графе.
 На следующей строке выведите N чисел — для каждой вершины выведите номер компоненты сильной связности,
 которой принадлежит эта вершина. Компоненты сильной связности должны быть занумерованы таким образом,
 чтобы для любого ребра номер компоненты сильной связности его начала не превышал номера
 компоненты сильной связности его конца.
 */