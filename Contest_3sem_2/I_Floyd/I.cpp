//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > G_matrix;

const int INF = 51000000;

void Floyd(const G_matrix &g, G_matrix &length){
    for (int i = 0; i < length.size(); ++i) {
        for (int j = 0; j < length.size(); ++j) {
            length[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < length.size(); ++k) {
        for (int i = 0; i < length.size(); ++i) {
            for (int j = 0; j < length.size(); ++j) {
                if (length[i][k] < INF && length[k][j] < INF){
                    if(length[i][k] + length[k][j] < length[i][j]){
                        length[i][j] = length[i][k] + length[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    int N, StartVertex, FinishVertex;
    std::cin >> N >> StartVertex >> FinishVertex;
    G_matrix g(N, std::vector<int>(N)), length(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> g[i][j];
            if(g[i][j] == -1){
                g[i][j] = INF;
            }
        }
    }

    Floyd(g, length);

    int answer_length = length[StartVertex - 1][FinishVertex - 1];
    if(answer_length != INF){
        std::cout << answer_length;
    } else{
        std::cout << -1;
    }
}

/*
 * Дан ориентированный граф, рёбрам которого приписаны некоторые неотрицательные веса (длины). Найти длину кратчайшего пути из вершины s в вершину t.
Формат входных данных
В первой строке заданы три числа: число вершин в графе N ≤ 50, номера вершин s и t.
 Далее идёт матрица смежности графа, то есть N строк, в каждой из которых записано N чисел.
 j-ое число в i-ой строке матрицы смежности задает длину ребра, ведущего из i-й вершину в j-ую.
 Длины могут принимать любые значения от 0 до 1000000, число -1 означает отсутствие соответствующего ребра.
 Гарантируется, что на главной диагонали матрицы стоят нули.
Формат результата
Выведите одно число – минимальную длину пути. Если пути не существует, выведите -1.
 */
/*
void print(const std::vector<std::vector<int> > &a){
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
 */