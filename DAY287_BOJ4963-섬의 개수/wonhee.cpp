#include<iostream>
#include<queue>
using namespace std;
int w, h;
bool land[51][51];
int Move[8][2] = {
	{-1,-1},{-1,0},{-1,1},
	{0,-1},{0,1},
	{1,-1},{1,0},{1,1}
};

bool isRange(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return false;
	return true;
}

void bfs(int i, int j)
{
	land[i][j] = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + Move[i][0];
			int nx = x + Move[i][1];
			if (isRange(ny, nx) && land[ny][nx])
			{
				land[ny][nx] = 0;
				q.push({ ny,nx });
			}
		}
	}

}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> w >> h;
	while (w != 0 && h != 0)
	{
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> land[i][j];
		int cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (land[i][j])
				{
					bfs(i, j);
					++cnt;
				}
		cout << cnt << '\n';
		cin >> w >> h;
	}
	return 0;
}