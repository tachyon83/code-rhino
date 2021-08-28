
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree[100001];

int DFS(int curr, vector<int> &dp, vector<bool> &visited) {
	int i;
	visited[curr] = true;

	for (i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i];
		if (!visited[next]) { // 방문하지 않았다면
			dp[curr] += DFS(next, dp, visited); // child 노드의 수를 더해준다
		}
	}

	return dp[curr];
}

int main() {
	int N, R, Q, i;
	scanf("%d %d %d", &N, &R, &Q);

	vector<bool> visited(N + 1, false);
	vector<int> dp(N + 1, 1);

	for (i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(R, dp, visited); // dp에 현재 노드로부터 서브트리의 노드 갯수를 저장
	for (i = 0; i < Q; i++) {
		int node;
		scanf("%d", &node);
		printf("%d\n", dp[node]);
	}
	return 0;
}
