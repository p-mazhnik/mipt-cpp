//
// Created by pavel on 06.11.2017.
//
#include <iostream>
#include <queue>

enum Color {WHITE, GRAY, BLACK};

void BFS(const std::vector<std::vector<bool> > &input,
        std::vector<std::vector<int> > &d_time, std::pair<int, int> v) {
    std::queue<std::pair<int, int> > q;
    q.push(v);
    std::vector<std::vector<Color> > col(input.size(), std::vector<Color>(input[0].size(), WHITE));
    col[v.first][v.second] = GRAY;

    while (q.size()) {
        std::pair<int, int> one, two, three, four;

        std::pair<int, int> vertex = q.front();
        q.pop();

        one.first = vertex.first;
        two.first = vertex.first;
        three.second = vertex.second;
        four.second = vertex.second;
        for (int j = vertex.second; j >= 0 && input[vertex.first][j] != 0 ; --j) { //идём влево
            --one.second;
        }
        for (int j = vertex.second; j < input[vertex.first].size() && input[vertex.first][j] != 0 ; ++j) { //идём вправо
            ++two.second;
        }
        for (int i = vertex.first; i >= 0 && input[i][vertex.second] != 0 ; --i) { //идём вверх
            --three.first;
        }
        for (int i = vertex.first; i < input.size() && input[i][vertex.second] != 0 ; ++i) { //идём вниз
            ++four.first;
        }
        one.second = vertex.second + one.second / 2;
        two.second = vertex.second + two.second / 2;
        three.first = vertex.first + three.first / 2;
        four.first = vertex.first + four.first / 2;

        std::vector<std::pair<int, int> > adjacent_vertex = {one, two, three, four};

        for (int i = 0; i < 4; ++i) { //пробегаемся по смежным вершинам
            if (col[adjacent_vertex[i].first][adjacent_vertex[i].second] == WHITE) {
                col[adjacent_vertex[i].first][adjacent_vertex[i].second] = GRAY;
                d_time[adjacent_vertex[i].first][adjacent_vertex[i].second] = d_time[vertex.first][vertex.second] + 1;
/*
                parent[adjacent_vertex[i].first][adjacent_vertex[i].second].first = vertex.first;
                parent[adjacent_vertex[i].first][adjacent_vertex[i].second].second = vertex.second;
*/
                q.push(adjacent_vertex[i]);
            }
        }
    }
    col[v.first][v.second] = BLACK;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector <std::vector<bool> > input(N, std::vector<bool>(M));
    char c = '.';
    std::pair<int, int> start, finish;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> c;
            if (c != '#') {
                if(c == 'S'){
                    start.first = i;
                    start.second = j;
                }
                if(c == 'T'){
                    finish.first = i;
                    finish.second = j;
                }
                input[i][j] = 1;
            }
        }
    }
    std::vector<std::vector<int> > d_time(input.size(), std::vector<int>(input[0].size()));
    BFS(input, d_time, start);
    if(finish != start && d_time[finish.first][finish.second] == 0){
        std::cout << -1;
    }
    else {
        std::cout << d_time[finish.first][finish.second];
    }
}