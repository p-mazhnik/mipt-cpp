//
// Created by pavel on 11.12.2017.
//

#include <iostream>
#include <vector>
#include <queue>

const long long INF = 10000000005;

class Network{
private:
    std::queue<int> q;
    std::vector<int> parent;
    std::vector<int> col;
public:
    struct Edge{
        int finish;
        long long stream;
        Edge(int a = -1, long long b = 0){
            finish = a;
            stream = b;
        }
    };
    typedef std::vector<std::vector<int> > G_list;
    typedef std::vector<std::vector<long long> > G_matrix;

    G_list adjacency;
    G_matrix g;

    Network(int N) : g(N, std::vector<long long> (N)), adjacency(N), parent(N, -1), col(N) {};

    long long BFS(int start, int finish, int &);
    long long EdmondsKarp(int, int);
};


long long Network::BFS(int start, int finish, int &count_bfs) {
    q.push(start);

    bool found = false;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adjacency[v].size() && !found; ++i) {
            if (g[v][adjacency[v][i]] && col[adjacency[v][i]] != count_bfs) {
                col[adjacency[v][i]] = count_bfs;
                parent[adjacency[v][i]] = v;
                if(adjacency[v][i] == finish){
                    found = true;
                    break;
                }
                q.push(adjacency[v][i]);
            }
        }
        col[v] = count_bfs;
    }

    if(found){
        long long stream = g[parent[finish]][finish];
        int current = finish;
        while (current != start) {
            if (g[parent[current]][current] < stream) {
                stream = g[parent[current]][current];
            }
            current = parent[current];
        }
        current = finish;
        while (current != start) {
            g[parent[current]][current] -= stream;
            g[current][parent[current]] += stream;
            current = parent[current];
        }
        return stream;
    }
    return 0;
}

long long Network::EdmondsKarp(int start, int finish){
    long long current = INF, stream = 0;
    int count_bfs = 1;
    while(current != 0){
        current = BFS(start, finish, count_bfs);
        stream += current;
        ++count_bfs;
    }
    return stream;
}

int main(){
    int N, M;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    Network transport(N);
    for (int x, y, i = 0; i < M; ++i) {
        long long throughput;
        std::cin >> x >> y >> throughput;
        transport.g[x - 1][y - 1] = throughput;
        transport.adjacency[x - 1].push_back(y - 1);
        transport.adjacency[y - 1].push_back(x - 1);
    }
    std::cout << transport.EdmondsKarp(0, N - 1);
    return 0;
}