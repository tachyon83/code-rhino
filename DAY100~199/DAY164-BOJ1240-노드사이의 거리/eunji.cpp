#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int minPath(int x, int y, vector<vector<int>> node, int N);

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> node(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N - 1; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		node[x][y] = val;
		node[y][x] = val;
	}
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		cout << minPath(start, end, node, N) << endl;
	}
}

int minPath(int x, int y, vector<vector<int>> node, int N) {

	vector<bool> visit(N + 1, 0);
	priority_queue<pair<int, int>> q;
	visit[x] = true;
	for (int i = 1; i <= N; i++) {
		if (node[x][i] != 0) q.push({ -node[x][i], i });
	}
	while (!q.empty()) {
		int val = -(q.top().first);
		int start = q.top().second;
		if (start == y) return val;
		q.pop();
		visit[start] = true;
		for (int i = 1; i <= N; i++) {
			if (node[start][i] != 0 && visit[i] == false)q.push({ -val - node[start][i],i });
		}
	}
}
