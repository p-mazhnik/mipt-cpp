#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
	int amount_subsequences;
	int amount_opening_brackets;
	int amount_closing_brackets;
	Node() : amount_subsequences(0), amount_opening_brackets(0), amount_closing_brackets(0) {}
	Node(int a, int b, int c) : amount_subsequences(a), amount_opening_brackets(b), amount_closing_brackets(c) {}
};

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	string sequences;
	cin >> sequences;
	int new_size = 1;
	while (new_size < sequences.size()) {
		new_size *= 2;
	}
	sequences.resize(new_size, ' ');
	vector<Node> segment_tree(2 * sequences.size() - 1);
	for (int i = 0; i < sequences.size(); i++) {
		if (sequences[i] == '(') {
			segment_tree[sequences.size() + i - 1] = Node(0, 1, 0);
		}
		else if (sequences[i] == ')') {
			segment_tree[sequences.size() + i - 1] = Node(0, 0, 1);
		}
		else {
			segment_tree[sequences.size() + i - 1] = Node(0, 0, 0);
		}
	}
	for (int i = sequences.size() - 2; i >= 0; i--) {
		int new_subsequences = min(segment_tree[2 * i + 1].amount_opening_brackets, segment_tree[2 * i + 2].amount_closing_brackets);
		segment_tree[i].amount_subsequences = segment_tree[2 * i + 1].amount_subsequences + segment_tree[2 * i + 2].amount_subsequences
			+ 2 * new_subsequences;
		segment_tree[i].amount_opening_brackets = segment_tree[2 * i + 1].amount_opening_brackets + segment_tree[2 * i + 2].amount_opening_brackets
			- new_subsequences;
		segment_tree[i].amount_closing_brackets = segment_tree[2 * i + 1].amount_closing_brackets + segment_tree[2 * i + 2].amount_closing_brackets
			- new_subsequences;
	}
	int m, left, right;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> left >> right;
		left--;
		right--;
		Node left_answer, right_answer;
		left += segment_tree.size() / 2;
		right += segment_tree.size() / 2;
		while (left <= right) {
			if (left % 2 == 0) {
				int new_subsequences = min(left_answer.amount_opening_brackets, segment_tree[left].amount_closing_brackets);
				left_answer.amount_subsequences += segment_tree[left].amount_subsequences + 2 * new_subsequences;
				left_answer.amount_opening_brackets += segment_tree[left].amount_opening_brackets - new_subsequences;
				left_answer.amount_closing_brackets += segment_tree[left].amount_closing_brackets - new_subsequences;
				left++;
			}
			if (right % 2 == 1) {
				int new_subsequences = min(segment_tree[right].amount_opening_brackets, right_answer.amount_closing_brackets);
				right_answer.amount_subsequences += segment_tree[right].amount_subsequences + 2 * new_subsequences;
				right_answer.amount_opening_brackets += segment_tree[right].amount_opening_brackets - new_subsequences;
				right_answer.amount_closing_brackets += segment_tree[right].amount_closing_brackets - new_subsequences;
				right--;
			}
			if (left > right) {
				break;
			}
			left = (left - 1) / 2;
			right = (right - 1) / 2;
		}
		cout << left_answer.amount_subsequences + right_answer.amount_subsequences
			+ 2 * min(right_answer.amount_closing_brackets, left_answer.amount_opening_brackets) << endl;
	}
	return 0;
}