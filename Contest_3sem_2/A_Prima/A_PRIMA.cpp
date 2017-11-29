//
// Created by pavel on 22.11.2017.
//

#include <iostream>
#include <vector>
#include <cmath>

const int INF = 1000000;

double distance(const std::vector<std::pair<int, int> > &XY, int i, int j) {
    return sqrt((XY[j].first - XY[i].first)*(XY[j].first - XY[i].first) +
            (XY[j].second - XY[i].second)*(XY[j].second - XY[i].second));
}

double PRIMA(const std::vector<std::pair<int, int> > &XY){
    double dist = 0;
    std::vector<bool> used(XY.size());
    std::vector<std::pair<double , int> > min_weight(XY.size(), std::make_pair(INF, -1)); // храним вес наименьшего ребра и его конец

    for (int i = 0; i < XY.size(); i++) {
        int v = -1;
        for (int j = 0; j < XY.size(); j++) { //ищем вершину v c минимальным значением min_weight;
            if (!used[j] && (v == -1 || min_weight[j] < min_weight[v])){
                v = j;
            }
        }
        used[v] = true;
        if (min_weight[v].second != -1) {
            dist += (distance(XY, v, min_weight[v].second));
        }
        for (int u = 0; u < XY.size(); u++) {
            if (!used[u] && (distance(XY, v, u) < min_weight[u].first)) {
                min_weight[u].first = distance(XY, v, u);
                min_weight[u].second = v;
            }
        }
    }
    return dist;
}

int main(){
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int> > XY(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> XY[i].first >> XY[i].second;
    }

    printf("%.6lf", PRIMA(XY));

}
/*
 * В Байтландии есть целых n городов, но нет ни одной дороги. Король страны, Вальдемар де Беар, решил исправить эту ситуацию и соединить некоторые города дорогами так, чтобы по этим дорогам можно было добраться от любого города до любого другого. Когда строительство будет завершено, король планирует отпраздновать День Объединения. К сожалению, казна Байтландии почти пуста, поэтому король требует сэкономить деньги, минимизировав суммарную длину всех построенных дорог.
Формат входных данных
Первая строка входного файла содержит натуральное число n (1 ≤ n ≤ 5000)— количество городов в Байтландии. Каждая из следующих n строк содержит по два целых числа xi, yi — координаты i-го города(-10000 ≤ xi, yi ≤ 10000). Никакие два города не расположены в одной точке.
Формат результата
Первая строка выходного файла должна содержать минимальную суммарную длину дорог. Выведите число с точностью не менее 10-6.
 */