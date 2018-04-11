#include <iostream>
#include <cstring>

using namespace std;

struct heap
{
    int sizeHeap;
    int *a;
    int *heapIndex;
    int countInsert;
    heap();
    void insert_heap(int x);
    int extract_min();
    int get_min();
    bool isEmpty();
    void clear_heap();
    bool delete_x(int x);
    bool change_x(int x, int y);
    void print_array();
    ~heap();
};

heap::heap()
{
    int n = 200000;
    sizeHeap = 0;
    this->a = new int[n];
    this->heapIndex = new int[n];
    this->countInsert = 0;
}

heap::~heap()
{
    delete [](this->a);
    delete [](this->heapIndex);
}

bool heap::isEmpty()
{
    return (this->sizeHeap == 0);
}

int leftCh (int i)
{
    return 2 * i + 1;
}

int rightCh (int i)
{
    return 2 * i + 2;
}

void sift_up(int *heapIndex, int *a, int i)
{
    bool flag = true;
    while(i > 0 && flag)
    {
        int parent = (i - 1) / 2;
        if(a[heapIndex[i]] < a[heapIndex[parent]])
        {
            swap(heapIndex[i], heapIndex[parent]);
            i = parent;
        }
        else
        {
            flag = false;
        }
    }
}

void sift_down(int *heapIndex, int *a, int n, int index)
{
    int left = leftCh(index);
    int right = rightCh(index);
    int imin = index;
    if (left  < n && a[heapIndex[left]] < a[heapIndex[imin]])
        imin = left;
    if (right < n && a[heapIndex[right]] < a[heapIndex[imin]])
        imin = right;
    if (index != imin)
    {
        swap(heapIndex[index], heapIndex[imin]);
        sift_down(heapIndex, a, n, imin);
    }
}

void heap::insert_heap(int x)
{
    int index = this->sizeHeap;
    this->a[this->countInsert] = x;
    this->heapIndex[index] = this->countInsert;
    sift_up(this->heapIndex, this->a, index);
    (this->sizeHeap)++;
    (this->countInsert)++;
}

int heap::extract_min()
{
    int index = sizeHeap - 1;
    int x = a[heapIndex[0]];
    a[heapIndex[0]] = -1;
    heapIndex[0] = heapIndex[index];
    sift_down(this->heapIndex, this->a, index + 1, 0);
    (this->sizeHeap)--;
    return x;
}

int heap::get_min()
{
    int x = this->a[heapIndex[0]];
    return x;
}

void heap::clear_heap()
{
    while(!(this->isEmpty()))
        this->extract_min();
}

bool heap::delete_x(int x)
{
    if(x >= countInsert || a[x] == -1)
        return false;
    else
    {
        change_x(x, -1);
        extract_min();
        return true;
    }
}

bool heap::change_x(int x, int y)
{
    if(x >= countInsert || a[x] == -1)
        return false;
    else
    {
        int temp = a[x];
        a[x] = y;
        int i = 0;
        while(x != heapIndex[i])
            i++;
        sift_up(this->heapIndex, this->a, i);
        sift_down(this->heapIndex, this->a, this->sizeHeap, i);
        return true;
    }
}

void heap::print_array()
{
    for(int i = 0; i < sizeHeap; i++)
        cout << a[heapIndex[i]] << ' ';
    cout << '\n';
}

int main()
{
    heap myHeap;
    char comand[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
       cin >> comand;
       if(!strcmp(comand, "insert"))
       {
           int x;
           cin >> x;
           myHeap.insert_heap(x);
           cout << "ok";
       }
       if(!strcmp(comand, "extract_min"))
       {
           if(myHeap.isEmpty())
                cout << "error";
           else
                cout << myHeap.extract_min();
       }
       if(!strcmp(comand, "get_min"))
       {
            if(myHeap.isEmpty())
                cout << "error";
            else
                cout << myHeap.get_min();
       }
       if(!strcmp(comand, "size"))
       {
           cout << myHeap.sizeHeap;
       }
       if(!strcmp(comand, "clear"))
       {
           myHeap.clear_heap();
           cout << "ok";
       }
       if(!strcmp(comand, "delete"))
       {
           int x;
           cin >> x;
           x--;
           if(myHeap.isEmpty() || !myHeap.delete_x(x))
            cout << "error";
           else
               cout << "ok";
       }
       if(!strcmp(comand, "change"))
       {
           int x, y;
           cin >> x >> y;
           x--;
           if(myHeap.isEmpty() || !myHeap.change_x(x, y))
            cout << "error";
           else
            cout << "ok";
       }
       /*if(!strcmp(comand, "index"))
       {
           int x;
           cin >> x;
           cout << myHeap.pIndex[x];
       }*/
       cout << '\n';
    }
    return 0;
}
