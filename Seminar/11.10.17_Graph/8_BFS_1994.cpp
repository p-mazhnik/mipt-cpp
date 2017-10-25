//
// Created by pavel on 18.10.2017.
//

#include <iostream>
#include <queue>

typedef std::vector<std::vector<bool>> G_matrix;
typedef std::vector<std::vector<int>> G_list;

enum Color {WHITE, GRAY, BLACK};

void BFS(G_matrix g, int S){
    std::queue<int> Q;
    std::vector<Color> col(g.size(), WHITE);
    std::vector<int> d_time(g.size());
    std::vector<int> f_time(g.size());
    Q.push(S);
    while(Q.size() != 0){
        int x = Q.front();
        Q.pop();
        for(){
            if(col[v] == WHITE){
                col[v] = GRAY;
                d_time[v] = d_time[x] + 1;
                Q.push(v);
            }
            col[v] = BLACK;
        }
    }
}