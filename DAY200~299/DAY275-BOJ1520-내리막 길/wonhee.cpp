#include<iostream>
#include<string.h>
using namespace std;
int M, N;
int dp[501][501] = { 0 };
int h[501][501];
int direction[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

bool isRange(int y, int x)
{
	if (y >= M || y < 0 || x >= N || x < 0)
		return false;
	return true;
}

int dfs(int y, int x)
{
	if (!isRange(y, x))
		return 0;

	int& ret = dp[y][x];
	if (ret != -1)
		return ret;
	if (y == M - 1 && x == N - 1)
		return ret = 1;

	ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + direction[i][0];
		int nx = x + direction[i][1];
		if (h[ny][nx] < h[y][x])
			ret += dfs(ny, nx);
	}

	return ret;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> h[i][j];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);

	return 0;
}