#include<iostream>
using namespace std;

long long dp[1000001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);


	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 1000001; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])% 1000000009;

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}