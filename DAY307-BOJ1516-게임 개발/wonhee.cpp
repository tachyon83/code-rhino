#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> v[501];
	int cnt[501] = { 0 };
	int time[501];
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> time[i];
		int prev;
		while (1)
		{
			cin >> prev;
			if (prev == -1)
				break;
			v[prev-1].push_back(i);
			cnt[i]++;
		}
	}

	int answer[501] = { 0 };
	vector<int> q;
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0)
		{
			q.push_back(i);
			answer[i] = time[i];
		}
	}

	while (!q.empty())
	{
		int x = q[0];
		q.erase(q.begin());
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			answer[y] = max(answer[y], answer[x] + time[y]);
			cnt[y]--;
			if (cnt[y] == 0)
				q.push_back(y);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << '\n';
	}

	return 0;
}