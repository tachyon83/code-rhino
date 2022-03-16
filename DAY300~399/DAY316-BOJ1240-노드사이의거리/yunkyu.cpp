#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

vector<pair<int, int>> tree[1001];
bool visited[1001];

void BFS(int start,int end) {
	queue<pair<int, int>> q;
	int i;
	visited[start] = true;
	q.push({ start,0 });

	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (curr == end) { // 목적지에 도달했다면 종료
			printf("%d\n", dist);
			return;
		}
		
		for (auto node : tree[curr]) { // 갈수 있는 노드에 대해
			int next = node.first;
			int cost = node.second;
			if (!visited[next]) { // 방문하지 않았다면
				visited[next] = true;
				q.push({ next,dist + cost }); // 현재까지 거리에 비용을 더함
			}
		}
	}
}

int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n - 1; i++) {
		int a, b, dist;
		scanf("%d %d %d", &a, &b, &dist);
		// 노드 연결
		tree[a].push_back({ b,dist });
		tree[b].push_back({ a,dist });
	}

	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		BFS(a, b);
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
