#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int d[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
string map[1001];
int N, M;
bool visit[1001][1001][2];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int bfs()
{
	visit[0][0][0] = 1;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{1,0} });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int W = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == M - 1)
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (isRange(ny, nx))
			{
				if (map[ny][nx] == '1' && W == 0)
				{
					visit[ny][nx][W + 1] = 1;
					q.push({ { ny,nx },{cnt + 1,W + 1} });
				}
				else if (map[ny][nx] == '0' && !visit[ny][nx][W])
				{
					visit[ny][nx][W] = 1;
					q.push({ { ny,nx }, { cnt + 1,W } });
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << bfs();
	return 0;
}