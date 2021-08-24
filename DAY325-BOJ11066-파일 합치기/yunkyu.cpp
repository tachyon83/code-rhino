#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <memory.h>
using namespace std;

int files[501];
int sum[501];
int dp[501][501];

int solve(int left, int right) {
	int& ret = dp[left][right];
	if (ret != -1)
		return ret;

	if (left == right) { 
		return ret = 0;
	}

	ret = INT_MAX;
	for (int i = left; i < right; i++) {
		ret = min(ret, solve(left, i) + solve(i + 1, right)); // left~right 의 부분집합중 가장 작은값을 취함
	}

	return ret += sum[right] - sum[left - 1]; // left ~ right 까지의 파일의 양을 더한다
}

int main() {
	int T, k, i;
	scanf("%d", &T);
	while (T > 0) {
		scanf("%d", &k);
		for (i = 1; i <= k; i++) {
			scanf("%d", &files[i]);
			sum[i] = sum[i - 1] + files[i]; // 파일양의 누적합
		}
		memset(dp, -1, sizeof(dp)); // 배열 초기화
		printf("%d\n", solve(1, k));
		T--;
	}
	return 0;
}
