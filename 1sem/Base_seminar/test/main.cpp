#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
    int st_min;
};

struct stack
{
    Node *head;
    int st_size;
    stack();
    ~stack();
    bool is_empty();
    void push(int x);
    void pop();

};

stack::stack()
{
    head = NULL;
    st_size = 0;
}

bool stack::is_empty()
{
    return head == NULL;
}

void stack::push(int x)
{
    Node *n = new Node;
    n->info = x;
    if(is_empty() || x < head->st_min){
        n->st_min = x;
    }
    else {
        n->st_min = head->st_min;
    }
    n->next = head;
    head = n;
    ++st_size;
}

void stack::pop()
{
    Node *k = head->next;
    delete head;
    head = k;
    --st_size;
}

struct heap
{
    int *a;
    int h_size;
    heap();
    ~heap();
    void sift_down(int n, int index);
    void sift_up(int index);
    void insert(int x);
    void extract_min();
};

heap::heap()
{
    a = new int[20];
    h_size = 0;
}

void heap::sift_down(int n, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 1;
    int imin = index;
    if(left < n && a[left] < a[imin]){
        imin = left;
    }
    if(right < n && a[right] < a[imin]){
        imin = right;
    }
    if(index != imin){
        swap(a[index], a[imin]);
        sift_down(n, imin);
    }
}

void heap::sift_up(int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(a[parent] <= a[index]){
            return;
        }
        else{
            swap(a[index], a[parent]);
            index = parent;
        }
    }
}

void heap::insert(int x)
{
    a[h_size] = x;
    sift_up(h_size);
    ++h_size;
}

void heap::extract_min()
{
    swap(a[0], a[h_size - 1]);
    --h_size;
    sift_down(h_size, 0);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
