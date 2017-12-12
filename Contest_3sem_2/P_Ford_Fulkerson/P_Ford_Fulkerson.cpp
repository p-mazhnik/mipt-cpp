//
// Created by pavel on 11.12.2017.
//

#include <iostream>
#include <vector>

const int INF = 100000001;

typedef std::vector<std::vector<int> > G_matrix;

enum Color {WHITE, GRAY, BLACK};

int DFS_visit(G_matrix &g, std::vector<Color> &col, int vertex, int minim){
    if(vertex == g.size() - 1){
        return minim;
    }
    col[vertex] = GRAY;
    for(int i = 0; i < g.size(); i++){//пробегаемся по всем смежным вершинам
        if(g[vertex][i] && col[i] == WHITE){
            int result = DFS_visit(g, col, i, std::min(minim, g[vertex][i]));
            if (result) {
                g[vertex][i] -= result;
                g[i][vertex] += result;
                return result;
            }
        }
    }
    col[vertex] = BLACK;
    return 0;
}

int FordFulkerson(G_matrix &g){
    //std::vector<Color> col(g.size(), WHITE);
    int current = INF, result = 0;
    while(current != 0){
        std::vector<Color> col(g.size(), WHITE);
        current = DFS_visit(g, col, 0, INF);
        result += current;
    }
    return result;
}

int main(){
    int N, M;
    std::cin >> N >> M;
    G_matrix g(N, std::vector<int> (N));
    for (int x, y, throughput, i = 0; i < M; ++i) {
        std::cin >> x >> y >> throughput;
        g[x - 1][y - 1] = throughput;
    }
    std::cout << FordFulkerson(g);
    return 0;
}