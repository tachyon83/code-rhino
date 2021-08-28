#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[100001];
long long dp[100001][2];

void DFS(int curr, vector<bool> &visited, int length) {
	visited[curr] = true;
	int i;

	if (length % 2 == 0)
		dp[curr][0] = 1;
	else
		dp[curr][1] = 1;

	for (i = 0; i < tree[curr].size(); i++) {
		int child = tree[curr][i];
		if (!visited[child]) {
			DFS(child, visited, length + 1);
			dp[curr][0] += dp[child][0];
			dp[curr][1] += dp[child][1];
		}
	}
}

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	vector<bool> visited(N + 1, false);

	for (i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(1, visited , 0);

	for (i = 0; i < M; i++) {
		int u, v, c;
		long long cnt = 0;
		scanf("%d %d %d", &u, &v, &c);

		if (c == 0) {
			cnt += dp[v][1] * (dp[1][0] - dp[v][1]);
			cnt += dp[v][0] * (dp[1][1] - dp[v][0]);
		}
		else {
			cnt += dp[v][1] * (dp[1][1] - dp[v][0]);
			cnt += dp[v][0] * (dp[1][0] - dp[v][1]);
		}

		printf("%lld\n", cnt);
	}
	return 0;
}
