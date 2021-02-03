#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > graph;
vector<bool> inLoop;
vector<bool> visit;
int N;
bool checkCycle(int src, int parent, int start) {
	if (src == start && visit[src]) {
		return true;
	}

	visit[src] = true;
	bool ret = false;
	int size = graph[src].size();

	for (int i = 0; i < size; i++) {
		int dst = graph[src][i];
		if ((dst == parent) || (visit[dst] && dst != start)) {
			continue;
		}

		ret = ret ? true : checkCycle(dst, src, start);
	}

	return ret;
}
int bfs(int start) {
	queue<pair<int, int> > q;
	q.push(make_pair(start, 0));
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (inLoop[cur]) {
			return dist;
		}

		int size = graph[cur].size();
		for (int i = 0; i < size; i++) {
			int dst = graph[cur][i];

			if (visit[dst]) {
				continue;
			}
			visit[dst] = true;
			q.push(make_pair(dst, dist + 1));
		}
	}
	return -1;
}
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N;
	graph.resize(N + 1);
	inLoop.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int src, dst;
		cin >> src >> dst;

		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}

	for (int i = 1; i <= N; i++) {
		visit = vector<bool>(N + 1, false);

		if (checkCycle(i, -1, i)) {
			inLoop[i] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		visit = vector<bool>(N + 1, false);
		cout << bfs(i) << ' ';
	}
}