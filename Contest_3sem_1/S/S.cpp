//
// Created by pavel on 05.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &d_time,
               std::vector<int> &f_time, int &time, int vertex, int &count_cycle){
    col[vertex] = GRAY;
    ++time;
    d_time[vertex] = time;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, g[vertex][i], count_cycle);
        }
        if(col[g[vertex][i]] == GRAY){
            ++count_cycle;
        }
    }
    col[vertex] = BLACK;
    ++time;
    f_time[vertex] = time;
}

void DFS(const G_list &g, int &count_cycle){
    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());

    for(int u = 0; u < g.size(); ++u){
        if(col[u] == WHITE){
            DFS_visit(g, col, d_time, f_time, time, u, count_cycle);
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    G_list g(N);
    for (int i, k = 0; k < N; ++k) {
        std::cin >> i;
        g[i - 1].push_back(k);
    }
    int count_cycle = 0;
    DFS(g, count_cycle);
    std::cout << count_cycle;
    //system("pause");
}

/*
 * У Васи есть N свинок-копилок, свинки занумерованы числами от 1 до N. Каждая копилка может быть
 * открыта единственным соответствующим ей ключом или разбита.

Вася положил ключи в некоторые из копилок (он помнит, какой ключ лежит в какой из копилок). Теперь
 Вася собрался купить машину, а для этого ему нужно достать деньги из всех копилок.
 При этом он хочет разбить как можно меньшее количество копилок (ведь ему еще нужно копить деньги на квартиру,
 дачу, вертолет…). Помогите Васе определить, какое минимальное количество копилок нужно разбить.
Формат входных данных
В первой строке содержится число N — количество свинок-копилок (1 ≤ N ≤ 100). Далее идет N строк с
 описанием того, где лежит ключ от какой копилки: в i-ой из этих строк записан номер копилки,
 в которой находится ключ от i-ой копилки.
Формат результата
Выведите единственное число: минимальное количество копилок, которые необходимо разбить.
 */