#include <iostream>
using namespace std;
long long dp[201][201] = { 0 };

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    
    for (int i = 1; i < k; i++)
        for (int j = 0; j <= n; j++)
            for (int l = 0; l <= j; l++)
                dp[i][j] = (dp[i][j] + dp[i - 1][l]) % 1000000000;

    cout << dp[k - 1][n] << '\n';
    return 0;
}