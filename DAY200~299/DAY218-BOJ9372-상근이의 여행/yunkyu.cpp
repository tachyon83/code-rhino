#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int find(int x) { 
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	parent[v] = u;

	return true;
}

int main() {
	int t, n, m, i;
	scanf("%d", &t);
	while (t > 0) {
		vector<pair<int, int>> edge;
		int cnt = 0;
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++) parent[i] = i; // 노드의 부모노드 가리킴
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			edge.push_back({ a,b });
		}

		for (i = 0; i < edge.size(); i++) {
			// 유니온 파인드
			if (Union(edge[i].first, edge[i].second)) { // 각 비행 스케줄에 대해 같은 집합인지 조사하고 아니라면 합쳐주고 카운트 + 1
				cnt++;
			}
		}

		printf("%d\n", cnt);
		t--;
	}

	return 0;
}
