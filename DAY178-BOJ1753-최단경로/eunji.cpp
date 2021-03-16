#define INF 987654321
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int, int>> node[20001];
int start;
int dist[20001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E;
	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ v,w });
	}
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int val = -(pq.top().first);
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < val) continue;
		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i].first;
			int cost = node[cur][i].second + val;
			if (cost < dist[next]) {
				dist[next] = cost;
				pq.push({-cost,next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i]>=INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}
