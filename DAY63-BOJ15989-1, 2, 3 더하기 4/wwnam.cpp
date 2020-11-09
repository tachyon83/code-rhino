#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	vector<int> arr;
	vector<vector<int> > dp;
	int N, maxVal = 0;

	cin >> N;
	arr.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		maxVal = max(maxVal, arr[i]);
	}
	dp.resize(maxVal + 1, vector<int>(4, 0));

	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= maxVal; i++) {
		dp[i][1] = 1;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	for (int i = 1; i <= N; i++) {
		int ans = 0;
		for (int j = 1; j <= 3; j++) {
			ans += dp[arr[i]][j];
		}
		cout << ans << '\n';
	}
}