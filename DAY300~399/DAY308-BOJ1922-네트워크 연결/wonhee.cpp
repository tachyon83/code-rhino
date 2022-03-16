#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<pair<int, int>> v[1001];
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		if (a == b)
			continue;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}
	
	int answer = 0;
	bool c[1001] = { 0 };
	priority_queue <pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
	for (int i = 0; i < v[1].size(); i++)
		pq.push(v[1][i]);
	
	c[1] = 1;
	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		if (c[p.second] == 1)
			continue;
		c[p.second] = 1;
		answer += p.first;
		for (int i = 0; i < v[p.second].size(); i++)
			pq.push(v[p.second][i]);
	}
	cout << answer << '\n';
	return 0;
}