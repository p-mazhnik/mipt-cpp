#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Node
{
    int point;
    char *name;
    Node();
};

void swap(Node a, Node b)
{
    Node k;
    k.name = a.name;
    k.point = a.point;
    a.name = b.name;
    a.point = b.point;
    b.name = k.name;
    b.point = k.point;
}

Node::Node()
{
    name = new char[10];
}

struct heap
{
    Node *a;
    int h_size;
    void sift_down(int n, int index);
    void sift_up(int index);
    void insert(int x, char *s);
    void extract_min();
    void heap_sort();
    void clear();
    heap ();
    ~heap();
};

heap::heap()
{
    a = new Node[20];
    this->h_size = 0;
}

heap::~heap()
{
    delete []a;
}

void heap::sift_down(int n, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int imax = index;
    if (left < n && a[left].point < a[imax].point) {
        imax = left;
    }
    if (left < n && a[left].point == a[imax].point && strcmp(a[left].name, a[imax].name) >= 1){
        imax = left;
    }
    if (right < n && a[right].point < a[imax].point){
        imax = right;
    }
    if (right < n && a[right].point == a[imax].point && strcmp(a[right].name, a[imax].name) >= 1){
        imax = right;
    }
    if (index != imax){
        swap(a[imax], a[index]);
        sift_down(n, imax);
    }
}

void heap::sift_up(int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(a[index].point >= a[parent].point){
            return;
        }
        swap(a[index], a[parent]);
        index = parent;
    }
}

void heap::insert(int x, char *s)
{
    a[h_size].point = x;
    a[h_size].name = s;
    this->sift_up(h_size);
    ++this->h_size;
}

void heap::extract_min()
{
    swap(a[0], a[h_size - 1]);
    --this->h_size;
    this->sift_down(this->h_size, 0);
}

void heap::heap_sort()
{
    for (int i = h_size - 1; i > 0; --i){
        swap(a[0], a[i]);
        sift_down (i, 0);
    }
}

void heap::clear()
{
    this->h_size = 0;
}

int main()
{
    int x;
    heap *h = new heap;
    int m;
    cin >> m;
    char a[10];
    for(int i = 0; i < m; ++i){
        cin >> a;
        if(strcmp(a, "put") == 0){
            char *s = new char [10];
            cin >> s >> x;
            h->insert(x, s);
            cout << "ok" << endl;
            delete []s;
        }
        if(strcmp(a, "sort") == 0){
            h->heap_sort();
            for(int i = 0; i < h->h_size; ++i){
                cout << h->a[i].name << ' ' << h->a[i].point << endl;
            }
        }

    }
    delete h;
    return 0;
}
