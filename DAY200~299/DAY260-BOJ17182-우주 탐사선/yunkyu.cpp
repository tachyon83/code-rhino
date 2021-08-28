#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;
int cost[10][10];
int ans = 987654321;

void DFS(int curr, int visit, int dist) {
	if (visit == (1 << N) - 1) { // 모두 방문했다면 답을 구한다
		ans = min(ans, dist);
		return;
	}

	int i;

	for (i = 0; i < N; i++) {
		if ((visit & (1 << i)) == 0) { // 방문하지 않은 행성이라면
			visit |= (1 << i); 
			DFS(i, visit, dist + cost[curr][i]);
			visit &= ~(1 << i);
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	// 플로이드 와샬 모든 행성 사이의 최단거리 구함
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (cost[j][i] + cost[i][k] < cost[j][k])
					cost[j][k] = cost[j][i] + cost[i][k];
			}
		}
	}

	DFS(K, 1 << K, 0);
	printf("%d", ans);

	return 0;

}
