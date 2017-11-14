//
// Created by pavel on 03.11.2017.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

typedef std::vector<std::vector<int> > G_list;

enum Color {WHITE, GRAY, BLACK};

void DFS_visit(const G_list &g, std::vector<Color> &col, std::vector<int> &up,
               std::vector<int> &d_time, int &time, int vertex,
               std::set<int> &point, const int &count_skyscrapers, int previous_vertex = -1){
    col[vertex] = GRAY;
    ++time;
    up[vertex] = d_time[vertex] = time;
    int children = 0;
    for(int i = 0; i < g[vertex].size(); i++){//пробегаемся по всем смежным вершинам
        if(col[g[vertex][i]] == WHITE){ //ребро дерева
            DFS_visit(g, col, up, d_time, time, g[vertex][i], point, count_skyscrapers, vertex);
            up[vertex] = std::min(up[vertex], up[g[vertex][i]]); //сравниваем up[vertex] с up потомков
            if(vertex >= count_skyscrapers && previous_vertex != -1 && up[g[vertex][i]] >= d_time[vertex]){
                point.insert(vertex);
            }
            children++;
        }
        else if(g[vertex][i] != previous_vertex && col[g[vertex][i]] == GRAY){ //обратное ребро
            up[vertex] = std::min(up[vertex], d_time[g[vertex][i]]); //сравниваем up[vertex] с up обратных рёбер
        }
    }
    if(vertex >= count_skyscrapers && previous_vertex == -1 && children > 1) {
        point.insert(vertex);
    }
    col[vertex] = BLACK;
    ++time;
}

void DFS(const G_list &g, std::set<int> &number_of_bridge, const int &count_skyscrapers){
    std::vector<int> up(g.size());

    int time = 0;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());

    for(int vertex = 0; vertex < g.size(); ++vertex){
        if(col[vertex] == WHITE){
            DFS_visit(g, col, up, d_time, time, vertex, number_of_bridge, count_skyscrapers);
        }
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_list g(N + M);

    for (int a, b, c, k = 0; k < M; ++k) {
        std::cin >> a >> b >> c;
        g[a - 1].push_back(N + k);
        g[b - 1].push_back(N + k);
        g[c - 1].push_back(N + k);
        g[N + k].push_back(a - 1);
        g[N + k].push_back(b - 1);
        g[N + k].push_back(c - 1);
    }

    std::set<int> point;
    DFS(g, point, N);
    std::cout << point.size() << '\n';
    for(auto it = point.begin(); it != point.end(); ++it){
        std::cout << *it + 1 - N << ' ';
    }
}

/*
Город будущего застроен небоскребами, для передвижения между которыми и парковки транспорта многие тройки небоскребов
соединены треугольной подушкой из однополярных магнитов. Каждая подушка соединяет ровно 3 небоскреба и вид сверху на нее
 представляет собой треугольник, с вершинами в небоскребах. Это позволяет беспрепятственно передвигаться между соответствующими
 небоскребами. Подушки можно делать на разных уровнях, поэтому один небоскреб может быть соединен различными подушками с
 парами других, причем два небоскреба могут соединять несколько подушек (как с разными третьими небоскребами, так и с одинаковым).
 Например, возможны две подушки на разных уровнях между небоскребами 1, 2 и 3, и, кроме того, магнитная подушка между 1, 2, 5.

Система магнитных подушек организована так, что с их помощью можно добираться от одного небоскреба, до любого другого
 в этом городе (с одной подушки на другую можно перемещаться внутри небоскреба), но поддержание каждой из них требует
 больших затрат энергии.

Требуется написать программу, которая определит, какие из магнитных подушек нельзя удалять из подушечной системы города,
 так как удаление даже только этой подушки может привести к тому, что найдутся небоскребы из которых теперь нельзя
 добраться до некоторых других небоскребов, и жителям станет очень грустно.
Формат входных данных
        В первой строке входного файла находятся числа N и M — количество небоскребов в городе и количество
        работающих магнитных подушек соответственно (3 ≤ N ≤ 100000, 1 ≤ M ≤ 100000). В каждой из следующих M
        строк через пробел записаны три числа — номера небоскребов, соединенных подушкой. Небоскребы пронумерованы от 1 до N.

Гарантируется, что имеющиеся воздушные подушки позволяют перемещаться от одного небоскреба до любого другого.
Формат результата
Выведите в выходной файл сначала количество тех магнитных подушек, отключение которых невозможно без нарушения
 сообщения в городе, а потом их номера. Нумерация должна соответствовать тому порядку, в котором подушки перечислены
 во входном файле. Нумерация начинается с единицы.
*/
