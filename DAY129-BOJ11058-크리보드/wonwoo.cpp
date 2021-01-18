#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n;
    vector<long long> dp;

    cin >> n;
    dp.resize(n + 1, 0);
    for (int i = 0; i <= 6; i++) {
        dp[i] = i;
    }
    for (int i = 7; i <= n; i++) {
        for (int j = 3; j <= i - 1; j++) {
            long long cur = dp[i - j] * (j - 1);
            if (cur > dp[i]) {
                dp[i] = cur;
            }
        }
    }
    cout << dp[n] << '\n';
}