#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pair<int, int>> graph[50001];

int dijkstra(int start, int n) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n + 1, INF);
	int i;
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d > dist[curr]) continue; // 더 작은 경로가 이미 있다면 스킵

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int cost = d + graph[curr][i].second;
			if (cost < dist[next]) { // 비용이 더 작다면 갱신
				dist[next] = cost;
				pq.push({ cost,next });
			}
		}
	}

	return dist[n];
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	printf("%d", dijkstra(1, n));
	return 0;
}
