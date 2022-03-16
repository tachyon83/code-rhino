#include<iostream>
using namespace std;
#define MAXNUM 10000000

int arr[1001][3], dp[1001][3];
int main()
{
	cin.tie(0);	cout.tie(0);
	cin.sync_with_stdio(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	
	int result = MAXNUM;
	for (int i = 0; i < 3; i++)
	{
		dp[0][0] = MAXNUM;
		dp[0][1] = MAXNUM;
		dp[0][2] = MAXNUM;

		dp[0][i] = arr[0][i];
		for (int j = 1; j < N; j++)
			for (int k = 0; k < 3; k++)
				dp[j][k] = min(dp[j - 1][(k + 1) % 3], dp[j - 1][(k + 2) % 3]) + arr[j][k];
		
		for (int j = 0; j < 3; j++)
			if (i != j)
				result = min(result, dp[N - 1][j]);
	}
	cout << result << '\n';
	return 0;
}
