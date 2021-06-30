#include <iostream>
#include<algorithm>
using namespace std;
int dp[1001][1001] = { 0 };
string s[1001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++)
		dp[0][i] = s[0][i] - '0';
	for (int i = 0; i < m; i++)
		dp[i][0] = s[i][0] - '0';

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (s[i][j] == '1')
			{
				if (s[i - 1][j] == '1' && s[i - 1][j - 1] == '1' && s[i][j - 1] == '1')
					dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
				else
					dp[i][j] = 1;
			}
			else
				dp[i][j] = 0;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret = max(ret, dp[i][j]);
	cout << ret * ret;
	return 0;
}