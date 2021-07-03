#include<iostream> 
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int m[8][2] = { {-1,-2} ,{1,-2}, {-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2} };
int N, M;
string s[51];
int visit[51][51];
int result[51][51] = { 0 };
int visit_cnt[51][51] = { 0 };
bool isRange(int y, int x)
{
	if (0 > y || y >= N || 0 > x || x >= M)
		return false;
	return true;
}

void bfs(int i, int j, int maal)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	visit[i][j] = 0;
	++visit_cnt[i][j];
	q.push({ { i,j },{1, 0} });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int num = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && visit[ny][nx] == -1)
			{
				++visit_cnt[ny][nx];
				if (cnt >= maal)
				{
					cnt = 0;
					++num;
				}
				visit[ny][nx] = num;
				q.push({ { ny,nx },{num,cnt + 1 } });
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> s[i];

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num = s[i][j] - '0';
			if (1 <= num && num <= 9)
			{
				++cnt;
				memset(visit, -1, sizeof(visit));
				bfs(i, j, num);
				for (int a = 0; a < N; a++)
					for (int b = 0; b < M; b++)
						result[a][b] += visit[a][b];
			}
		}
	}

	int ret = 100000;
	bool hasChanged = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (result[i][j] >= 0 && visit_cnt[i][j] == cnt)
			{
				ret = min(ret, result[i][j]);
				hasChanged = true;
			}
	if (!hasChanged)
		cout << -1;
	else
		cout << ret;
	return 0;
}