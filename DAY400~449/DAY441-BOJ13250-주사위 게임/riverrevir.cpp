#include <bits/stdc++.h>
using namespace std;
int n;
double dp[1000001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += (dp[i - j] + 1) * (1.0 / 6.0);
            }
            else {
                dp[i] += 1.0 / 6.0;
            }
        }
    }
    cout << fixed;
    cout.precision(12);
    cout << dp[n];
}
