#include <iostream>
#include <algorithm>
#include <vector>
//#include <conio.h>
using namespace std;
typedef long long ull;

struct Treap {
	int prior; // ���������
	ull data; // ����	

	ull sum; // �����
	int size; // ������

	Treap *l, *r; // ����������
	Treap(ull data) : data(data), prior(rand()), size(1), l(NULL), r(NULL), sum(data) {} // �����������
};

ull sum(Treap* v) {
	return (v == NULL) ? 0 : v->sum;
}
int sz(Treap* v) {
	return (v == NULL) ? 0 : v->size;
}

void update(Treap* v) {
	v->size = 1 + sz(v->l) + sz(v->r);
	v->sum = v->data + sum(v->l) + sum(v->r);
}

void Split(Treap* root, ull x, Treap* &L, Treap* &R) {
	if (root == NULL) {
		L = NULL;
		R = NULL;
		return;
	}
	if (x >= root->data) {
		L = root;
		Split(root->r, x, root->r, R);
	}
	else {
		R = root;
		Split(root->l, x, L, root->l);
	}
	update(root);
}

void another_Split(Treap* root, ull x, Treap* &L, Treap* &R, int left = 0) {
	if (root == NULL) {
		L = NULL;
		R = NULL;
		return;
	}
	int key = left + sz(root->l);
	if (key <= x) {
		L = root;
		another_Split(root->r, x, root->r, R, key + 1);
	}
	else {
		R = root;
		another_Split(root->l, x, L, root->l, left);
	}
	update(root);
}


Treap* Merge(Treap* L, Treap* R) {
	if (L == NULL) {
		return R;
	}
	else if (R == NULL) {
		return L;
	}
	if (L->prior >= R->prior) {
		L->r = Merge(L->r, R);
		update(L);
		return L;
	}
	else {
		R->l = Merge(L, R->l);
		update(R);
		return R;
	}
}

bool find(Treap* &root, ull x) {
	if (root == NULL) {
		return false;
	}
	if (root->data == x) {
		return true;
	}
	if (root->data > x) {
		return find(root->l, x);
	}
	else {
		return find(root->r, x);
	}
}

void insert(Treap* &root, ull x) {
	if (!find(root, x)) {
		Treap* new_v = new Treap(x);
		Treap* tmp_l, *tmp_r;
		Split(root, x, tmp_l, tmp_r);
		root = Merge(tmp_l, Merge(new_v, tmp_r));
	}
}

void another_insert(Treap* & root, ull x, int i) {
	Treap* new_v = new Treap(x);
	Treap* tmp_l, *tmp_r;
	another_Split(root, i, tmp_l, tmp_r);
	root = Merge(tmp_l, Merge(new_v, tmp_r));
}

void erase(Treap* &root, ull x) {
	if (find(root, x)) {
		Treap* t1, *t2, *t3, *t4;
		Split(root, x, t1, t2);
		Split(t1, x - 1, t3, t4);
		root = Merge(t3, t2);
	}
}

ull sum_on_range(Treap* &root, int l, int r) {
	Treap* t1, *t2, *t3, *t4;
	another_Split(root, r, t1, t2);
	another_Split(t1, l - 1, t3, t4);
	if (t4 != NULL)
		update(t4);
	ull result = sum(t4);
	root = Merge(t3, Merge(t4, t2));
	return result;
}

ull real_sum(Treap* froot, Treap* sroot, int l, int r) {
	if (l == 0 && r == 0) {
		return sum_on_range(froot, ((l + 1) / 2), r / 2);
	}
	else {
		return sum_on_range(froot, ((l + 1) / 2), r / 2) + sum_on_range(sroot, (l / 2), (r - 1) / 2);
	}
}

void swapper(Treap*& froot, Treap*& sroot, int l, int r) {
	Treap* t1_f, *t2_f, *t3_f, *t4_f;
	Treap* t1_s, *t2_s, *t3_s, *t4_s;
	another_Split(froot, r / 2, t1_f, t2_f);
	another_Split(t1_f, ((l + 1) / 2) - 1 , t3_f, t4_f);
	if (t4_f != NULL)
		update(t4_f);
	another_Split(sroot, (r - 1) / 2, t1_s, t2_s);
	another_Split(t1_s, (l / 2) - 1, t3_s, t4_s);
	if (t4_s != NULL)
		update(t4_s);
	froot = Merge(Merge(t3_f, t4_s), t2_f);
	sroot = Merge(Merge(t3_s, t4_f), t2_s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int count_swapper = 1;
	while (n != 0 && m != 0) {
		Treap* treap_nechet = NULL;
		Treap* treap_chet = NULL;
		int value;
		for (int i = 0; i < n; i++) {
			cin >> value;
			if (i % 2 == 0) {
				another_insert(treap_nechet, value, (i / 2));
			}
			else {
				another_insert(treap_chet, value, (i / 2));
			}
		}
		int comand;
		vector<ull> res;
		for (int i = 0; i < m; i++) {
			cin >> comand;
			int first, second;
			cin >> first >> second;
			if (comand == 1) {
				swapper(treap_nechet, treap_chet, first - 1, second - 1);
			}
			if (comand == 2) {
					res.push_back(real_sum(treap_nechet, treap_chet, first - 1, second - 1));
			}
		}
		cout << "Swapper " << count_swapper << ":" << endl;
		count_swapper++;
		for (auto a : res) {
			cout << a << endl;
		}
		cout << endl;
		cin >> n >> m;
	}
	//_getch();
}