#include <stdio.h>

#define MAX(A,B) (A > B) ? A : B 

int forest[500][500];
int dp[500][500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int N;

int dfs(int i, int j) {
	register int a;
	int ni, nj, temp = 0;

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	dp[i][j] = 1;

	for (a = 0; a < 4; a++) {
		ni = i + dx[a];
		nj = j + dy[a];

		if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
			continue;
		}

		if (forest[i][j] >= forest[ni][nj]) {
			continue;
		}

		temp = MAX(temp, dfs(ni, nj));
	}
	dp[i][j] += temp;

	return dp[i][j];
}

int main() {

	register int i, j;
	int answer = 0;
	
	//freopen("input.txt", "r", stdin);

	scanf("%d ", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d ", &forest[i][j]);
			dp[i][j] = -1;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			answer = MAX(answer, dfs(i, j));
		}
	}

	printf("%d\n", answer);

	return 0;
}
