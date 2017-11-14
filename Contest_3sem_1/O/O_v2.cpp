//
// Created by pavel on 08.11.2017.
//

#include <iostream>
#include <vector>

class Treap{ //Tree + heap
public:
    long long key; //key
    int priority; //priority
    int size;

    long long sum;

    Treap *left;
    Treap *right;
    Treap(long long key) : key(key), priority(rand()), size(1), sum(key), left(NULL), right(NULL){};
    Treap() : left(NULL), right(NULL){};
    ~Treap();
};

Treap::~Treap() {
    if (left != NULL) delete left;
    if (right != NULL) delete right;
}

int get_size(Treap *&x){
    return (x == NULL) ? 0 : x->size;
}

long long get_sum(Treap *&x){
    return (x == NULL) ? 0 : x->sum;
}

void update(Treap *&T){
    T->size = 1 + get_size(T->left) + get_size(T->right);
    T->sum = get_sum(T->left) + get_sum(T->right) + T->key;
}

void split(Treap *T, long long x, Treap* &left, Treap* &right, int size = 0) {
    if (T == NULL){
        left = right = NULL;
        return;
    }
    else{
        int key = size + get_size(T->left);
        if(x >= key){
            split(T->right, x, T->right, right, key + 1);
            left = T;
        } else{
            split(T->left, x, left, T->left, size);
            right = T;
        }
    }
    update(T);
}

Treap *merge(Treap *left, Treap *right) {
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    if(left->priority >= right->priority){
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
    else{
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

void insert(Treap* &root, long long x, int i = 0){
    Treap *new_vertex = new Treap(x);
    Treap *left, *right;
    split(root, i, left, right);
    root = merge(merge(left, new_vertex), right);
}

long long sum(Treap* &root, int l, int r){
    Treap *one, *two;
    Treap *three, *four;
    split(root, r, one, two);
    split(one, l - 1, three, four);
    long long result = get_sum(four);
    root = merge(merge(three, four), two);
    return result;
}

long long sum(Treap* odd, Treap* even, int l, int r) {
    if (l == 0 && r == 0){
        return sum(even, (l) / 2, (r - 1) / 2);
    }
    else {
        return sum(even, (l) / 2, (r - 1) / 2) + sum(odd, (l - 1) / 2, (r) / 2 - 1);
    }
}

void my_swap(Treap* &odd, Treap* &even, int l, int r) {
    Treap *one_odd, *two_odd;
    Treap *three_odd, *four_odd;
    split(odd, r / 2 - 1, one_odd, two_odd);
    split(one_odd, (l - 1) / 2 - 1, three_odd, four_odd);

    Treap *one_even, *two_even;
    Treap *three_even, *four_even;
    split(even, (r - 1) / 2, one_even, two_even);
    split(one_even, (l) / 2 - 1, three_even, four_even);

    odd = merge(merge(three_odd, four_even), two_odd);
    even = merge(merge(three_even, four_odd), two_even);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int cmd;
    int count_tests = 0;
    int n, m, x, y;
    std::cin >> n >> m;
    while(n != 0 && m != 0) {
        Treap *odd = NULL; // числа с чётными индексами
        Treap *even = NULL;
        ++count_tests;
        long long value;
        for (int i = 0; i < n; i++) { //считываем последовательность
            std::cin >> value;
            if (i % 2 == 0){
                insert(even, value, (i + 1) / 2);
            }
            else {
                insert(odd, value, (i + 1) / 2);
            }
        }
        std::vector<long long> result;
        for (int i = 0; i < m; ++i) { //считываем команды
            std::cin >> cmd >> x >> y;
            switch (cmd) {
                case 1: { //взять отрезок чётной длины от x до y и поменять местами число x с x+1, x+2 с x+3, и т.д.
                    my_swap(odd, even, x, y);
                    break;
                }
                case 2: { //посчитать сумму чисел на произвольном отрезке от x до y.
                    result.push_back(sum(odd, even, x, y));
                    break;
                }
            }
        }
        std::cout << "Swapper " << count_tests << ":\n";
        for(int i = 0; i < result.size(); ++i){
            std::cout << result[i] << '\n';
        }
        std::cout << '\n';
        std::cin >> n >> m;
        delete odd, even;
    }
}
/*
 * Перед возвращением в штаб-квартиру корпорации Аазу и Скиву пришлось заполнить на местной таможне декларацию о доходах за время визита. Получилась довольно внушительная последовательность чисел. Обработка этой последовательности заняла весьма долгое время.

— Своппер кривой, — со знанием дела сказал таможенник.

— А что такое своппер? — спросил любопытный Скив.

Ааз объяснил, что своппер — это структура данных, которая умеет делать следующее.

• Взять отрезок чётной длины от x до y и поменять местами число x с x+1, x+2 с x+3, и т.д.
• Посчитать сумму чисел на произвольном отрезке от a до b.

Учитывая, что обсчёт может затянуться надолго, корпорация "МИФ" попросила Вас решить проблему со своппером и промоделировать ЭТО эффективно.
Формат входных данных
Во входном файле заданы один или несколько тестов. В первой строке каждого теста записаны число N - длина последовательности и число M - число операций (1 ≤ N, M ≤ 100000). Во второй строке теста содержится N целых чисел, не превосходящих 106 по модулю - сама последовательность.
Далее следуют M строк - запросы в формате "1 xi yi" - запрос первого типа, и "2 ai bi" - запрос второго типа. Сумма всех N и M по всему файлу не превосходит 200000. Файл завершается строкой из двух нулей. Гарантируется, что xi < yi, а ai ≤ bi.
Формат результата
Для каждого теста выведите ответы на запросы второго типа, как показано в примере. Разделяйте ответы на тесты пустой строкой.
Примеры
Входные данные	Результат работы
5 5
1 2 3 4 5
1 2 5
2 2 4
1 1 4
2 1 3
2 4 4
2 1
1 2
2 1 2
0 0
Swapper 1:
10
9
2

Swapper 2:
3

 */