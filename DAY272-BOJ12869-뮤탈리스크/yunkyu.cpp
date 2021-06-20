#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int scv[3];
int dp[61][61][61];

int func(int a, int b, int c) {
	// 음수가 되는 값이 있을 경우 0 으로
	if (a < 0) return func(0, b, c);
	if (b < 0) return func(a, 0, c);
	if (c < 0) return func(a, b, 0);

	if (a == 0 && b == 0 && c == 0) { // 모든 scv를 파괴했을때
		return 0;
	}

	int& ret = dp[a][b][c];
	if (ret != -1) return ret;

	// 모든 scv 공격 순서중 가장 작은값을 취한다
	ret = func(a - 9, b - 3, c - 1) + 1;
	ret = min(ret, func(a - 9, b - 1, c - 3) + 1);
	ret = min(ret, func(a - 3, b - 9, c - 1) + 1);
	ret = min(ret, func(a - 3, b - 1, c - 9) + 1);
	ret = min(ret, func(a - 1, b - 3, c - 9) + 1);
	ret = min(ret, func(a - 1, b - 9, c - 3) + 1);

	return ret;
}

int main() {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &scv[i]);

	memset(dp, -1, sizeof(dp));

	printf("%d", func(scv[0], scv[1], scv[2]));
	return 0;
}
