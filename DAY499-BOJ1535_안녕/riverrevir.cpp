#include <bits/stdc++.h>
using namespace std;
int hp[21];
int mp[21];
int dp[21][101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> hp[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> mp[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - hp[j] > 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - hp[i]] + mp[i-1]);
            }
        }
    }
    cout << dp[n][100];
    
}
