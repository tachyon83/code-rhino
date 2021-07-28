#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int V, E;
int visit[20001];

bool bfs(int start, vector<int> v[20001])
{
	visit[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		int size = v[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v[x][i];
			if (visit[y] == -1)
			{
				visit[y] = (visit[x] + 1) % 2;
				q.push(y);
			}
			else
			{
				if (visit[x] == visit[y])
					return false;
			}
		}
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int K; cin >> K;
	for (int a = 0; a < K; a++)
	{
		cin >> V >> E;
		memset(visit, -1, sizeof(visit));
		vector<int> v[20001];
		for (int i = 0; i < E; i++)
		{
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bool ret = 1;
		for (int i = 1; i <= V; i++)
		{
			if (visit[i] == -1 && !bfs(i, v))
			{
				ret = 0;
			}
		}
		if (ret)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}