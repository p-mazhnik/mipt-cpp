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
    int h_size;
    void sift_down(int index);
    void sift_up(int index);
    void insert(int x, int j);
    void extract_min();
    void clear();
    void change(int i, int x);
    void h_delete(int i);
    heap ();
    ~heap();
};

heap::heap()
{
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
    a[h_size].num = j;
    b[a[h_size].num] = x;
    this->sift_up(h_size);
    ++this->h_size;
}

void heap::extract_min()
{
    b[a[0].num] = -1;
    swap(a[0], a[h_size - 1]);
    --this->h_size;
    this->sift_down(0);
}

void heap::change(int i, int x)
{
    if (b[i] == -1){
        cout << "error" << endl;
        return;
    }
    int q = 0;
    for(; q < h_size && a[q].num != i; ++q){}
    if(h_size != 0 && q < h_size && a[q].num == i){
        a[q].info = x;
        b[a[q].num] = x;
        this->sift_up(q);
        this->sift_down(q);
        cout << "ok" << endl;
    }
    else{
        cout << "error" << endl;
    }
}

void heap::h_delete(int i)
{
    if (b[i] == -1){
        cout << "error" << endl;
        return;
    }
    int q = 0;
    for(; q < h_size && a[q].num != i; ++q){}
    if(h_size != 0 && q < h_size && a[q].num == i){
        a[q].info = -1;
        b[a[q].num] = -1;
        this->sift_up(q);
        swap(a[0], a[h_size - 1]);
        --h_size;
        this->sift_down(0);
        cout << "ok" << endl;
    }
    else{
        cout << "error" << endl;
    }
}

void heap::clear()
{
    while(h_size){
        this->extract_min();
    }
}

int main()
{
    int x;
    int num;
    heap *h = new heap;
    int m;
    cin >> m;
    char s[15];
    for(int i = 0, j = 1; i < m; ++i){
        cin >> s;
        if (strcmp(s, "insert") == 0){
            cin >> x;
            h->insert(x, j);
            ++j;
            cout << "ok" << endl;
        }
        if (strcmp(s, "extract_min") == 0 || strcmp(s, "get_min") == 0){
            if(h->h_size){
                cout << h->a[0].info << endl;
                if (strcmp(s, "extract_min") == 0){
                   h->extract_min();
                }
            }
            else {
                cout << "error" << endl;
            }
        }
        if (strcmp(s, "change") == 0){
            cin >> num >> x;
            h->change(num, x);
        }
        if (strcmp(s, "delete") == 0){
            cin >> num;
            h->h_delete(num);
        }
        if (strcmp(s, "size") == 0){
            cout << h->h_size << endl;
        }
        if (strcmp(s, "clear") == 0){
            h->clear();
            cout << "ok" << endl;
        }
    }
    delete h;
    return 0;
}
