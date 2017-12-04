//
// Created by pavel on 04.12.2017.
//

#include <iostream>
#include <vector>
#include <queue>

const long long INF = 20090009990;
const int MAX_COUNT = 1000000;

struct Edge{
    int start;
    int finish;
    long long weight;
    Edge(int a = 0, int b = 0, long long c = 0){
        start = a;
        finish = b;
        weight = c;
    }
};

typedef std::vector<std::vector<Edge> > G_List;

void Dijkstra(const G_List &g, std::vector<long long> &d, int StartVertex){
    std::vector<bool> used(g.size(), false);
    d[StartVertex] = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int> >, std::greater<std::pair<long long, int> > > queue; // dist, vertex
    int current;
    queue.push(std::make_pair(d[StartVertex], StartVertex));
    while (!queue.empty()) {
        current = queue.top().second;
        queue.pop();
        used[current] = true;
        for (int i = 0; i < g[current].size(); ++i) {
            if(!used[g[current][i].finish] && d[g[current][i].finish] > d[current] + g[current][i].weight){
                d[g[current][i].finish] = d[current] + g[current][i].weight;
                queue.push(std::make_pair(d[g[current][i].finish], g[current][i].finish));
            }
        }
        while (!queue.empty() && used[queue.top().second]) {
            queue.pop();
        }
    }
}

int main(){
    int N, U, D, I, J, L; //N - кол-во этажей
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> U >> D >> I >> J >> L; // U - подъём, D - спуск, внос - I, вынос - J; L - кол-во лифтов
    G_List g(MAX_COUNT + L);
    for (int k = 0; k < MAX_COUNT - 1; ++k) {
        g[k].push_back(Edge(k, k + 1, U));
        g[k + 1].push_back(Edge(k + 1, k, D));
    }

    for (int Count, j = 0; j < L; ++j) {
        std::cin >> Count;
        for (int K, i = 0; i < Count; ++i) {
            std::cin >> K;
            g[K - 1].push_back(Edge(K - 1, MAX_COUNT + j, I));
            g[MAX_COUNT + j].push_back(Edge(MAX_COUNT + j, K - 1, J));
        }
    }
    std::vector<long long> d (MAX_COUNT + L, INF);
    Dijkstra(g, d,  0);

    std::cout << d[N - 1];
}

/*

Чтобы поднять в свой офис на N-м этаже небоскреба новый сейф, Вите опять пришлось прибегнуть к помощи грузчиков.
 Но за это время система оплаты изменилась. Теперь за подъем по лестнице на один этаж требуется заплатить
 U рублей, за спуск по лестнице на один этаж — D рублей, за внос в лифт — I рублей, за вынос из лифта — J рублей.

В офисе имеется L лифтов, каждый из которых останавливается лишь на определенных этажах.

Помогите Вите разработать маршрут подъема сейфа с первого этажа, стоимость которого наименьшая.
Формат входных данных
В первой строке входного файла записаны целые числа N, U, D, I, J, L. Каждая из следующих L строк описывает
 соответствующий лифт. Она начинается с числа K_i — количества этажей, на которых останавливается i-й лифт,
 за которым следует K_i натуральных чисел — этажи, на которых останавливается этот лифт (этажи для каждого лифта
 задаются в возрастающем порядке). 0 ≤ U ≤ 1000, 0 ≤ D ≤ 1000, 0 ≤ I ≤ 1000, 0 ≤ J ≤ 1000, 0 ≤ L ≤ 500, 1 ≤ N ≤ 1000000,
 2 ≤ K_i ≤ 1000, K_1+K_2+…+K_L ≤ 100000. Количество этажей в небоскребе не превосходит 1000000.
Формат результата
В выходной файл выведите одно число — минимальную стоимость подъема сейфа.

 Примеры
Входные данные	Результат работы
10 1 1 1 1 1
2 3 7
7
10 1 1 3 2 1
2 3 7
9
20 100 0 1 1 2
2 5 7
2 8 17
804

 */