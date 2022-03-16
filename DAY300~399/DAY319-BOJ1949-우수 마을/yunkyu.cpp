#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int num[10001];
bool visited[10001];
vector<int> tree[10001];
int dp[10001][2];

void solve(int curr) {
	visited[curr] = true;

	dp[curr][0] = 0; // 일반 마을일때
	dp[curr][1] = num[curr]; // 우수 마을로 선정할때

	for (int i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i];
		if (!visited[next]) { // 방문하지 않았다면
			solve(next);
			dp[curr][0] += max(dp[next][0], dp[next][1]); // 일반 마을이면 인접마을이 일반마을,우수마을중 하나임
			dp[curr][1] += dp[next][0]; // 우수마을이면 인접마을은 우수마을일수 없다
		}
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));

	solve(1);

	printf("%d", max(dp[1][0], dp[1][1])); // 1번 마을이 우수마을일때와 일반마을일때중 큰것이 정답

	return 0;
}
