#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int curr ,vector<vector<int>> &tree, vector<bool> &visited) {
	int i;
	// 방문 하지 않은 노드들을 차례대로 탐색
	visited[curr] = true;
	for (i = 0; i < tree[curr].size(); i++) { 
		int next = tree[curr][i];
		if (!visited[next])
			dfs(next, tree, visited);
	}
}

int main() {
	int T, n, m, i;
	scanf("%d", &T);
	while (T > 0) {
		scanf("%d", &n);
		vector<vector<int>> tree(n + 1);
		vector<bool> visited(n + 1);
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		int cnt = 0;
		for (i = 1; i <= n; i++) {
			if (!visited[i]) { // 방문하지 않은 노드일때 탐색
				dfs(i, tree, visited);
				cnt++; // 탐색 한번에 끝난다면 모든 노드가 이어져있음
			}
		}
		if (m == n - 1 && cnt == 1) { // 사이클이 생기지 않으려면 n개의 노드보다 1개 적은 엣지를 가져야함
			printf("tree\n");
		}
		else {
			printf("graph\n");
		}
		T--;
	}
	return 0;
}
