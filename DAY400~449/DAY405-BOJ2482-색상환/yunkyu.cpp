#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MOD 1000000003
using namespace std;

int dp[1001][1001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 0;
	}

	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			// i개의 색중 앞으로 j개를 고르는 경우 = 현재색 골랐을때 vs 안 고를때
			// 현재색 고를때 = 왼쪽 오른쪽 제외한것중 i - 2개중 j - 1개 
			// 고르지않을때 = 고르지 않은 색을 제외한 i - 1개중 j 개
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	printf("%d", dp[n][k] % MOD);
}
