//
// Created by pavel on 09.12.2017.
//

#include <iostream>
#include <vector>
#include <queue>

const long long INF = 20090009990;

struct Edge{
    int finish;
    long long weight;
    Edge(int b = 0, long long c = 0){
        finish = b;
        weight = c;
    }
};

typedef std::vector<std::vector<Edge> > G_List;

void Dijkstra_fire(const G_List &g, std::vector<int> &fire, std::vector<long long> &distance){
    std::vector<bool> used(g.size(), false);
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int> >, std::greater<std::pair<long long, int> > > queue; // dist, vertex
    int current;
    for (int j = 0; j < fire.size(); ++j) {
        distance[fire[j]] = 0;
        queue.push(std::make_pair(distance[fire[j]], fire[j]));
    }
    while (!queue.empty()) {
        current = queue.top().second;
        queue.pop();
        used[current] = true;
        for (int i = 0; i < g[current].size(); ++i) {
            if(!used[g[current][i].finish] && distance[g[current][i].finish] > distance[current] + g[current][i].weight){
                distance[g[current][i].finish] = distance[current] + g[current][i].weight;
                queue.push(std::make_pair(distance[g[current][i].finish], g[current][i].finish));
            }
        }
        while (!queue.empty() && used[queue.top().second]) {
            queue.pop();
        }
    }
}

void Dijkstra(const G_List &g, std::vector<long long> &distance, std::vector<long long> &fire_distance, int StartVertex){
    std::vector<bool> used(g.size(), false);
    distance[StartVertex] = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int> >, std::greater<std::pair<long long, int> > > queue; // dist, vertex
    int current;
    queue.push(std::make_pair(distance[StartVertex], StartVertex));
    while (!queue.empty()) {
        current = queue.top().second;
        queue.pop();
        used[current] = true;
        for (int i = 0; i < g[current].size(); ++i) {
            if(!used[g[current][i].finish] && distance[g[current][i].finish] > distance[current] + g[current][i].weight
               && fire_distance[g[current][i].finish] > distance[current] + g[current][i].weight){
                distance[g[current][i].finish] = distance[current] + g[current][i].weight;
                queue.push(std::make_pair(distance[g[current][i].finish], g[current][i].finish));
            }
        }
        while (!queue.empty() && used[queue.top().second]) {
            queue.pop();
        }
    }
}

int main(){
    int N, M, K, Start, Finish; //N - кол-во этажей
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M >> K;
    G_List g(N);

    std::vector<int> fire(K);
    std::vector<long long> fire_distance(N, INF);
    for (int a, l = 0; l < K; ++l) {
        std::cin >> a;
        fire[l] = a - 1;
    }

    for (int x, y, length, k = 0; k < M; ++k) {
        std::cin >> x >> y >> length;
        g[x - 1].push_back(Edge(y - 1, length));
        g[y - 1].push_back(Edge(x - 1, length));
    }

    std::cin >> Start >> Finish;

    Dijkstra_fire(g, fire, fire_distance);

    std::vector<long long> distance (N, INF);
    Dijkstra(g, distance, fire_distance, Start - 1);
    if(distance[Finish - 1] == INF){
        std::cout << -1;
    } else {
        std::cout << distance[Finish - 1];
    }
}
/*
 * Однажды группа спелеологов отправилась покорять африканские пещеры. Углубившись достаточно далеко, они обнаружили что-то странное - пахло дымом. "Неужели мы подобрались к вулкану?" - удивленно спросил новичок. "Нет. Около вулкана пахнет серой", - ответил капитан. "Кто у нас занимался тушением костров?". Все неуверенно пожали плечами. "Итак, друзья, мы в ловушке".

Перед капитаном команды спелеологов возникла непосильная задача: как же вывести свою группу из пещеры, не сгорев? Пещера в терминах спелеологов состоит из множества "тоннелей" и "станций". Каждый тоннель соединяет какую-нибудь пару различных станций и имеет свою длину. У капитана имеется карта пещеры, и он знает, где они разводили костры, и где находится выход из пещеры.

Каждую секунду дым распространяется на 1 метр. Таким образом, тоннель длины "k", смежный с уже задымленной станцией, заполнится дымом за "k" секунд, а также заполнится дымом и соответствующая станция. Если спелеологи находятся на станции, где есть дым, они задыхаются. Спелеологи бегут со скоростью 1 метр в секунду. Изначально дым есть только в тех станциях, где спелеологи разводили костры.

Перемещаться по тоннелям можно в обе стороны. Если спелеологи прибывают на станцию одновременно с дымом, то они задыхаются (это верно и для той станции, где расположен выход). Гарантируется, что сейчас спелеологи находятся на станции, где нет дыма.
Формат входных данных
В первой строке входных данных содержится три целых числа N, M и K - количество станций, тоннелей и станций с кострами соответственно (2 ≤ N ≤ 2*105, 0 ≤ M ≤ 2*105, 1 ≤ K < N).

Во второй строке содержится K различных чисел ai - номера станций, в которых спелеологи разводили костры (1 ≤ ai ≤ N).

Следующие M строк описывают тоннели. Каждое описание состоит из трех чисел xi, yi и li, обозначающих номера станций, которые соединяет i-ый тоннель, и его длину в метрах (1 ≤ xi, yi ≤ N, 1 ≤ li ≤ 109$, xi != yi). В последней строке входных данных содержится 2 числа S и F - номер станции, на которой сейчас находятся спелеологи и номер станции, в которой находится выход из пещеры (1 ≤ S, F ≤ N).
Формат результата
Выведите единственное число - минимальное количество секунд, которое требуется спелеологам для того, чтобы выбраться из пещеры, либо "-1", если спелеологам не удастся выбраться.
Примеры
Входные данные	Результат работы
6 5 1
6
1 2 20
2 3 2
3 4 1
2 5 1
5 6 3
4 1
23
6 6 2
4 1
4 1 1
6 5 1
2 4 1
1 5 2
5 6 2
5 1 2
3 6
-1

 */