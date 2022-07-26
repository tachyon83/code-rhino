#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long
#define MOD 1000000007

int N;
int A[100101];
vector<int> g[100101];
ll dp[100101][10];

void DFS(int n, int prev)
{
	for(int next : g[n])
	{
		if (next == prev) continue;
		DFS(next, n);
		for(int x=0; x<=9; x++)
		{
			dp[n][x] += dp[next][x]; 
			if (x <= A[next])
			{
				dp[n][x] += dp[next][A[next]]; 
				dp[n][x]++; 
			}
			dp[n][x] %= MOD;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> A[i];
	for(int i=0; i<N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	DFS(1, 0);
	ll res = dp[1][0] + dp[1][A[1]] + 1;
	res %= MOD; res += MOD; res %= MOD;
	cout << res << "\n";
	return 0;
}
