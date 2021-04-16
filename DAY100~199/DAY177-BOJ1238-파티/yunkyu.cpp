//파티
//https://www.acmicpc.net/problem/1238

#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, X;
vector<pair<int, int>> v[1001];
vector<pair<int, int>> v2[1001];
int ans[1001];

void dijkstra(int start,vector<pair<int,int>> graph[1001]) {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> dist(N + 1, INF);

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (dist[curr] < d) continue;

		for (int i = 0; i < graph[curr].size(); i++) {
			int cost = d + graph[curr][i].second;
			int next = graph[curr][i].first;

			if (cost < dist[next]) {
				dist[next] = cost;
				pq.push({ cost, next });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		ans[i] += dist[i];
	}

}
int main() {
	scanf("%d %d %d", &N, &M, &X);
	int i;

	for (i = 0; i < M; i++) {
		int start, end, time;
		scanf("%d %d %d", &start, &end, &time);
		v[start].push_back({ end,time });
		v2[end].push_back({ start,time });
	}

	dijkstra(X,v);
	dijkstra(X, v2);
	
	int max = 0;
	for (i = 1; i <= N; i++) {
		if (max < ans[i])
			max = ans[i];
	}

	printf("%d", max);

	return 0;
}
