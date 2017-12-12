//
// Created by pavel on 22.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 2000000000000;

struct Edge{
    int start;
    int finish;
    long long weight;
    Edge(int a = 0, int b = 0, long long c = 0){
        start = a;
        finish = b;
        weight = c;
    }
    friend std::istream &operator>>(std::istream &, Edge &);
};

typedef std::vector<Edge> G_list;

std::istream &operator>>(std::istream &in, Edge &edge) {
    int start, finish;
    in >> start >> finish >> edge.weight;
    edge.start = start - 1;
    edge.finish = finish - 1;
    return in;
}

long long BellmanFord(const G_list &e, int count_vertex, int K, int start, int finish){
    std::vector<std::vector<long long> > distance(count_vertex, std::vector<long long> (2, INF)); //длина пути не привышает k в k-ом столбце
    distance[start][0] = 0;
    for (int i = 0; i < K; ++i) {
        int previous_step = i % 2;
        int current_step = 1 - (i % 2);
        for(int j = 0; j < e.size(); ++j) {
            if (distance[e[j].start][previous_step] < INF) { //RELAX
                if (distance[e[j].finish][current_step] > distance[e[j].start][previous_step] + e[j].weight) {
                    distance[e[j].finish][current_step] = distance[e[j].start][previous_step] + e[j].weight;
                }
            }
        }
        for (int vertex = 0; vertex < distance.size(); vertex++) {
            distance[vertex][current_step ] = std::min(distance[vertex][current_step], distance[vertex][previous_step]);
        }
    }
    return distance[finish][K % 2];
}

int main(){
    int N, M, K, Start, Finish;
    std::cin >> N >> M >> K >> Start >> Finish;
    G_list e(M);
    for (int k = 0; k < M; ++k) {
        std::cin >> e[k];
    }
    long long answer = BellmanFord(e, N, K, Start - 1, Finish - 1);
    if(answer == INF){
        std::cout << -1 << '\n';
    } else {
        std::cout << answer << '\n';
    }
}

/*
 *Профессору Форду необходимо попасть на международную конференцию. Он хочет потратить на дорогу наименьшее количество денег, поэтому решил, что будет путешествовать исключительно ночными авиарейсами (чтобы не тратиться на ночевку в отелях), а днем будет осматривать достопримечательности тех городов, через которые он будет проезжать транзитом. Он внимательно изучил расписание авиаперелетов и составил набор подходящих авиарейсов, выяснив, что перелеты на выбранных направлениях совершаются каждую ночь и за одну ночь он не сможет совершить два перелета.

Теперь профессор хочет найти путь наименьшей стоимости, учитывая что до конференции осталось K ночей (то есть профессор может совершить не более K перелетов).
Формат входных данных
В первой строке находятся числа N (количество городов), M (количество авиарейсов), K (количество оставшихся ночей), S (номер города, в котором живет профессор), F (номер города, в котором проводится конференция).

Ограничения: 2 ≤ N ≤ 100, 1 ≤ M ≤ 10^5, 1 ≤ K ≤ 100, 1 ≤ S ≤ N, 1 ≤ F ≤ N.

Далее идет M строк, задающих расписание авиарейсов. i-я строка содержит три натуральных числа: S_i, F_i и P_i, где S_i - номер города, из которого вылетает i-й рейс, F_i - номер города, в который прилетает i-й рейс, P_i - стоимость перелета i-м рейсом. 1 ≤ S_i ≤ N, 1 ≤ F_i ≤ N, 1 ≤ P_i ≤ 10^6.
Формат результата
Выведите одно число - минимальную стоимость пути, подходящего для профессора. Если профессор не сможет за K ночей добраться до конференции, выведите число -1.
 */