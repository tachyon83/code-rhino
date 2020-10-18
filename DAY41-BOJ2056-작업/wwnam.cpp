#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int N, ans = 0;
	vector<vector<int> > adj;
	vector<int> ind, arr, dp;
	queue<int> q;

	cin >> N;

	adj.resize(N + 1);
	ind.resize(N + 1, 0);
	arr.resize(N + 1, 0);
	dp.resize(N + 1, 0);

	int K, X, needs;
	for (int i = 1; i <= N; i++)
	{
		cin >> K >> X;
		arr[i] = K;
		for (int j = 0; j < X; j++)
		{
			cin >> needs;
			adj[needs].push_back(i);
			ind[i]++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (!ind[i])
		{
			q.push(i);
			dp[i] = arr[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int size = adj[cur].size(), next;
		for (int i = 0; i < size; i++)
		{
			next = adj[cur][i];
			dp[next] = max(dp[next], dp[cur] + arr[next]);
			if (--ind[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}