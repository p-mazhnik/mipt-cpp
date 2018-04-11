#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Node
{
    int info;
    int dt;
};

struct heap
{
    Node *a;
    int h_size;
    void sift_down(int index);
    void sift_up(int index);
    void insert(int x, int j);
    void extract_min();
    void clear();
    void print_array();
    heap ();
    ~heap();
};

heap::heap()
{
    a = new Node[100001];
    this->h_size = 0;
}

heap::~heap()
{
    delete []a;
}

void heap::sift_down(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int imin= index;
    if (left < this->h_size && a[left].info < a[imin].info) {
        imin= left;
    }
    if (right < this->h_size && a[right].info < a[imin].info){
        imin= right;
    }
    if (index != imin){
        swap(a[index], a[imin]);
        sift_down(imin);
    }
}

void heap::sift_up(int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(a[index].info < a[parent].info){
            swap(a[index], a[parent]);
            index = parent;
        }
        else{
            return;
        }
    }
}

void heap::insert(int x, int j)
{
    a[h_size].info = x;
    a[h_size].dt = j;
    this->sift_up(h_size);
    ++this->h_size;
}

void heap::extract_min()
{
    swap(a[0], a[h_size - 1]);
    --this->h_size;
    this->sift_down(0);
}

void heap::clear()
{
    while(h_size){
        this->extract_min();
    }
}

void heap::print_array() // вывод массива длины n на экран
{
    for (int i = 0; i < h_size; ++i) {
            cout << a[i].info << ' ';
    };
    cout << endl << endl;
}

int main()
{
    int time;
    int dt;
    heap *h = new heap;
    heap *h2 = new heap;
    int m;
    cin >> m;
    int k = m;
    for(int i = 0; i < m; ++i){
        cin >> time >> dt;
        h->insert(time, dt);
    }
    for(int i = 0; i < m - 1; ++i){
        h2->insert(h->a[0].info + h->a[0].dt, 0);
        h->extract_min();
        //h->print_array();
        if(h->a[0].info >= h2->a[0].info){
            h2->extract_min();
            --k;
        }
    }
    cout << k;
    delete h2;
    delete h;
    return 0;
}
