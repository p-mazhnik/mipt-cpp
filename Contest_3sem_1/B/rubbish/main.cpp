#include <iostream>
#include <vector>

using namespace std;

unsigned int MAX = (1 << 24);

unsigned int a, b;
unsigned int cur = 0;

unsigned int nextRand() {
	cur = cur * a + b;
	return cur >> 8;
}

int main() {
	vector<unsigned int> array(MAX);
	unsigned int m, q;
	cin >> m >> q >> a >> b;
	unsigned int add, left, right;
	for (unsigned int i = 0; i < m; i++) {
		add = nextRand();
		left = nextRand();
		right = nextRand();
		if (left > right) {
			swap(left, right);
		}
		array[left] += add;
		if (right + 1 < MAX) {
			array[right + 1] -= add;
		}
	}
	vector<unsigned int> prefix_sum(MAX);
	unsigned int current = array[0];
	prefix_sum[0] = array[0];
	for (unsigned int i = 1; i < MAX; i++) {
		current += array[i];
		prefix_sum[i] = current + prefix_sum[i - 1];
	}
	unsigned int result = 0;
	for (unsigned int i = 0; i < q; i++) {
		left = nextRand();
		right = nextRand();
		if (left > right) {
			swap(left, right);
		}
		if (left != 0) {
			result += prefix_sum[right] - prefix_sum[left - 1];
		}
		else {
			result += prefix_sum[right];
		}
	}
	cout << result << endl;
	return 0;
}