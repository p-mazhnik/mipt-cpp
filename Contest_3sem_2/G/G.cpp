//
// Created by pavel on 22.11.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 200000000;

struct Edge{
    int start;
    int finish;
    int weight;
    Edge(int a = 0, int b = 0, int c = 0){
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

int BellmanFord(const G_list &e, int count_vertex, int K, int start, int finish){
    std::vector<int> virtual_count_to_finish(count_vertex, INF); // >= каким должно быть расстояние от вершины старта до остальных
    virtual_count_to_finish[finish] = K;
    for (int i = 0; i < virtual_count_to_finish.size() - 1; ++i) {
        for(int j = 0; j < e.size(); ++j) {
            if (virtual_count_to_finish[e[j].finish] < INF) { //RELAX
                if (virtual_count_to_finish[e[j].start] > virtual_count_to_finish[e[j].finish] - 1 && virtual_count_to_finish[e[j].finish] - 1) {
                    virtual_count_to_finish[e[j].start] = virtual_count_to_finish[e[j].finish] - 1;
                }
            }
        }
    }

    /*for (int k : virtual_count_to_finish) {
        std::cout << k << ' ';
    }
    std::cout << '\n';*/

    std::vector<int> d(count_vertex, INF);
    std::vector<int> count_vertex_from_start(count_vertex, INF);
    d[start] = 0;
    count_vertex_from_start[start] = 0;

    for (int i = 0; i < count_vertex; ++i) {
        for(int j = 0; j < e.size(); ++j) {
            if (d[e[j].start] < INF) { //RELAX
                if (d[e[j].finish] > d[e[j].start] + e[j].weight && virtual_count_to_finish[e[j].finish] >= count_vertex_from_start[e[j].start] + 1) {
                    d[e[j].finish] = d[e[j].start] + e[j].weight;
                    count_vertex_from_start[e[j].finish] = count_vertex_from_start[e[j].start] + 1;
                }
            }
        }
    }
    return d[finish];
}

int main(){
    int N, M, K, Start, Finish;
    std::cin >> N >> M >> K >> Start >> Finish;
    G_list e(M);

    for (int k = 0; k < M; ++k) {
        std::cin >> e[k];
    }

    int answer = BellmanFord(e, N, K, Start - 1, Finish - 1);
    if(answer == INF){
        std::cout << -1;
    } else{
        std::cout << answer;
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