//
// Created by pavel on 28.11.2017.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class DSU{
private:
    std::vector<int> tree;
    std::vector<int> weight;
    std::vector<int> rank;
public:
    void make_set(int);
    int find_set (int);
    void union_sets (int a, int b, int w = 0);
    int get_weight(int a);
    DSU(int n) : tree(n), rank(n), weight(n){}
};

void DSU::make_set (int v) {
    tree[v] = v;
    rank[v] = 0;
    weight[v] = 0;
}

int DSU::find_set (int v) {
    if (v == tree[v]) {
        return v;
    }
    return tree[v] = find_set (tree[v]);
}

void DSU::union_sets (int a, int b, int w) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b]){
            std::swap (a, b);
        }
        tree[b] = a;
        weight[a] += w + weight[b];
        if (rank[a] == rank[b]) {
            ++rank[a];
        }
    } else{
        if (rank[a] < rank[b]){
            std::swap (a, b);
        }
        weight[a] += w;
    }
}

int DSU::get_weight(int a) {
    return weight[a];
}

int main(){
    int N, M;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    DSU system(N);
    for (int j = 0; j < N; ++j) {
        system.make_set(j);
    }
    for (int cmd, x, y, w, i = 0; i < M; ++i) {
        std::cin >> cmd >> x;
        switch (cmd){
            case 1:{
                std::cin >> y >> w;
                system.union_sets(x - 1, y - 1, w);
                break;
            }
            case 2:{
                std::cout << system.get_weight(system.find_set(x - 1)) << '\n';
                break;
            }
        }
    }
    //std::system("pause");
}

/*
В неориентированный взвешанный граф добавляют ребра. Напишите программу, которая в некоторые моменты находит сумму весов ребер в компоненте связности.
Формат входных данных
В первой строке записано два числа n и m (1 ≤ n,m ≤ 10^6) - количество вершин в графе и количество производимых добавлений и запросов.
 Далее следует m строк с описанием добавления или запроса. Каждая строка состоит из двух или четырех чисел.
 Первое из чисел обозначает код операции. Если первое число 1, то за ним следует еще три числа x, y, w.
 Это означает, что в граф добавляется ребро из вершины x в вершину y веса w. (1 ≤ x < y ≤ n, 1 ≤ w ≤ 1000). Кратные ребра допустимы.
 Если первое число 2, то за ним следует ровно одно число x. Это означает, что необходимо ответить на вопрос,
 какова сумма ребер в компоненте связности, которой принадлежит вершина x (1 ≤ x ≤ n).
Формат результата
Для каждой операции с кодом 2 выведите ответ на поставленную задачу. Ответ на каждый запрос выводите на отдельной строке.
Примеры
Входные данные	Результат работы
6 10
2 1
1 1 2 1
2 1
1 2 4 2
2 1
1 1 4 3
2 1
1 3 5 3
2 5
2 6
0
1
3
6
3
0
 */
