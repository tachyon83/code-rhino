#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
vector<pair<int, int>> edges[1001];
int dijkstra(int start, int end, int N);

int main() {
	int N, M;
	int start, end;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		edges[a].push_back({ b,val });
	}
	cin >> start >> end;

	cout << dijkstra(start, end, N);
}

int dijkstra(int start, int end, int N) {
	vector<int> d(N + 1, INF);
	d[start] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int minNode = pq.top().second;
		int dis = -(pq.top().first);
		pq.pop();

		if (d[minNode] < dis) continue;

		for (int i = 0; i < edges[minNode].size(); i++) {
			int next = edges[minNode][i].first;
			int val = edges[minNode][i].second + dis;
			if (val < d[next]) {
				d[next] = val;
				pq.push({ -val,next });
			}
		}
	}
	return d[end];
}
