//
// Created by pavel on 13.12.2017.
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

    Network(int N) : g(N, std::vector<long long> (N)), adjacency(N), parent(N, -1), col(N) {};\
    void add_edge(int x, int y, long long throughput);

    long long BFS(int start, int finish, int &);
    long long EdmondsKarp(int, int);
};

void Network::add_edge(int x, int y, long long throughput){
    g[x][y] = throughput;
    adjacency[x].push_back(y);
    adjacency[y].push_back(x);
}

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

long long valence(char c){
    if(c == '.') {
        return -1;
    }
    if(c == 'H') {
        return 1;
    }
    if(c == 'O') {
        return 2;
    }
    if(c == 'N') {
        return 3;
    }
    return 4;
}

int main(){
    int N, M;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    std::vector<std::vector<long long> > table(N, std::vector<long long>(M));
    Network transport(N * M + 2);
    long long out = 0, in = 0;
    char elem;
    for (int i = 0; i < N; ++i) { //считываем элементы
        for (int j = 0; j < M; ++j) {
            std::cin >> elem;
            table[i][j] = valence(elem);
            if(elem == '.') {
                continue;
            }
            if((i + j) % 2 == 0) {
                transport.add_edge(N * M, M * i + j, table[i][j]);
                out += table[i][j];
            } else {
                transport.add_edge(M * i + j, N * M + 1, table[i][j]);
                in += table[i][j];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(table[i][j] == -1 || (i + j) % 2 == 1) {
                continue;
            }
            int current_vertex = i * M + j; //текущая вершина; ниже - её соседи
            int right_neighbour = i * M + j + 1;
            int left_neighbour = i * M + j - 1;
            int up_neighbour = (i - 1) * M + j;
            int down_neighbour = (i + 1) * M + j;
            if ((j + 1) < M && table[i][j + 1] != -1) {
                transport.add_edge(current_vertex, right_neighbour, 1);
            }
            if ((j - 1) >= 0 && table[i][j - 1] != -1) {
                transport.add_edge(current_vertex, left_neighbour, 1);
            }
            if ((i - 1) >= 0 && table[i - 1][j] != -1) {
                transport.add_edge(current_vertex, up_neighbour, 1);
            }
            if ((i + 1) < N && table[i + 1][j] != -1) {
                transport.add_edge(current_vertex, down_neighbour, 1);
            }
        }
    }
    long long throughput = transport.EdmondsKarp(N * M, N * M + 1);
    if (throughput == in && throughput == out && throughput != 0){
        std::cout << "Valid";
    } else {
        std::cout << "Invalid";
    }
    return 0;
}

/*
 * Вася и Сережа играют в следующую игру. В некоторых клетках клетчатого листка Сережа рисует один из символов 'H',
 * 'O', 'N' или 'C', после чего Вася должен провести между некоторыми находящимися в соседних клетках символами линии
 * так, чтобы получилось корректное изображение химической молекулы. К сожалению, Сережа любит рисовать много символов,
 * и Вася не может сразу определить, возможно ли вообще нарисовать линии нужным способом. Помогите ему написать программу,
 * которая даст ответ на этот вопрос.

В этой задаче проведенные между символами химических элементов линии будем считать корректным изображением молекулы,
 если они удовлетворяют следующим условиям:

• каждая линия соединяет символы, нарисованные в соседних (по стороне) клетках,
• между каждой парой символов проведено не более одной линии,
• от каждого элемента отходит ровно столько линий, какова валентность этого элемента (1 для H, 2 для O, 3 для N, 4 для C),
• пустые клетки ни с чем не соединены, и
• хотя бы в одной клетке нарисован какой-то символ.
Формат входных данных
Первая строка входного файла содержит два натуральных числа n и m (1 ≤ n, m ≤ 50) - размеры листочка, на котором рисует
 Сережа. Далее следуют n строк по m символов в каждой, задающих конфигурацию химических элементов, которую нарисовал
 Сережа; пустые клетки задаются символом '.'.
Формат результата
В выходной файл выведите одно слово "Valid", если линии провести требуемым образом можно, и "Invalid", если нельзя.
Примеры
Входные данные	Результат работы
3 4
HOH.
NCOH
OO..
Valid
3 4
HOH.
NCOH
OONH
Invalid

 */