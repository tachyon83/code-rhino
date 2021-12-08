#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define INF 987654321
using namespace std;

int n;
int w[10][10];
int dp[10][1 << 10]; // 비트마스크로 방문표시

int TSP(int curr, int visited) {
	if (visited == (1 << n) - 1) { // 모두 방문
		return w[curr][0] != 0 ? w[curr][0] : INF; // 갈수 없으면 INF값 반환
	}
	int& ret = dp[curr][visited];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i) || w[curr][i] == 0) continue; // 방문했거나 갈수 없다면
		ret = min(ret, TSP(i, visited | (1 << i)) + w[curr][i]); 
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	int result = TSP(0, 1);
	printf("%d", result);

	return 0;
}
