//
// Created by pavel on 20.11.2017.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<std::pair<long long, long long> > > G_matrix;

const long long INF = 10000000000;

void get_path(const std::vector<std::vector<int> > &parent, const G_matrix &g, const std::vector<std::vector<long long> > &length,
              std::vector<long long> &path, bool &is_cycle, int i, int j){
    if(parent[i][j] != -1 && length[parent[i][j]][parent[i][j]] < 0){
        is_cycle = true;
        return;
    }
    if(parent[i][j] == -1) {
        path.push_back(g[i][j].second);
        return;
    }
    get_path(parent, g, length, path, is_cycle, i, parent[i][j]);
    get_path(parent, g, length, path, is_cycle, parent[i][j], j);
}

void Floyd(const G_matrix &g, std::vector<std::vector<std::vector<long long > > > &length,
           std::vector<std::vector<std::vector<int> > > &parent){
    for (int a = 0; a < length.size(); ++a) {
        for (int k = 0; k < length.size(); ++k) {
            if (k == a) {
                continue;
            }
            for (int i = 0; i < length.size(); ++i) {
                for (int j = 0; j < length.size(); ++j) {
                    if (length[a][i][k] < INF && length[a][i][k] > -INF && length[a][k][j] < INF &&
                        length[a][k][j] > -INF) {
                        if (length[a][i][k] + length[a][k][j] < length[a][i][j]) {
                            length[a][i][j] = length[a][i][k] + length[a][k][j];
                            parent[a][i][j] = k;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int N, M, K;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M >> K;
    G_matrix g(N, std::vector<std::pair<long long, long long> >(N, std::make_pair(INF, 0)));
    std::vector<std::vector<std::vector<long long> > > length(N, std::vector<std::vector<long long> >(N, std::vector<long long> (N)));
    std::vector<std::vector<std::vector<int> > > parent(N, std::vector<std::vector<int> >(N, std::vector<int> (N)));

    std::vector<long long> path;

    std::vector<int> towns(K);
    for (int m = 0; m < g.size(); ++m) {
        g[m][m].first = 0;
    }
    for (long long i, j, w, k = 0; k < M; ++k) {
        //считываем рёбра
        std::cin >> i >> j >> w;
        if(-w < g[i - 1][j - 1].first) {
            g[i - 1][j - 1].first = -w;
            g[i - 1][j - 1].second = k + 1;
        }
    }

    for (int l = 0; l < K; ++l) {
        std::cin >> towns[l];
    }

    bool is_cycle = false; // проверка на цикл отрицательного веса
    for (int a = 0; a < length.size(); ++a) {
        for (int i = 0; i < length.size(); ++i) { //INIT
            for (int j = 0; j < length.size(); ++j) {
                length[a][i][j] = g[i][j].first;
                parent[a][i][j] = -1;
            }
        }
    }
    Floyd(g, length, parent);
    Floyd(g, length, parent);

    for (int i = 0; i < K - 1; ++i) { //MAIN
        if(length[towns[i + 1] - 1][towns[i] - 1][towns[i] - 1] < 0) { //петля
            is_cycle = true;
            break;
        }
        if(towns[i] == towns[i + 1]) {
            continue;
        }
        get_path(parent[towns[i + 1] - 1], g, length[towns[i + 1] - 1], path, is_cycle, towns[i] - 1, towns[i + 1] - 1);
    }
    if(is_cycle) {
        std::cout << "infinitely kind";
    }
    else {
        std::cout << path.size() << '\n';
        for (int j = 0; j < path.size(); ++j) {
            std::cout << path[j] << ' ';
        }
    }
}

/*
 * Группа Pink Floyd собирается дать новый концертный тур по всему миру. По предыдущему опыту группа знает, что
 * солист Роджер Уотерс постоянно нервничает при перелетах. На некоторых маршрутах он теряет вес от волнения,
 * а на других - много ест и набирает вес.

Известно, что чем больше весит Роджер, тем лучше выступает группа, поэтому требуется спланировать перелеты так,
 чтобы вес Роджера на каждом концерте был максимально возможным. Группа должна посещать города в том же порядке,
 в котором она дает концерты. При этом между концертами группа может посещать промежуточные города.

Входные данные
Первая строка входного файла содержит три натуральных числа n, m и k - количество городов в мире, количество рейсов
 и количество концертов, которые должна дать группа соответственно (n≤100, m≤104, 2≤k≤104). Города пронумерованы
 числами от 1 до n. Следующие m строк содержат описание рейсов, по одному на строке. Рейс номер i описывается
 тремя числами bi, ei и wi - номер начального и конечного города рейса и предполагаемое изменение веса Роджера
 в миллиграммах (1≤bi,ei≤n, −105≤wi≤105). Последняя строка содержит числа a1, a2, ..., ak - номера городов, в которых
 проводятся концерты. В начале концертного тура группа находится в городе a1.Гарантируется,
 что группа может дать все концерты.

Выходные данные
Первая строка выходного файла должна содержать число s - количество рейсов, которые должна сделать группа.
 Вторая строка должна содержать s чисел - номера используемых рейсов. Если существует такая последовательность
 маршрутов между концертами, что Роджер будет набирать вес неограниченно, то первая строка выходного файла
 должна содержать строку “infinitely kind”.

Примеры
входные данные
4 8 5
1 2 -2
2 3 3
3 4 -5
4 1 3
1 3 2
3 1 -2
3 2 -3
2 4 -10
1 3 1 2 4
выходные данные
6
5 6 5 7 2 3
входные данные
4 8 5
1 2 -2
2 3 3
3 4 -5
4 1 3
1 3 2
3 1 -2
3 2 -3
2 4 10
1 3 1 2 4
выходные данные
infinitely kind

 3 3 2
 1 2 5
 2 2 4
 2 3 9
 1 3

 #13 test:
 3 4 2
 1 2 -2
 2 2 2
 2 3 4
 3 1 -4
 1 1
 Вывод:
 infinitely kind //если же флойд использовать 1 раз, то выведет 0, что неправильно
 */