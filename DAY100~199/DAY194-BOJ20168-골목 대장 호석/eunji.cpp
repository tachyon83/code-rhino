#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321;
using namespace std;

int main() {
	vector<pair<int, int>> map[11];
	int dist[11];
	int N, M, A, B, C;
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x].push_back({ y,z });
		map[y].push_back({ x,z });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[A] = 0;
	int max[11] = { 0. };
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,A });
	while (!pq.empty()) {
		int val = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (val < dist[cur]) continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int cost = map[cur][i].second + val;
			if (dist[next] <= cost || cost > C) continue;
			dist[next] = cost;
			if ((map[cur][i].second) > max[next]) max[next] = (map[cur][i].second);
			pq.push({ cost,next });
		}
	}
	cout << max[B];

}
