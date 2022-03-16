#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v;
int dp[501][501];

int dfs(int i, int j)
{
	int& ret = dp[i][j];

	if (i == j)
		return 0;
	if (ret != -1)
		return ret;

	int subSum = 0;
	for (int k = i; k <= j; k++)
		subSum += v[k];

	for (int k = i; k < j; k++)
	{
		int sum = dfs(i, k) + dfs(k+1, j) + subSum;
		if (ret == -1 || ret > sum)
			ret = sum;
	}
	return ret;
}


int main()
{
	cin.tie(0);	cout.tie(0);
	cin.sync_with_stdio(0);

	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		int K; cin >> K;
		for (int i = 0; i < K; i++)
		{
			int num; cin >> num;
			v.push_back(num);
		}
		memset(dp, -1, sizeof(dp));
		cout << dfs(0, K-1) << '\n';
		v.clear();
	}
	return 0;
}
