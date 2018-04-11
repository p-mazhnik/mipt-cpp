#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Node
{
    int info;
    int num;
};

struct heap
{
    Node *a;
    int *b;
    char *s;
    int h_size;
    void sift_down(int index);
    void sift_up(int index);
    void insert(int x, int j);
    void extract_min();
    void h_delete(int i);
    heap ();
    ~heap();
};

heap::heap()
{
    s = new char[4];
    b = new int[200000];
    a = new Node[200000];
    this->h_size = 0;
}

heap::~heap()
{
    delete []a;
    delete []b;
}

void heap::sift_down(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int in = index;
    if(strcmp(s, "min") == 0){
        if (left < this->h_size && a[left].info < a[in].info) {
            in = left;
        }
        if (right < this->h_size && a[right].info < a[in].info){
            in = right;
        }
    }
    if(strcmp(s, "max") == 0){
        if (left < this->h_size && a[left].info > a[in].info) {
            in = left;
        }
        if (right < this->h_size && a[right].info > a[in].info){
            in = right;
        }
    }
    if (index != in){
        swap(a[index], a[in]);
        sift_down(in);
    }
}

void heap::sift_up(int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(strcmp(s, "min") == 0){
            if(a[index].info < a[parent].info){
                swap(a[index], a[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
        else{
            if(a[index].info > a[parent].info){
                swap(a[index], a[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
}

void heap::extract_min()
{
    b[a[0].num] = -1;
    swap(a[0], a[h_size - 1]);
    --this->h_size;
    this->sift_down(0);
}

void heap::insert(int x, int j)
{
    a[h_size].info = x;
    a[h_size].num = j;
    b[a[h_size].num] = x;
    this->sift_up(h_size);
    ++this->h_size;
}

void heap::h_delete(int i)
{
    if (b[i] == -1){
        return;
    }
    int l;
    int q;
    if(strcmp(s, "min") == 0){
        l = -1;
    }
    else{
        l = 1e9 + 1;
    }
    q = h_size - 1;
        for(; q >= 0 && a[q].num != i; --q){}
        if(h_size != 0 && q >= 0 && a[q].num == i){
            a[q].info = l;
            b[a[q].num] = -1;
            this->sift_up(q);
            swap(a[0], a[h_size - 1]);
            --h_size;
            this->sift_down(0);
        }
        else{
            return;
        }
}

struct heap_2
{
    heap *hmin;
    heap *hmax;
    void extract(heap *h1, heap* h2);
    void clear();
    heap_2();
    ~heap_2();
};

void heap_2::extract(heap *h1, heap* h2)
{
    h2->h_delete(h1->a[0].num);
    h1->b[h1->a[0].num] = -1;
    swap(h1->a[0], h1->a[h1->h_size - 1]);
    --h1->h_size;
    h1->sift_down(0);
}

void heap_2::clear()
{
    while(hmin->h_size){
        hmin->extract_min();
        hmax->extract_min();
    }
}

heap_2::heap_2()
{
    hmin = new heap;
    hmax = new heap;
}

heap_2::~heap_2()
{
    delete hmin;
    delete hmax;
}

int main()
{
    int x;
    heap_2 *h = new heap_2;
    char smin[] = "min";
    char smax[] = "max";
    h->hmin->s = smin;
    h->hmax->s = smax;
    int m;
    cin >> m;
    char s[15];
    for(int i = 0, j = 1; i < m; ++i){
        cin >> s;
        if (strcmp(s, "insert") == 0){
            cin >> x;
            h->hmin->insert(x, j);
            h->hmax->insert(x, j);
            ++j;
            cout << "ok" << endl;
        }
        if (strcmp(s, "extract_min") == 0 || strcmp(s, "get_min") == 0){
            if(h->hmin->h_size){
                cout << h->hmin->a[0].info << endl;
                if (strcmp(s, "extract_min") == 0){
                   h->extract(h->hmin, h->hmax);
                }
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "extract_max") == 0 || strcmp(s, "get_max") == 0){
            if(h->hmax->h_size){
                cout << h->hmax->a[0].info << endl;
                if (strcmp(s, "extract_max") == 0){
                   h->extract(h->hmax, h->hmin);
                }
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "size") == 0){
            cout << h->hmin->h_size << endl;
        }
        if (strcmp(s, "clear") == 0){
            h->clear();
            cout << "ok" << endl;
        }
    }
    delete h;
    return 0;
}
