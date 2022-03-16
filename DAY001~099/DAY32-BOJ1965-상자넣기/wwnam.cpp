#include <iostream>
using namespace std;
int main(void)
{
	int dp[1001], box[1001], n, max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> box[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (box[i] > box[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
		max = max < dp[i] ? dp[i] : max;
	cout << max;
}