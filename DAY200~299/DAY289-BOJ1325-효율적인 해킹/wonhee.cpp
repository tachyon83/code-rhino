#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int bfs(int x, bool c[10001], vector<int> v[10001])
{
	c[x] = 1;
	queue<int> q;
	q.push(x);
	int answer = -1;
	while (!q.empty())
	{
		int y = q.front();
		q.pop();
		answer += 1;
		int size = v[y].size();
		for (int i = 0; i < size; i++)
		{
			int z = v[y][i];
			if (!c[z])
			{
				c[z] = 1;
				q.push(z);
			}
		}
	}
	return answer;
}


vector<int> solution(int N, int M, vector<int> v[10001])
{
	bool c[10001] = { 0 };
	vector<int> answer;
	int maxNum = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(c, 0, sizeof(c));
		int num = bfs(i, c, v);
		if (num > maxNum)
		{
			answer.clear();
			answer.push_back(i);
			maxNum = num;
		}
		else if (num == maxNum)
			answer.push_back(i);
	}

	sort(answer.begin(), answer.end());
	return answer;
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M; cin >> N >> M;
	vector<int> v[10001];
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}

	vector<int> ve=solution(N, M, v);
	for (int i = 0; i < ve.size(); i++)
	{
		cout << ve[i] << ' ';
	}
	return 0;
}