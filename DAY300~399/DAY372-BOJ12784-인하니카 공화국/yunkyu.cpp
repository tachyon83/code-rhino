#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

vector<pair<int,int>> tree[1001];
int dp[1001];
bool visited[1001];

int dfs(int curr) {
	visited[curr] = true;

	if (tree[curr].size() == 1 && curr != 1) { // 리프 노드일 경우
		return 21; // 다이너마이트 최대 개수보다 큰 값 반환
	}

	for (int i = 0; i < tree[curr].size(); i++) {
		int child = tree[curr][i].first;
		int cost = tree[curr][i].second;
		// 방문하지 않은 child중
		if (!visited[child])
			// 현재 다리를 폭파시키는것과 child의 자식 노드로 연결된 다리를 폭파시키는 것 중 최소값을 취함 
			dp[curr] += min(dfs(child), cost);
	}

	return dp[curr];
}

int main() {
	int T, N, M;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			scanf("%d %d %d", &a, &b, &cost);
			// 트리 연결
			tree[a].push_back({ b,cost });
			tree[b].push_back({ a,cost });
		}

		printf("%d\n" ,dfs(1));
		for (int i = 1; i <= N; i++) {
			tree[i].clear();
		}
		// 초기화
		memset(dp, 0, sizeof(dp));
		memset(visited, false, sizeof(visited));
	}


	return 0;
