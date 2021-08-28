#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int mod = 1000000000;
long long dp[101][10][1 << 10]; //[i][j][k] i => 자리수 j => 0~9 숫자 k => 0~9나온 수를 비트로 체크


int main() {
	int n, i, j, k;
	scanf("%d", &n);

	for (i = 1; i <= 9; i++) { // 0으로 시작 할수 없으므로 제외
		dp[1][i][1 << i] = 1; 

	}

	for (i = 2; i <= n; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 1023; k++) {
				if (j == 0) { // 0일 경우 이전의 자리수는 +1인 수만 가능
					dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % mod;
				}
				else if (j == 9) { // 9일 경우 이전의 자리수는 -1인수만 가능
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % mod;
				}
				else { // 이전의 자리수는 현재수의 +1 ,-1인 수
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k] % mod;
				}
			}

		}
	}

	long long ans = 0;

	for (i = 0; i <= 9; i++) {
		ans += dp[n][i][1023];
	}

	printf("%lld", ans % mod);

	return 0;

}
