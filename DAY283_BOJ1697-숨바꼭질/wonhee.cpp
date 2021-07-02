#include<iostream>
#include<queue>
using namespace std;
int N, K;
bool visit[200001] = { 0 };

bool isRange(int x)
{
	if (x < 0 || x>200000)
		return false;
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int count = q.front().second;
		if (x == K)
		{
			cout << count;
			break;
		}
		q.pop();

		if (isRange(x + 1) && !visit[x + 1])
		{
			visit[x + 1] = 1;
			q.push({ x + 1,count + 1 });
		}
		if (isRange(x - 1) && !visit[x - 1])
		{
			visit[x - 1] = 1;
			q.push({ x - 1,count + 1 });
		}
		if (isRange(x * 2) && !visit[x * 2])
		{
			visit[x * 2] = 1;
			q.push({ x * 2,count + 1 });
		}
	}

	return 0;
}