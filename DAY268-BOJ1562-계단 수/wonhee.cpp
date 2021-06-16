#include <iostream>
using namespace std;

#define MOD 1000000000
int dp[101][10][1 << 10] = { 0 };
int main() {
    cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

    int n; cin >> n;
    int full = (1 << 10);

    for (int j = 1; j <= 9; ++j)
        dp[1][j][1 << j] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < full; ++k) {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MOD;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MOD;
                else
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
            }
        }
    }

    int answer = 0;
    for (int j = 0; j <= 9; ++j)
        answer = (answer + dp[n][j][full-1]) % MOD;

    cout << answer;
    return 0;
}