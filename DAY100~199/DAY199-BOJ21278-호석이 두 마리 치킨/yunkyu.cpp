#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
int graph[101][101];
int chicken[2];
int ans = INF;

void getTime(int a, int b, int N) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += min(graph[i][a], graph[i][b]) * 2; // 더 가까운 치킨집에 대한 왕복거리
	}

	if (sum < ans) {
		ans = sum;
		chicken[0] = a;
		chicken[1] = b;
	}
}

void floyd(int N) {
	int i, j, k;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}

void init(int N) {
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j)continue;
			graph[i][j] = INF;
		}
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	init(N);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	floyd(N); // 모든 정점에서 모든 정점으로의 거리 

	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			getTime(i, j, N); // 두가지 치킨집을 고르는 경우들에 대해 최단 왕복시간의 합을 구한다
		}
	}

	printf("%d %d %d", chicken[0], chicken[1], ans);
	return 0;
}
