//
// Created by pavel on 10.12.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 2000000000000;

struct Edge{
    int start;
    long long time_departure;
    int finish;
    long long time_arrival;
    Edge(int a = 0, long long d = 0, int b = 0, long long c = 0){
        start = a;
        time_departure = d;
        finish = b;
        time_arrival = c;
    }
    friend std::istream &operator>>(std::istream &, Edge &);
};

typedef std::vector<Edge> G_list;

std::istream &operator>>(std::istream &in, Edge &edge) {
    int start, finish;
    in >> start >> edge.time_departure >> finish >> edge.time_arrival;
    edge.start = start - 1;
    edge.finish = finish - 1;
    return in;
}

long long BellmanFord(const G_list &e, int count_vertex, int K, int start, int finish){
    std::vector<long long> distance(count_vertex, INF);
    distance[start] = 0;
    for (int i = 0; i < e.size(); ++i) {
        for(int j = 0; j < e.size(); ++j) {
            if (/*distance[e[j].start] < INF && */distance[e[j].start] <= e[j].time_departure) { //RELAX
                if (distance[e[j].finish] > e[j].time_arrival) {
                    distance[e[j].finish] = e[j].time_arrival;
                }
            }
        }
    }
    return distance[finish];
}

int main(){
    int N, M, K, Start, Finish;
    std::cin >> N >> Start >> Finish >> M;
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