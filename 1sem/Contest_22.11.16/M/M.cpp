#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct heap
{
    int *a;
    int h_size;
    void sift_down(int n, int index);
    void sift_up(int index);
    void insert(int x);
    void extract_min();
    void clear();
    heap ();
    ~heap();
};

heap::heap()
{
    a = new int[200000];
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
    if (left < n && a[left] < a[imax]) {
        imax = left;
    }
    if (right < n && a[right] < a[imax]){
        imax = right;
    }
    if (index != imax){
        swap(a[index], a[imax]);
        sift_down(n, imax);
    }
}

void heap::sift_up(int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(a[index] >= a[parent]){
            return;
        }
        swap(a[index], a[parent]);
        index = parent;
    }
}

void heap::insert(int x)
{
    a[h_size] = x;
    this->sift_up(h_size);
    ++this->h_size;
}

void heap::extract_min()
{
    swap(a[0], a[h_size - 1]);
    --this->h_size;
    this->sift_down(this->h_size, 0);
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
    char s[12];
    for(int i = 0; i < m; ++i){
        cin >> s;
        if (strcmp(s, "insert") == 0){
            cin >> x;
            h->insert(x);
            cout << "ok" << endl;
        }
        if (strcmp(s, "extract_min") == 0 || strcmp(s, "get_min") == 0){
            if(h->h_size){
                cout << h->a[0] << endl;
                if (strcmp(s, "extract_min") == 0){
                   h->extract_min();
                }
            }
            else {
                cout << "error" << endl;
            }
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
