#define INF 987654321
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int, int>> node[1001];
vector<pair<int, int>> nreverse[1001];
int start;
int dist[1001];
int dreverse[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, start;
	cin >> N >> M >> start;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		dreverse[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ v,w });
		nreverse[v].push_back({ u,w });
	}
	dist[start] = 0;
	dreverse[start] = 0;
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
				pq.push({ -cost,next });
			}
		}
	}
	pq.push({ 0,start });
	while (!pq.empty()) {
		int val = -(pq.top().first);
		int cur = pq.top().second;
		pq.pop();
		if (dreverse[cur] < val) continue;
		for (int i = 0; i < nreverse[cur].size(); i++) {
			int next = nreverse[cur][i].first;
			int cost = nreverse[cur][i].second + val;
			if (cost < dreverse[next]) {
				dreverse[next] = cost;
				pq.push({ -cost,next });
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		int time = dist[i] + dreverse[i];
		if (time > max) max = time;
	}
	cout << max;
}
