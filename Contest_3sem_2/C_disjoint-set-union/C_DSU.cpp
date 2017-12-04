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
    std::vector<int> rank;
public:
    void make_set(int);
    int find_set (int);
    void union_sets (int a, int b);
    DSU(int n) : tree(n), rank(n){}
};

void DSU::make_set (int v) {
    tree[v] = v;
    rank[v] = 0;
}

int DSU::find_set (int v) {
    if (v == tree[v]) {
        return v;
    }
    return tree[v] = find_set (tree[v]);
}

void DSU::union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b]){
            std::swap (a, b);
        }
        tree[b] = a;
        if (rank[a] == rank[b]) {
            ++rank[a];
        }
    }
}

int main(){
    int N, M, K;
    std::cin >> N >> M >> K ;
    std::string cmd;
    std::stack<std::pair<std::string, std::pair<int, int> > > operations;
    std::stack<std::string> answers;

    DSU system(N);
    for (int j = 0; j < N; ++j) {
        system.make_set(j);
    }
    for (int u, v, i = 0; i < M; ++i) {
        std::cin >> u >> v;
    }
    for (int u, v, k = 0; k < K; ++k) {
        std::cin >> cmd >> u >> v;
        operations.push(std::make_pair(cmd, std::make_pair(u - 1, v - 1)));
    }
    while(!operations.empty()) {
        if(operations.top().first == "ask"){
            if(system.find_set(operations.top().second.first) == system.find_set(operations.top().second.second)){
                answers.push("YES\n");
            } else {
                answers.push("NO\n");
            }
        }
        if(operations.top().first == "cut"){
            system.union_sets(operations.top().second.first, operations.top().second.second);
        }
        operations.pop();
    }
    while(!answers.empty()) {
        std::cout << answers.top();
        answers.pop();
    }
}

/*
 * Дан неориентированный граф. Над ним в заданном порядке производят операции следующих двух типов:

• cut — разрезать граф, то есть удалить из него ребро;

• ask — проверить, лежат ли две вершины графа в одной компоненте связности.

Известно, что после выполнения всех операций типа cut рёбер в графе не осталось. Найдите результат выполнения каждой из операций типа ask.
Формат входных данных
Первая строка входного файла содержит три целых числа, разделённые пробелами — количество вершин графа n,
 количество рёбер m и количество операций k (1 ≤ n ≤ 50000, 0 ≤ m ≤ 100000, m ≤ k ≤ 150000).

Следующие m строк задают рёбра графа; i-ая из этих строк содержит два числа u_i и v_i (1 ≤ u_i, v_i ≤ n), разделённые пробелами — номера концов i-го ребра.
 Вершины нумеруются с единицы; граф не содержит петель и кратных рёбер.

Далее следуют k строк, описывающих операции. Операция типа cut задаётся строкой «cut u v» (1 ≤ u, v ≤ n), которая означает, что из графа удаляют ребро между вершинами u и v.
 Операция типа ask задаётся строкой «ask u v» (1 ≤ u, v ≤ n), которая означает, что необходимо узнать, лежат ли в данный момент вершины u и v в одной компоненте связности.
 Гарантируется, что каждое ребро графа встретится в операциях типа cut ровно один раз.
Формат результата
Для каждой операции ask во входном файле выведите на отдельной строке слово «YES», если две указанные вершины лежат в одной компоненте связности, и «NO» в противном случае.
 Порядок ответов должен соответствовать порядку операций ask во входном файле.
Примеры
Входные данные	Результат работы
3 3 7
1 2
2 3
3 1
ask 3 3
cut 1 2
ask 1 2
cut 1 3
ask 2 1
cut 2 3
ask 3 1
YES
YES
NO
NO

 */