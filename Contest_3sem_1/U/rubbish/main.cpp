#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(pair<int, int> vertex, vector<vector<char>>& table, vector<vector<int>>& color, 
	queue<pair<int, int>>& bfs_queue, vector<vector<pair<int,int>>>& parent) {
	color[vertex.first][vertex.second] = 1;
	bfs_queue.push(vertex);
	while (!bfs_queue.empty()) {
		pair<int, int> current = bfs_queue.front();
		bfs_queue.pop();
		pair<int, int> right = current, left = current, up = current, down = current;
		while (right.second < table[0].size() && table[right.first][right.second] != '#') {
			right.second++;
		}
		right.second = right.second - (right.second - current.second - 1) / 2 - 1;
		while (left.second >= 0 && table[left.first][left.second] != '#') {
			left.second--;
		}
		left.second = left.second + (current.second - left.second - 1) / 2 + 1;
		while (up.first >= 0 && table[up.first][up.second] != '#') {
			up.first--;
		}
		up.first = up.first + (current.first - up.first - 1) / 2 + 1;
		while (down.first < table.size() && table[down.first][down.second] != '#') {
			down.first++;
		}
		down.first = down.first - (down.first - current.first - 1) / 2 - 1;
		vector<pair<int, int>> adjacent = { left, right, up, down };
		for (int i = 0; i < adjacent.size(); i++) {
			if (color[adjacent[i].first][adjacent[i].second] == 0) {
				parent[adjacent[i].first][adjacent[i].second] = current;
				color[adjacent[i].first][adjacent[i].second] = 1;
				bfs_queue.push(adjacent[i]);
			}
		}
	}
	color[vertex.first][vertex.second] = 2;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> table(n, vector<char>(m));
	vector<vector<int>> color(n, vector<int>(m));
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
	char current;
	pair<int, int> start, finish;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> current;
			if (current == 'S') {
				start = make_pair(i, j);
			}
			if (current == 'T') {
				finish = make_pair(i, j);
			}
			table[i][j] = current;
		}
	}
	queue<pair<int, int>> bfs_queue;
	bfs(start, table, color, bfs_queue, parent);
	if (parent[finish.first][finish.second].first == -1) {
		cout << -1 << endl;
	}
	else {
		int result = 0;
		pair<int, int> current = finish;
		while (current != start) {
			result++;
			current = parent[current.first][current.second];
		}
		cout << result << endl;
	}
	return 0;
}