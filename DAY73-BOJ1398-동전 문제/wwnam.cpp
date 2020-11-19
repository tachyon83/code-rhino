#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int T;
	vector<int> dp(101, 0);
	for (int i = 1; i < 100; i++) {
		dp[i] = i;
		if (i >= 10)
			dp[i] = min(dp[i], dp[i - 10] + 1);
		if (i >= 25)
			dp[i] = min(dp[i], dp[i - 25] + 1);
	}

	cin >> T;
	while (T--) {
		long long N, tmp, ans = 0;
		cin >> N;
		tmp = N;
		while (tmp > 0) {
			ans += dp[tmp % 100];
			tmp /= 100;
		}
		cout << ans << '\n';
	}
}