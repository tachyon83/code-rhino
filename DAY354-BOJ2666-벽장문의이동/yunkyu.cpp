#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

int m;
int seq[21];
int dp[21][21][21]; // 첫번째 => 현재 순서, (두번째,세번째) => 열린 벽장


int solve(int cnt, int first, int second) {
	if (cnt == m) return 0; // 모든 벽장을 사용
	int& ret = dp[cnt][first][second];
	if (ret != -1) return ret; // 이미 구한 값은 반환

	// 이전 벽장과 다음 벽장 사이의 거리가 움직여야하는 벽장의 수 => abs(prev-next)
	int a = solve(cnt + 1, seq[cnt], second) + abs(first - seq[cnt]); // 첫번째 벽장 대신 다음 벽장을 사용
	int b = solve(cnt + 1, first, seq[cnt]) + abs(second - seq[cnt]); // 두번째 벽장 대신 다음 벽장을 사용
	
	return ret = min(a,b); // 둘중 더 작은 값을 취한다.
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &seq[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d",solve(0, a, b));
	return 0;
}
