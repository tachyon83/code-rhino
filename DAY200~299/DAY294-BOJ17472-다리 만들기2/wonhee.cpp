#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool map[11][11];
int land[11][11] = { 0 };
int N, M;
vector<pair<pair<int, int>, int>> v[7];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void bfs(int y, int x, int num)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	land[y][x] = num;

	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = ny + d[i][0];
			int newX = nx + d[i][1];
			if (isRange(newY, newX) && land[newY][newX] == 0 && map[newY][newX] == 1)
			{
				land[newY][newX] = num;
				q.push({ newY,newX });
			}
			if (isRange(newY, newX) && map[newY][newX] == 0)
				v[num].push_back({ { ny,nx },i });
		}
	}
}
int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	return 0;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int land_num = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && land[i][j] == 0)
			{
				bfs(i, j, land_num);
				++land_num;
			}
		}

	int connect[7][7] = { 0 };
	for (int i = 1; i < land_num; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			int y = v[i][j].first.first;
			int x = v[i][j].first.second;
			int direct = v[i][j].second;
			int distance = 0;
			while (1)
			{
				y += d[direct][0];
				x += d[direct][1];
				if (!isRange(y, x) || land[y][x] == i)
					break;
				else if (land[y][x] == 0)
					++distance;
				else
				{
					if (distance > 1 && (connect[i][land[y][x]] == 0 || connect[i][land[y][x]] > distance))
						connect[i][land[y][x]] = distance;
					break;
				}
			}
		}
	}

	vector<pair<int, pair<int, int>>> dist;
	for (int i = 1; i < land_num - 1; i++)
		for (int j = i + 1; j < land_num; j++)
			if (connect[i][j] != 0)
				dist.push_back({ connect[i][j], {i,j} });

	sort(dist.begin(), dist.end());
	int parent[7];
	for (int i = 1; i < land_num; i++)
		parent[i] = i;
	int sum = 0;
	for (int i = 0; i < dist.size(); i++)
	{
		if (!findParent(parent, dist[i].second.first, dist[i].second.second))
		{
			unionParent(parent, dist[i].second.first, dist[i].second.second);
			sum += dist[i].first;
		}
	}

	bool isPossible = true;
	for (int i = 1; i < land_num; i++)
		parent[i] = parent[parent[i]];
	for (int i = 1; i < land_num - 1; i++)
		if (parent[i] != parent[i + 1])
			isPossible = false;

	if (!isPossible)
		cout << -1;
	else
		cout << sum;

	return 0;
}