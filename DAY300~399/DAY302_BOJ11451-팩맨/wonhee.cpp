#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
string direction = "NSWE";
int N, M;
string s[51];
bool check[51][51][51][51];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

pair<int, string> bfs(int a, int b, int c, int d)
{
	queue < pair<pair<pair<int, int>, pair<int, int>>, pair<int, string>>> q;
	check[a][b][c][d] = 1;
	q.push({ {{a,b},{c,d}},{0,""} });

	while (!q.empty())
	{
		pair<int, int> first = q.front().first.first;
		pair<int, int> second = q.front().first.second;
		int cnt = q.front().second.first;
		string str = q.front().second.second;
		q.pop();
		if (first == second)
			return { cnt,str };

		for (int i = 0; i < 4; i++)
		{
			int t1 = first.first + m[i][0];
			int t2 = first.second + m[i][1];
			int t3 = second.first + m[i][0];
			int t4 = second.second + m[i][1];
			if (!isRange(t1, t2))
				t1 = (t1 + N) % N; t2 = (t2 + M) % M;
			if (!isRange(t3, t4))
				t3 = (t3 + N) % N; t4 = (t4 + M) % M;

			if (s[t1][t2] == 'G' || s[t3][t4] == 'G')
				continue;
			if (s[t1][t2] == 'X')
				t1 -= m[i][0]; t2 -= m[i][1];
			if (s[t3][t4] == 'X')
				t3 -= m[i][0]; t4 -= m[i][1];
			if (!isRange(t1, t2))
				t1 = (t1 + N) % N; t2 = (t2 + M) % M;
			if (!isRange(t3, t4))
				t3 = (t3 + N) % N; t4 = (t4 + M) % M;

			if (!check[t1][t2][t3][t4])
			{
				check[t1][t2][t3][t4] = 1;
				q.push({ { {t1,t2},{t3,t4} },{cnt + 1,str + direction[i]} });
			}
		}
	}
	return { -1,"" };
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<pair<int, int>> v;
		memset(check, 0, sizeof(check));
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> s[i];
			for (int j = 0; j < M; j++)
				if (s[i][j] == 'P')
					v.push_back({ i,j });
		}

		pair<int, string> ret = bfs(v[0].first, v[0].second, v[1].first, v[1].second);
		if (ret.first == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << ret.first << ' ' << ret.second << '\n';

	}
	return 0;
}