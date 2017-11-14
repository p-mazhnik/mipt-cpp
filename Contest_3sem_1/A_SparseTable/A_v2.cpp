//
// Created by pavel on 08.11.2017.
//

#include <vector>
#include <iostream>

template <typename T>
class sparse_table {
private:
    std::vector<T> data;
    std::vector <std::vector<T> > table;
    void build_table();
    static long long log_2(const long long &n);
public:

    sparse_table(const std::vector<T> &data) : data(data) {
        build_table();
    }

    T get_min(long long L, long long R) const;
};

template <typename T>
void sparse_table<T>::build_table() {
    if (!data.size()) {
        return;
    }
    long long pow = 1;
    long long max_pow = log_2(data.size());
    table.resize(max_pow + 1, std::vector<T>(data.size()));

    for (int i = 0; i < data.size(); ++i) {
        table[0][i] = data[i];
    }

    for (; pow <= max_pow; ++pow) {
        int current_pow_two = (1 << pow), prev_pow_two = (1 << (pow - 1));
        for (int i = 0; i <= data.size() - current_pow_two; ++i) {
            table[pow][i] = std::min(table[pow - 1][i], table[pow - 1][i + prev_pow_two]);
        }
    }
}

template <typename T>
long long sparse_table<T>::log_2(const long long &n) {
    int k = 0;
    while ((1 << k) <= n) {
        ++k;
    }
    return k - 1;
}

template <typename T>
T sparse_table<T>::get_min(long long L, long long R) const {
    if(R == L) {
        return data[R];
    }
    if(L > R) {
        long long l = L;
        L = R;
        R = l;
    }
    long long pow = log_2(R - L + 1);
    return std::min(table[pow][L], table[pow][R - (1 << pow) + 1]);
}

int main(){
    long long N, M, a1, u1, v1, min;
    scanf("%lld %lld %lld %lld %lld", &N, &M, &a1, &u1, &v1);
    std::vector<long long> input(N);
    input[0] = a1;
    for (int i = 1; i < N; ++i) {
        input[i] = (23 * input[i - 1] + 21563) % 16714589;
    }
    sparse_table<long long> table(input);
    min = table.get_min(u1 - 1, v1 - 1);
    for (int j = 1; j < M; ++j) {
        u1 = (17 * u1 + 751 + min + 2 * (j)) % N + 1;
        v1 = (13 * v1 + 593 + min + 5 * (j)) % N + 1;
        min = table.get_min(u1 - 1, v1 - 1);
    }
    printf("%lld %lld %lld", u1, v1, min);
    return 0;
}
/*
 * Дан массив из n чисел. Требуется написать программу, которая будет отвечать на запросы следующего вида: найти минимум на отрезке между u и v включительно.
Формат входных данных
В первой строке входного файла даны три натуральных числа n, m (1 ≤ n ≤ 105, 1 ≤ m ≤ 107) и a1 0 ≤ a_1 < 16714589) количество элементов в массиве, количество запросов и первый элемент массива соответственно. Вторая строка содержит два натуральных числа u1 и v1 (1 ≤ u1, v1 ≤ n) первый запрос.

Элементы a2, a3, ..., an задаются следующей формулой:

ai + 1 = (23 · ai + 21563) % 16714589.
Например, при n = 10, a1 = 12345 получается следующий массив: a = (12345, 305498, 7048017, 11694653, 1565158, 2591019, 9471233, 570265, 13137658, 1325095).


Запросы генерируются следующим образом:
ui + 1 = (17 · ui + 751 + ansi + 2i) % n + 1,
vi + 1 = (13 · vi + 593 + ansi + 5i) % n + 1
где ansi - ответ на запрос номер i.

Обратите внимание, что ui может быть больше, чем vi.
Формат результата
В выходной файл выведите um, vm и ansm (последний запрос и ответ на него).
Примеры
Входные данные	Результат работы
10 8 12345
3 9
5 3 1565158

 */