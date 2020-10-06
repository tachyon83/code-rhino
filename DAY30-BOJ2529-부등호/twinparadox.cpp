// 코드리뷰는 언제나 환영합니다.
// 10844 - 쉬운 계단수 문제에 0~9 체크가 포함되는 문제입니다.
// 0~9 체크를 비트마스킹으로 진행하면 해결 가능합니다.
// 0보다 작거나, 9보다 큰 수가 들어갈 수 없기 때문에 그에 대한 경우만 예외적으로 처리하면 됩니다.
// 0123456789
// 0000000000
#include <iostream>
#include <vector>
using namespace std;
long long dp[101][10][1024] = { 0, }, ans = 0, MOD = 1e9;
int main(void)
{
	int N, all = 1023;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= all; k++)
			{
				if (j == 0)
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % MOD;
				else if (j == 9)
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % MOD;
				else
				{
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % MOD;
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % MOD;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i][all]) % MOD;
	cout << ans;
}