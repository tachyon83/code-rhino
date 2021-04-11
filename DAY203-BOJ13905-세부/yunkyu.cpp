#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, pair<int, int>> pipii;
int parent[100001];
vector<pair<int, int>> graph[100001];

int BFS(int start, int end, int n) {
	vector<bool> visited(n + 1, false);
	queue<pair<int, int>> q;
	int i;
	visited[start] = true;
	q.push({ start , INF });

	while (!q.empty()) {
		int curr = q.front().first;
		int possible = q.front().second;
		q.pop();
		
		if (curr == end) return possible;

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int limit = graph[curr][i].second;
			if (!visited[next]) {
				visited[next] = true;
				q.push({next,min(possible,limit)});
			}
		}
	}
}

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	parent[b] = a;
	return true;
}
int main() {
	int n, m, s, e;
	priority_queue<pipii, vector<pipii>, less<pipii>> pq;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &e);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int h1, h2, k;
		scanf("%d %d %d", &h1, &h2, &k);
		pq.push({ k,{h1,h2} });
	}

	while (!pq.empty()) {
		int limit = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();

		if (Union(u, v)) {
			graph[u].push_back({ v,limit });
			graph[v].push_back({ u,limit });
		}
	}

	if (find(s) != find(e)) {
		printf("0");
		return 0;
	}

	printf("%d",BFS(s,e,n));
	return 0;
}
